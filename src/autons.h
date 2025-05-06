#pragma once
inline void blueGoalRush(){
	ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	reactiveClawClampOn = false;
	intake_state = 0;
	clawDoinker.toggle();
	chassis.setPose(54, -62, 280);
	ladybrownMotor.move(127);
	intake.move(127);
	chassis.moveToPoint(18, -52, 1500, { .minSpeed = 127, .earlyExitRange = 11 }); //rush mogo
	chassis.waitUntil(11.5);
	ladybrownMotor.brake();
	chassis.waitUntil(32);
	reactiveClawClampOn = true;
	chassis.waitUntilDone();
	chassis.tank(60,60);
	delay(100);
	chassis.tank(0,0);
	chassis.moveToPoint(36.5, -54, 2000, { .forwards = false });
	reactiveClawClampOn = false;
	chassis.waitUntilDone();
	claw.retract();
	delay(400);
	clawDoinker.retract();
	chassis.tank(-40, -40);
	delay(600);
	chassis.turnToHeading(160,600);
	chassis.waitUntilDone();
	chassis.moveToPoint(30,-38,1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 10});
	chassis.waitUntilDone();
	approachAndClampMogo(80);
	delay(150);
	intake_state = 1;
	delay(850);
	mogoclamp.toggle();
	delay(100);
	chassis.moveToPoint(30,-44,600);
	chassis.turnToHeading(47,900);
	chassis.waitUntilDone();
	chassis.moveToPoint(24,-50,800, {.forwards = false, .minSpeed = 80, .earlyExitRange = 8});
	chassis.waitUntilDone();
	approachAndClampMogo(80);
	delay(150);
	chassis.turnToPoint(60,-56,300);
	chassis.waitUntilDone();
	chassis.moveToPoint(60,-56,1000);
	chassis.waitUntilDone();
	chassis.moveToPoint(74, -74, 1200, {.minSpeed = 70, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
	chassis.tank(-100,-100);
	delay(400);	
	chassis.tank(0,0);
	chassis.turnToPoint(26,-60,600);
	chassis.waitUntilDone();
	chassis.moveToPoint(26,-60,1000);
	chassis.waitUntilDone();
	chassis.turnToHeading(207,300);
	chassis.waitUntilDone();
	chassis.tank(93,93);
	delay(359);
	chassis.tank(0,0);
}
inline void blueRingside(){
	chassis.setPose(60,12,145);
	//alliance
	ladybrownMotor.move(127);
	pros::delay(700);
	ladybrownMotor.move(-127);
	//move to clamp
  chassis.swingToHeading(95, lemlib::DriveSide::RIGHT, 400);
  chassis.waitUntilDone();
	chassis.moveToPoint(32, 18, 1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 10});
	chassis.waitUntil(5);
	ladybrownMotor.move(0); //sped lb
	chassis.waitUntilDone();
  approachAndClampMogo(80);
  delay(150);
	intake.move(127);
	intake_state = 1;
	chassis.turnToPoint(13,36,800);
	chassis.waitUntilDone();
	chassis.moveToPoint(13,36,1000, {.maxSpeed = 60, .minSpeed = 40, .earlyExitRange = 5});
	chassis.turnToPoint(13,62,1000, {.maxSpeed = 40, .minSpeed = 30, .earlyExitRange = 7});
	chassis.moveToPoint(13,62,1000, {.maxSpeed = 45});
	chassis.waitUntilDone();
	delay(500);
	lemlib::Pose temp = chassis.getPose();
	chassis.setPose(5,45,temp.theta);
	chassis.turnToPoint(27,39,600, {.minSpeed = 30, .earlyExitRange = 5});
	
	
	chassis.waitUntilDone();
	clawDoinker.toggle();
	chassis.moveToPoint(27,39,600, {.minSpeed = 90, .earlyExitRange = 5});
	
	intake.move(127);
	intake_state = 1;
	chassis.waitUntilDone();
	//corner
//   chassis.turnToPoint(-53,32, 1000);
//   chassis.waitUntilDone();
//   chassis.moveToPoint(-53,32,1000, {.minSpeed = 80, .earlyExitRange = 5});
//   chassis.waitUntilDone();
	

	// chassis.turnToPoint(-60, 72, 1000, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.turnToPoint(54,72,600);
	chassis.waitUntilDone();
	// chassis.waitUntilDone();
	// chassis.moveToPoint(-60, 72, 1000, {.maxSpeed = 30, .minSpeed = 10, .earlyExitRange = 8});
	// chassis.waitUntilDone();
	chassis.moveToPoint(54, 72, 800, {.minSpeed = 70, .earlyExitRange = 8});
	
	clawDoinker.toggle();
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
	chassis.tank(-100,-100);
	delay(400);
	chassis.moveToPoint(56, 72, 800, {.minSpeed = 70, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
	chassis.tank(-100,-100);
	delay(400);	
	chassis.moveToPoint(56, 72, 800, {.minSpeed = 70, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
  ringDoinker.toggle();
	chassis.tank(-100,-100);
	delay(400);
	temp = chassis.getPose();
	chassis.setPose(47,44,temp.theta);
	chassis.turnToPoint(48,-8,700);
	intakeRiser.toggle();
	chassis.waitUntilDone();
  ringDoinker.toggle();
	chassis.moveToPoint(47,6,1000, {.minSpeed = 126});
	chassis.waitUntilDone();
	intakeRiser.toggle();
}
inline void soloWinPointBlue(){
	chassis.setPose(60,12,145);
	//alliance
	ladybrownMotor.move(127);
	pros::delay(1000);
	ladybrownMotor.move(-127);
	//move to clamp
  chassis.swingToHeading(95, lemlib::DriveSide::RIGHT, 400);
  chassis.waitUntilDone();
	chassis.moveToPoint(32, 16, 1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 8});
	chassis.waitUntil(5);
	ladybrownMotor.move(0); //sped lb
	chassis.waitUntilDone();
  approachAndClampMogo();
	
	// //move to rings top
  delay(150);
	chassis.turnToPoint(26,32,600, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.waitUntilDone();
	chassis.moveToPoint(26,32,600, {.minSpeed = 100, .earlyExitRange = 5});
	intake.move(127);
	intake_state = 1;
	chassis.waitUntilDone();
	//corner
  chassis.turnToPoint(53,32, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(53,32,1000, {.minSpeed = 80, .earlyExitRange = 5});
  chassis.waitUntilDone();
	chassis.turnToPoint(64, 52, 1000, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.waitUntilDone();
	chassis.moveToPoint(64, 52, 1000, {.minSpeed = 100, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(200);
	chassis.tank(-100,-100);
	delay(400);
	chassis.tank(0,0);



  lemlib::Pose temp = chassis.getPose();
  chassis.setPose(48,44,temp.theta);
	chassis.turnToPoint(52,-50 , 800, {.minSpeed = 30, .earlyExitRange = 10});
	
	chassis.waitUntilDone();
	
	chassis.moveToPoint(52,-50,1000, {.maxSpeed = 70, .minSpeed = 50, .earlyExitRange = 5});
	chassis.waitUntil(18);
	intake_state = 0;
	intakeRiser.toggle();
	chassis.waitUntilDone();
  mogoclamp.toggle();
  delay(1000);
  
  chassis.turnToHeading(55,1000,  {.minSpeed = 30, .earlyExitRange = 10});
  intakeRiser.toggle();
  temp = chassis.getPose();
  chassis.setPose(45,-6,temp.theta);
  //chassis.turnToPoint(-30,-46,1000, {.minSpeed = 30, .earlyExitRange = 5});
  //chassis.waitUntilDone();
  //chassis.moveToPoint(-30,-46,1000, {.minSpeed = 80, .earlyExitRange = 5}); 
  chassis.waitUntilDone();
	// //move to mogo2
	//chassis.turnToPoint(-22,-31, 1000);
	//chassis.waitUntilDone();
	// intake.move(0);
	chassis.moveToPoint(29.5,-22.5,1200, {.forwards = false, .minSpeed = 80, .earlyExitRange = 5});
	chassis.waitUntilDone();
	approachAndClampMogo();
	chassis.turnToPoint(28,-44,1000);
	chassis.waitUntilDone();
	intake_state = 1;
	chassis.moveToPoint(28,-44,900);
	chassis.waitUntilDone();
	chassis.tank(-100,-100);
	delay(200);
	chassis.tank(0,0);
	chassis.turnToPoint(6,-12,600);
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
inline void redGoalRush(){
	ladybrownMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	reactiveClawClampOn = false;
	intake_state = 0;
	clawDoinker.toggle();
	chassis.setPose(-52, -32, 105);
	ladybrownMotor.move(127);
	intake.move(127);
	chassis.moveToPoint(-16, -42, 1500, { .minSpeed = 127, .earlyExitRange = 11 }); //rush mogo
	chassis.waitUntil(11);
	ladybrownMotor.brake();
	chassis.waitUntil(48);
	reactiveClawClampOn = true;
	chassis.waitUntilDone();
	chassis.tank(60,60);
	delay(100);
	chassis.tank(0,0);
	chassis.moveToPoint(-36, -40, 2000, { .forwards = false });
	reactiveClawClampOn = false;
	chassis.waitUntilDone();
	claw.retract();
	delay(400);
	clawDoinker.retract();
	chassis.tank(-40, -40);
	delay(600);
	chassis.turnToHeading(190,600);
	chassis.waitUntilDone();
	chassis.moveToPoint(-24,-26,1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 10});
	chassis.waitUntilDone();
	approachAndClampMogo(80);
	delay(150);
	intake_state = 1;
	delay(850);
	mogoclamp.toggle();
	delay(100);
	chassis.moveToPoint(-30,-34,600);
	chassis.turnToHeading(275,600);
	chassis.waitUntilDone();
	chassis.moveToPoint(-16,-35,800, {.forwards = false, .minSpeed = 80, .earlyExitRange = 8});
	chassis.waitUntilDone();
	approachAndClampMogo(80);
	delay(150);
	chassis.turnToPoint(-50,-56,300);
	chassis.waitUntilDone();
	chassis.moveToPoint(-50,-56,1000);
	chassis.waitUntilDone();
	chassis.moveToPoint(-62, -77, 1200, {.minSpeed = 70, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
	chassis.tank(-100,-100);
	delay(400);	
	chassis.tank(0,0);
	chassis.turnToPoint(-18,-52,600);
	chassis.waitUntilDone();
	chassis.moveToPoint(-18,-52,1000);
	chassis.waitUntilDone();
	chassis.turnToHeading(129,300);
	chassis.waitUntilDone();
	chassis.tank(92,92);
	delay(359);
	chassis.tank(0,0);
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
	chassis.moveToPoint(-32, 18.5, 1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 10});
	chassis.waitUntil(5);
	ladybrownMotor.move(0); //sped lb
	chassis.waitUntilDone();
  approachAndClampMogo(80);
  delay(150);
	intake.move(127);
	intake_state = 1;
	chassis.turnToPoint(-12.5,26,800);
	chassis.waitUntilDone();
	chassis.moveToPoint(-12.5,26,1000, {.maxSpeed = 60, .minSpeed = 40, .earlyExitRange = 5});
	chassis.turnToPoint(-11,62,1000, {.maxSpeed = 40, .minSpeed = 30, .earlyExitRange = 7});
	chassis.moveToPoint(-11,62,1000, {.maxSpeed = 45});
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
	chassis.turnToPoint(-54,72,600);
	chassis.waitUntilDone();
	// chassis.waitUntilDone();
	// chassis.moveToPoint(-60, 72, 1000, {.maxSpeed = 30, .minSpeed = 10, .earlyExitRange = 8});
	// chassis.waitUntilDone();
	chassis.moveToPoint(-54, 72, 800, {.minSpeed = 70, .earlyExitRange = 8});
	
	ringDoinker.toggle();
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
	chassis.tank(-100,-100);
	delay(400);
	chassis.moveToPoint(-56, 72, 800, {.minSpeed = 70, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
	chassis.tank(-100,-100);
	delay(400);	
	chassis.moveToPoint(-56, 72, 800, {.minSpeed = 70, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(400);
  clawDoinker.toggle();
	chassis.tank(-100,-100);
	delay(400);
	temp = chassis.getPose();
	chassis.setPose(-48,44,temp.theta);
	chassis.turnToPoint(-47,-8,700);
	intakeRiser.toggle();
	chassis.waitUntilDone();
  clawDoinker.toggle();
	chassis.moveToPoint(-47,6,1000, {.minSpeed = 126});
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
	pros::delay(800);
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
	delay(200);
  chassis.turnToPoint(-53,32, 1000);
  chassis.waitUntilDone();
  chassis.moveToPoint(-53.5,32.5,1000, {.minSpeed = 80, .earlyExitRange = 5});
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
	intake_state = 3;
	intakeRiser.toggle();
	chassis.waitUntilDone();
  mogoclamp.toggle();
  delay(1000);
  
  chassis.turnToHeading(305,1000,  {.minSpeed = 30, .earlyExitRange = 10});
  intake_state = 0;
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
	chassis.moveToPoint(-27.5,-23.5,1200, {.forwards = false, .minSpeed = 80, .earlyExitRange = 5});
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