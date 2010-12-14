# Project name. Should be the same as the project directory name and
# will become the name of the binary target.
SET( PROJECT_NAME "JoystickTester")

INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

QT4_WRAP_UI(UI_SOURCE
  MainUI.ui
)
QT4_WRAP_CPP(MOC_SOURCE
  MainUI.h
)

# Project source code list
SET( PROJECT_SOURCES
  # Add all the cpp source files here
  main.cpp
  MainUI.cpp
  ${MOC_SOURCE}
  ${UI_SOURCE}
)


# Project executable
ADD_EXECUTABLE(${PROJECT_NAME}
  ${PROJECT_SOURCES}
)

# Project dependencies
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
  # Core library dependencies
  OpenEngine_Core
  OpenEngine_Logging
  OpenEngine_Display
  OpenEngine_Devices
  OpenEngine_Scene
  # Extension dependencies
  Extensions_Qt
  Extensions_SetupHelpers  
)
