#ifndef _JOY_GUI_H_
#define _JOY_GUI_H_

#include <QtGui>
#include <Display/QtEnvironment.h>
#include <Devices/IJoystick.h>
#include <Core/IListener.h>
#include <vector>

namespace Ui { class MainUI; }

using namespace OpenEngine::Devices;
using namespace OpenEngine::Core;
using namespace std;

class MainUI : public QMainWindow, 
               public IListener<JoystickAxisEventArg>,
               public IListener<JoystickButtonEventArg> {
    Q_OBJECT;
    Ui::MainUI* ui;
    OpenEngine::Devices::IJoystick& joystick;
    vector<QSlider*> sliders;
    vector<QCheckBox*> checkboxes;
    
    void AddWidgetForJoystickInfo(JoystickInfo info);

public:
    MainUI(OpenEngine::Display::QtEnvironment& env);
    void Handle(JoystickAxisEventArg arg);
    void Handle(JoystickButtonEventArg arg);
};

#endif
