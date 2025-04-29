#pragma once
#include "devices.h"
#include "macros.h"
#include "tasks.h"
#include "globalStates.h"


inline void redSoloAWP(){
	chassis.setPose(-51.5,9,240);
	//alliance
	chassis.moveToPoint(-59,5,500);
	ladybrownMotor.move(127);
	pros::delay(1000);
	ladybrownMotor.move(-127);
	//move to clamp
	chassis.moveToPoint(-30, 20, 1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 5});
	chassis.waitUntil(5);
	ladybrownMotor.move(0); //sped lb
	chassis.waitUntilDone();
	chassis.tank(-90,-90);
	pros::delay(200);
	mogoclamp.toggle();
	chassis.tank(0,0);
	pros::delay(150);
	//move to rings top
	chassis.turnToHeading(10, 1000);
	chassis.waitUntilDone();
	chassis.moveToPoint(-23,48,1000, {.minSpeed = 100, .earlyExitRange = 5});
	intake.move(127);
	conveyor.move(127);
	chassis.waitUntilDone();
	chassis.tank(100,100);
	pros::delay(400);
	chassis.tank(0,0);
	//corner
	chassis.turnToHeading(290,1000);
	chassis.waitUntilDone();
	chassis.moveToPoint(-68, 66, 1000, {.minSpeed = 100, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	pros::delay(400);
	chassis.tank(-100,-100);
	pros::delay(400);
	chassis.tank(0,0);
	//move to middle rings
	chassis.swingToHeading(345, lemlib::DriveSide::LEFT, 1000, {.maxSpeed = 110, .minSpeed = 30, .earlyExitRange = 5});
	chassis.waitUntilDone();
	chassis.moveToPoint(-58.5,40,1000, {.minSpeed = 100, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.turnToHeading(160, 1000, {.maxSpeed = 110, .minSpeed = 30, .earlyExitRange = 10});
	chassis.waitUntilDone();
	chassis.moveToPoint(-35,-46,1000, {.maxSpeed = 110, .minSpeed = 80, .earlyExitRange = 5});
	chassis.waitUntilDone();
	mogoclamp.toggle();
	//move to bottom rings
	chassis.turnToHeading(90, 1000);
	chassis.waitUntilDone();
	intake.move(127);
	chassis.moveToPoint(-21,46,1000);
	chassis.waitUntilDone();
	//move to mogo2
	chassis.turnToHeading(175, 1000);
	chassis.waitUntilDone();
	intake.move(0);
	chassis.moveToPoint(-22,-31,1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 5});
	chassis.waitUntilDone();
	chassis.tank(-90,-90);
	pros::delay(200);
	chassis.tank(0,0);
	mogoclamp.toggle();
	//ladder
	
	chassis.turnToPoint(-8.5,-21,1000);
	chassis.waitUntilDone();
	chassis.moveToPoint(-8.5,-21,1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 5});
	chassis.waitUntil(5);
	ladybrownMotor.move(127);
	chassis.waitUntilDone();
	ladybrownMotor.move(0);
	intake.move(0);
	conveyor.move(0);


}

