// main
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

// OpenEngine stuff
//#include <Meta/Config.h>
#include <Logging/Logger.h>
#include <Logging/StreamLogger.h>
#include <Core/Engine.h>

#include <Devices/SDLJoystickOnly.h>

// SimpleSetup
#include <Utils/SimpleSetup.h>
#include <Display/QtEnvironment.h>
#include "MainUI.h"

// Game factory
//#include "GameFactory.h"

// name spaces that we will be using.
// this combined with the above imports is almost the same as
// fx. import OpenEngine.Logging.*; in Java.
using namespace OpenEngine::Logging;
using namespace OpenEngine::Core;
using namespace OpenEngine::Utils;
using namespace OpenEngine::Display;

#undef main

/**
 * Main method for the first quarter project of CGD.
 * Corresponds to the
 *   public static void main(String args[])
 * method in Java.
 */
int main(int argc, char** argv) {

    // Create simple setup
    QtEnvironment *env = new QtEnvironment(false);
    SimpleSetup* setup = new SimpleSetup("Example Project Title", env);
    
    

    MainUI* ui = new MainUI(*env);

    setup->GetEngine().Start();



    // Return when the engine stops.
    return EXIT_SUCCESS;
}


