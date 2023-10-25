/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lsikora25                                        */
/*    Created:      Thu Sep 07 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    4, 5, 7, 6      
// Motor20              motor         20              
// DigitalOutA          digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace vex;
competition Competition;
int Brain_precision = 0, Console_precision = 0, Controller1_precision = 0;
float myVariable;

void porsche() {
  Brain.Screen.setFont(mono15);
  Brain.Screen.newLine();
  Brain.Screen.print("              ____----------- _____");
  Brain.Screen.newLine();
  Brain.Screen.print("\\~~~~~~~~~~/~_--~~~------~~~~~     \\");
  Brain.Screen.newLine();
  Brain.Screen.print(" `---`\\  _-~      |                   \\");
  Brain.Screen.newLine();
  Brain.Screen.print("   _-~  <_         |                     \\[]");
  Brain.Screen.newLine();
  Brain.Screen.print(" / ___     ~~--[""] |      ________-------'_");
  Brain.Screen.newLine();
  Brain.Screen.print("> /~` \\    |-.   `\\~~.~~~~~                _ ~ - _");
  Brain.Screen.newLine();
  Brain.Screen.print(" ~|  ||\\%  |       |    ~  ._                ~ _   ~ ._");
  Brain.Screen.newLine();
  Brain.Screen.print("   `_//|_%  \\      |          ~  .              ~-_    /\\");
  Brain.Screen.newLine();
  Brain.Screen.print("          `--__     |    _-____  /\\               ~-_ \\/.");
  Brain.Screen.newLine();
  Brain.Screen.print("               ~--_ /  ,/ -~-_ \\ \\/          _______---~/ ");
  Brain.Screen.newLine();
  Brain.Screen.print("                   ~~-/._<   \\ \\`~~~~~~~~~~~~~     ##--~/");
  Brain.Screen.newLine();
  Brain.Screen.print("                         \\    ) |`------##---~~~~-~  ) )");
  Brain.Screen.newLine();
  Brain.Screen.print("                          ~-_/_/                  ");
}
//**********************************************************************************************

//AUTON CODE
int onauton_autonomous_0() { //left side
  Drivetrain.setDriveVelocity(80, percent);
  Drivetrain.setTurnVelocity(80, percent);
  Drivetrain.drive(forward);
  wait(2, seconds);
  Drivetrain.stop();
  return 0;
}

/*
int onauton_autonomous_0() { //right side
  Drivetrain.setDriveVelocity(80, percent);
  Drivetrain.setTurnVelocity(80, percent);
  return 0;
} */

//**********************************************************************************************

void onevent_Controller1ButtonA_pressed_0() {
  DigitalOutA.set(true);

}
void onevent_Controller1ButtonA_released_0() {

}


void onevent_Controller1ButtonB_pressed_0() {
  DigitalOutA.set(false);

}
void onevent_Controller1ButtonB_released_0() {

}

void onevent_Controller1ButtonX_pressed_0() {
  Motor20.setVelocity(80,percent);
  Motor20.spin(reverse);
  wait(1.3, seconds);
  Motor20.stop();
}
int ac = 0;
void onevent_Controller1ButtonY_pressed_0() {
  Motor20.setVelocity(80,percent);
  Motor20.spin(reverse);
}
void onevent_Controller1ButtonY_released_0() {
  Motor20.stop();
}

//**********************************************************************************************

//AUTONOMOUS SETUP
void VEXcode_auton_task() {
  // Start the auton control tasks....
  vex::task auto0(onauton_autonomous_0);
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  auto0.stop();
  return;
}

//DRIVER CONTROLLED
int ondriver_drivercontrol_0() {
  return 0;
}

//DRIVER CONTROL SETUP
void VEXcode_driver_task() {
  // Start the driver control tasks....
  vex::task drive0(ondriver_drivercontrol_0);

  task rc_auto_loop_task_Controller1();
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
  return;
}
//**********************************************************************************************

//MAIN
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vex::competition::bStopTasksBetweenModes = false;
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);
  vexcodeInit();

  porsche(); //console print

  //setting up speeds
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.setTurnVelocity(60, percent);

  //config motor position

  //register event handlers
  Controller1.ButtonA.pressed(onevent_Controller1ButtonA_pressed_0);
  Controller1.ButtonB.pressed(onevent_Controller1ButtonB_pressed_0);
  Controller1.ButtonX.pressed(onevent_Controller1ButtonX_pressed_0);
  Controller1.ButtonY.pressed(onevent_Controller1ButtonY_pressed_0);
  Controller1.ButtonY.released(onevent_Controller1ButtonY_released_0);
}
