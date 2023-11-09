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
// Drivetrain           drivetrain    4, 5, 6, 7      
// DigitalOutA          digital_out   A               
// Motor20              motor         20              
// Controller1          controller                    
// Motor19              motor         19              
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
int dFor = 400;
int dSide = 200;
//AUTON CODE
int onauton_autonomous_0() { //opposite side
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.setTurnVelocity(80, percent);

  Drivetrain.driveFor(forward, 1000, mm, true);
  wait(1, seconds);
  Drivetrain.turnFor(right, 40, degrees, true);
  wait(1, seconds);
  Drivetrain.driveFor(forward, 150, mm, true);
  wait(1, seconds);
  Drivetrain.driveFor(reverse, 300, mm, true);
  wait(1, seconds);
  return 0; 
}

/*
int onauton_autonomous_0() { //same side
   Drivetrain.setDriveVelocity(5, percent);
  Drivetrain.setTurnVelocity(80, percent);

  Drivetrain.driveFor(forward, 300, mm, true);
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.driveFor(reverse, 50, mm, true);
  DigitalOutA.set(true);
  Drivetrain.driveFor(reverse, 300, mm, true);
  wait(2, seconds);

  Drivetrain.turnFor(left, 20, degrees, true);
  wait(1, seconds); 
  Drivetrain.driveFor(forward, 800, mm, true);
  wait(1, seconds);
  Drivetrain.driveFor(forward, 200, mm, true);

  //BANG
  wait(1, seconds);
  Drivetrain.setDriveVelocity(70, percent);
  Drivetrain.driveFor(reverse, 800, mm, true);
  wait(1,seconds);
  Drivetrain.turnFor(left, 70, degrees, true); //left
  wait(1, seconds);
  Drivetrain.driveFor(forward, 10000, mm, true);
  DigitalOutA.set(false);
  return 0;
  }
  */


//**********************************************************************************************

void onevent_Controller1ButtonA_pressed_0() {
  DigitalOutA.set(true);
}

void onevent_Controller1ButtonB_pressed_0() {
  DigitalOutA.set(false);
}
void onevent_Controller1ButtonDown_pressed_0() {
  Motor19.setVelocity(100,percent);
  Motor19.spin(forward);
}
void onevent_Controller1ButtonDown_released_0() {
  Motor19.setVelocity(100, percent);
  Motor19.spin(reverse);
}


void onevent_Controller1ButtonY_pressed_0() {
  Motor20.setVelocity(80,percent);
  Motor20.spin(reverse);
}
void onevent_Controller1ButtonY_released_0() {
  Motor20.stop();
}

void onevent_Controller1ButtonUp_pressed_0() {
  Motor20.setVelocity(100,percent);
  Motor20.spin(forward);
}
void onevent_Controller1ButtonUp_released_0() {
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
void onevent_Controller1ButtonR2_pressed_0() {
  controller Controller1 = controller(primary);
  motor leftMotorA = motor(PORT4, ratio6_1, true);
  motor leftMotorB = motor(PORT5, ratio6_1, true);
  motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
  motor rightMotorA = motor(PORT7, ratio6_1, false);
  motor rightMotorB = motor(PORT6, ratio6_1, false);
  motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
  drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 0.5);
  motor Motor20 = motor(PORT20, ratio6_1, false);
  digital_out DigitalOutA = digital_out(Brain.ThreeWirePort.A);
}
void onevent_Controller1ButtonR1_pressed_0() {
  controller Controller1 = controller(primary);
  motor leftMotorA = motor(PORT4, ratio6_1, false);
  motor leftMotorB = motor(PORT5, ratio6_1, false);
  motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
  motor rightMotorA = motor(PORT7, ratio6_1, true);
  motor rightMotorB = motor(PORT6, ratio6_1, true);
  motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
  drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 0.5);
  motor Motor20 = motor(PORT20, ratio6_1, false);
  digital_out DigitalOutA = digital_out(Brain.ThreeWirePort.A);
}
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
  Controller1.ButtonY.pressed(onevent_Controller1ButtonY_pressed_0);
  Controller1.ButtonY.released(onevent_Controller1ButtonY_released_0);
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);
  Controller1.ButtonUp.pressed(onevent_Controller1ButtonUp_pressed_0);
  Controller1.ButtonUp.released(onevent_Controller1ButtonUp_released_0);
  Controller1.ButtonDown.pressed(onevent_Controller1ButtonDown_pressed_0);
  Controller1.ButtonDown.released(onevent_Controller1ButtonDown_released_0);
}
