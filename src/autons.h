#pragma once
inline void redGoalRush(){
	reactiveClawClampOn = true;
	clawDoinker.extend();
	chassis.setPose(-54, -32, 105);
	intake.move(127);
	chassis.moveToPoint(-18, -42, 1500, { .minSpeed = 127 }); //rush mogo
	chassis.moveToPoint(-34.407, -42.57, 2000, { .forwards = false });
	claw.extend();
	reactiveClawClampOn = false;
	chassis.waitUntilDone();
	claw.retract();
	delay(400);
	clawDoinker.retract();
	chassis.tank(-40, -40);
	delay(600);
	chassis.turnToHeading(180,1000);
	chassis.waitUntilDone();
	chassis.moveToPoint(-24,-30,1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 8});
	chassis.waitUntilDone();
	approachAndClampMogo();
	delay(150);
	intake_state = 1;
	chassis.moveToPoint(-24,-54,1000);
	chassis.waitUntilDone();
}
inline void redRingside(){
	chassis.setPose(-60,12,215);
	//alliance
	ladybrownMotor.move(127);
	pros::delay(700);
	ladybrownMotor.move(-127);
	//move to clamp
  chassis.swingToHeading(265, lemlib::DriveSide::LEFT, 400);
  chassis.waitUntilDone();
	chassis.moveToPoint(-32, 16, 1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 8});
	chassis.waitUntil(5);
	ladybrownMotor.move(0); //sped lb
	chassis.waitUntilDone();
  approachAndClampMogo();
  delay(150);
	intake.move(127);
	intake_state = 1;
	chassis.turnToPoint(-15,26,600);
	chassis.waitUntilDone();
	chassis.moveToPoint(-15,26,1000, {.maxSpeed = 60, .minSpeed = 40, .earlyExitRange = 5});
	chassis.turnToPoint(-13,48,1000, {.maxSpeed = 40, .minSpeed = 30, .earlyExitRange = 7});
	chassis.moveToPoint(-13,48,1000, {.maxSpeed = 40});
	chassis.waitUntilDone();
	delay(500);
	lemlib::Pose temp = chassis.getPose();
	chassis.setPose(-5,45,temp.theta);
	chassis.turnToPoint(-26,40,600, {.minSpeed = 30, .earlyExitRange = 5});
	
	
	chassis.waitUntilDone();
	ringDoinker.toggle();
	chassis.moveToPoint(-26,40,600, {.minSpeed = 90, .earlyExitRange = 5});
	
	intake.move(127);
	intake_state = 1;
	chassis.waitUntilDone();
	//corner
//   chassis.turnToPoint(-53,32, 1000);
//   chassis.waitUntilDone();
//   chassis.moveToPoint(-53,32,1000, {.minSpeed = 80, .earlyExitRange = 5});
//   chassis.waitUntilDone();
	

	// chassis.turnToPoint(-60, 72, 1000, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.turnToPoint(-60,77,600);
	chassis.waitUntilDone();
	// chassis.waitUntilDone();
	// chassis.moveToPoint(-60, 72, 1000, {.maxSpeed = 30, .minSpeed = 10, .earlyExitRange = 8});
	// chassis.waitUntilDone();
	chassis.moveToPoint(-60, 77, 1000, {.minSpeed = 70, .earlyExitRange = 8});
	
	ringDoinker.toggle();
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
	chassis.tank(-100,-100);
	delay(400);
	chassis.moveToPoint(-60, 77, 1000, {.minSpeed = 70, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
	chassis.tank(-100,-100);
	delay(400);	
	chassis.moveToPoint(-60, 77, 1000, {.minSpeed = 70, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
	chassis.tank(-100,-100);
	delay(400);
	temp = chassis.getPose();
	chassis.setPose(-48,44,temp.theta);
	chassis.turnToPoint(-53,-8,800);
	intakeRiser.toggle();
	chassis.waitUntilDone();
	chassis.moveToPoint(-53,-8,1000, {.minSpeed = 120});
	chassis.waitUntilDone();
	intakeRiser.toggle();
	// chassis.moveToPoint(-64, 77, 1000, {.minSpeed = 70, .earlyExitRange = 8});
	// chassis.waitUntilDone();
	// chassis.tank(100,100);
	// delay(400);
	// chassis.tank(-100,-100);
	// delay(400);
}

inline void soloWinPointRed() {
	chassis.setPose(-60,12,215);
	//alliance
	ladybrownMotor.move(127);
	pros::delay(1000);
	ladybrownMotor.move(-127);
	//move to clamp
  chassis.swingToHeading(265, lemlib::DriveSide::LEFT, 400);
  chassis.waitUntilDone();
	chassis.moveToPoint(-32, 16, 1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 8});
	chassis.waitUntil(5);
	ladybrownMotor.move(0); //sped lb
	chassis.waitUntilDone();
  approachAndClampMogo();
	
	// //move to rings top
  delay(150);
	chassis.turnToPoint(-26,32,600, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.waitUntilDone();
	chassis.moveToPoint(-26,32,600, {.minSpeed = 100, .earlyExitRange = 5});
	intake.move(127);
	intake_state = 1;
	chassis.waitUntilDone();
	//corner
  chassis.turnToPoint(-53,32, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(-53,32,1000, {.minSpeed = 80, .earlyExitRange = 5});
  chassis.waitUntilDone();
	chassis.turnToPoint(-64, 52, 1000, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.waitUntilDone();
	chassis.moveToPoint(-64, 52, 1000, {.minSpeed = 100, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(200);
	chassis.tank(-100,-100);
	delay(400);
	chassis.tank(0,0);



  lemlib::Pose temp = chassis.getPose();
  chassis.setPose(-48,44,temp.theta);
	chassis.turnToPoint(-52,-50 , 800, {.minSpeed = 30, .earlyExitRange = 10});
	
	chassis.waitUntilDone();
	
	chassis.moveToPoint(-52,-50,1000, {.maxSpeed = 70, .minSpeed = 50, .earlyExitRange = 5});
	chassis.waitUntil(18);
	intake_state = 0;
	intakeRiser.toggle();
	chassis.waitUntilDone();
  mogoclamp.toggle();
  delay(1500);
  
  chassis.turnToHeading(305,1000,  {.minSpeed = 30, .earlyExitRange = 10});
  intakeRiser.toggle();
  temp = chassis.getPose();
  chassis.setPose(-45,-6,temp.theta);
  //chassis.turnToPoint(-30,-46,1000, {.minSpeed = 30, .earlyExitRange = 5});
  //chassis.waitUntilDone();
  //chassis.moveToPoint(-30,-46,1000, {.minSpeed = 80, .earlyExitRange = 5}); 
  chassis.waitUntilDone();
	// //move to mogo2
	//chassis.turnToPoint(-22,-31, 1000);
	//chassis.waitUntilDone();
	// intake.move(0);
	chassis.moveToPoint(-30,-22,1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 5});
	chassis.waitUntilDone();
	approachAndClampMogo();
	chassis.turnToPoint(-28,-44,1000);
	chassis.waitUntilDone();
	intake_state = 1;
	chassis.moveToPoint(-28,-44,900);
	chassis.waitUntilDone();
	chassis.tank(-100,-100);
	delay(200);
	chassis.tank(0,0);
	chassis.turnToPoint(-6,-12,600);
	chassis.waitUntilDone();
	chassis.tank(100,100);
	ladybrownMotor.move(127);
	delay(500);
	ladybrownMotor.move(0);
	delay(150);
	chassis.tank(0,0);
	intake.move(0);
	intake_state = 0;
}
