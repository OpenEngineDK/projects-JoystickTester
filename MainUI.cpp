#include "MainUI.h"

#include "JoystickTester/ui_MainUI.h"
#include <Logging/Logger.h>

using namespace OpenEngine::Display;
using namespace OpenEngine::Devices;

MainUI::MainUI(QtEnvironment& env) : joystick(*(env.GetJoystick())) {
    ui = new Ui::MainUI();
    ui->setupUi(this);

    ui->firstLayout->addWidget(env.GetGLWidget());
    
    AddWidgetForJoystickInfo(joystick.GetJoystickInfo());

    joystick.JoystickAxisEvent().Attach(*this);
    joystick.JoystickButtonEvent().Attach(*this);

    show();
    raise();
}


void MainUI::AddWidgetForJoystickInfo(JoystickInfo info) {
    // name
    QLabel *label = new QLabel(QString::fromStdString(info.name));
    ui->rightLayout->addWidget(label);

    // axes
    for (int i=0;i<info.axes;i++) {
        QSlider* slider = new QSlider(Qt::Horizontal);
        slider->setMinimum(-32768);
        slider->setMaximum(32767);
        ui->rightLayout->addWidget(slider);
        sliders.push_back(slider);
    }

    // Buttons
    for (int i=0;i<info.buttons;i++) {
        QCheckBox *box = new QCheckBox();
        ui->rightLayout->addWidget(box);
        checkboxes.push_back(box);
    }
}

void MainUI::Handle(JoystickButtonEventArg arg) {
    
    int btnIdx = 0;
    for (int i=0;i<32;i++) {
        if (arg.button & (1 << i))
            btnIdx = i;
    }
    
    QCheckBox *box = checkboxes[btnIdx];
    if (!box) {
        logger.info << "CheckBox not found: " << btnIdx << logger.end;
        return;
    }
    box->setCheckState((arg.type==JoystickButtonEventArg::PRESS)
                       ? (Qt::Checked)
                       : (Qt::Unchecked));
    
}
void MainUI::Handle(JoystickAxisEventArg arg) {
    QSlider *slider = sliders[arg.axis];
    if (!slider) {
        logger.info << "Slider not found: " << arg.axis << logger.end;
        return;
    }
    //logger.info << arg.axis << " = " << arg.value << logger.end;
    slider->setValue(arg.value);

}
