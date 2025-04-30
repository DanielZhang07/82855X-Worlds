#pragma once

inline void redRingside(){
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
  delay(150);
	intake.move(127);
	intake_state = 1;
	chassis.turnToPoint(-15,26,1000);
	chassis.waitUntilDone();
	chassis.moveToPoint(-15,26,1000, {.maxSpeed = 60, .minSpeed = 40, .earlyExitRange = 5});
	chassis.turnToPoint(-15,48,1000, {.maxSpeed = 40, .minSpeed = 30, .earlyExitRange = 10});
	chassis.moveToPoint(-15,48,1000);
	chassis.waitUntilDone();
	delay(500);
	lemlib::Pose temp = chassis.getPose();
	chassis.setPose(-5,45,temp.theta);
	chassis.turnToPoint(-26,38,600, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.waitUntilDone();
	chassis.moveToPoint(-26,38,600, {.minSpeed = 100, .earlyExitRange = 5});
	intake.move(127);
	intake_state = 1;
	chassis.waitUntilDone();
	//corner
//   chassis.turnToPoint(-53,32, 1000);
//   chassis.waitUntilDone();
//   chassis.moveToPoint(-53,32,1000, {.minSpeed = 80, .earlyExitRange = 5});
//   chassis.waitUntilDone();
	chassis.turnToPoint(-64, 76, 1000, {.minSpeed = 30, .earlyExitRange = 5});
	chassis.waitUntilDone();
	chassis.moveToPoint(-64, 76, 1000, {.minSpeed = 100, .earlyExitRange = 8});
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(200);
	chassis.tank(-100,-100);
	delay(400);
	chassis.tank(0,0);


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
	chassis.waitUntilDone();
  mogoclamp.toggle();
  delay(1500);
  intake_state = 0;
  chassis.turnToHeading(290,1000,  {.minSpeed = 30, .earlyExitRange = 10});
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
	chassis.moveToPoint(-30,-20,1000, {.forwards = false, .minSpeed = 80, .earlyExitRange = 5});
	chassis.waitUntilDone();
	approachAndClampMogo();
	chassis.turnToPoint(-28,-40,600);
	chassis.waitUntilDone();
	intake_state = 1;
	chassis.moveToPoint(-28,-40,700);
	chassis.waitUntilDone();
	chassis.tank(-100,-100);
	delay(200);
	chassis.tank(0,0);
	chassis.turnToPoint(-14,-10,600);
	ladybrownMotor.move(127);
	chassis.waitUntil(160);
	ladybrownMotor.move(0);
	chassis.waitUntilDone();
	chassis.tank(100,100);
	delay(350);
	chassis.tank(0,0);
	intake.move(0);
	intake_state = 0;
}
// delrin 5 inches from wall
inline void blueMogoSideCenterRing() {
	chassis.setPose(58, -23, 90);
	chassis.moveToPoint(38.5, -29, 900, {.forwards=false, .minSpeed=15, .earlyExitRange=3});
	chassis.swingToPoint(24, -22, lemlib::DriveSide::LEFT, 900, {.forwards=false, .maxSpeed=100}); // swing to grab mogo
	approachAndClampMogo();
	delay(200);
	chassis.turnToPoint(16.7, -16, 1000);
	chassis.moveToPose(14.8, -16, 285, 1100, {.lead=0.1, .maxSpeed=90}); // move to grab center ring
	chassis.waitUntilDone();
	ringDoinker.toggle();
	delay(300);
	chassis.moveToPoint(58, -20, 900, {.forwards=false}); // move back to drag back ring
	chassis.waitUntilDone();
	ringDoinker.toggle();
	intake.move(127);
	conveyor.move(127);
	chassis.moveToPoint(35.5, -12, 900); // grab dragged ring
	chassis.moveToPoint(24, -55, 1100); // go to the safe ring stack
	chassis.turnToPoint(65, -45, 900);
	chassis.moveToPoint(40, -61, 1000, {.minSpeed=10, .earlyExitRange=5});
	chassis.moveToPoint(65, -61, 1000, {.maxSpeed=90});
	chassis.waitUntilDone();
	chassis.tank(105, 100);

}


inline void SORAuto() {

	// Alliance stake
	delay(100);
	ladybrownMotor.move(127);
	delay(1000);
	ladybrownMotor.move(-127);
	
	// Blue Ring Side
	// chassis.setPose(58, 8, 160);
	// chassis.moveToPoint(47, 46, 1000, {.forwards=false});
	// chassis.turnToPoint(24, 46.5, 1000);
	// ladybrownMotor.move(0);
	// intake.move(127);
	// chassis.moveToPoint(24, 46.5, 1000);
	// chassis.turnToPoint(25, 26, 1000, {.forwards=false});
	// chassis.moveToPoint(25, 28, 1000, {.forwards=false});
	// chassis.waitUntilDone();
	// approachAndClampMogo();
	// conveyor.move(127);
	// chassis.moveToPoint(60, 60, 1500, {.minSpeed = 40, .earlyExitRange=2});
	// chassis.waitUntilDone();
	// chassis.tank(127, 127);
	// delay(1500);
	// chassis.tank(0, 0);



	// Touch Ladder
	// delay(600);
	// chassis.turnToPoint(16, 16, 1000);
	// chassis.moveToPoint(20, 20, 1000);	
	// chassis.waitUntilDone();
	// ladybrownMotor.move(127);
	// delay(1000);
	// ladybrownMotor.move(0);


	// Red Ring Side
	chassis.setPose(-60, 8, 192);
	chassis.moveToPoint(-47, 46, 1000, {.forwards=false});
	chassis.turnToPoint(-24, 46.5, 1000);
	ladybrownMotor.move(0);
	intake.move(127);
	chassis.moveToPoint(-24, 46.5, 1000);
	chassis.turnToPoint(-26, 26, 1000, {.forwards=false});
	chassis.moveToPoint(-26, 29, 1000, {.forwards=false});
	chassis.waitUntilDone();
	approachAndClampMogo();
	conveyor.move(127);
	chassis.moveToPoint(-60, 60, 1500, {.minSpeed = 40, .earlyExitRange=2});
	chassis.waitUntilDone();
	chassis.tank(127, 127);
	delay(1500);
	chassis.tank(0, 0);


	// chassis.setPose(-59, -14, 320);
	// chassis.moveToPoint(-36, -36, 1000);
	// chassis.turnToPoint(-23, -47, 1000);
	// chassis.moveToPoint(-23, -47, 1000);
	// intake.move(127);
	// // conveyor.move(127);
	// chassis.waitUntilDone();
	// delay(500);
	// chassis.turnToPoint(-23, -23, 1000, {.forwards = false});
	// chassis.moveToPoint(-23, -36, 1000, {.forwards = false});
	// chassis.waitUntilDone();
	// chassis.tank(-90, -90);
	// delay(460);
	// mogoclamp.toggle();
	// conveyor.move(127);
	// delay(2000);
	// chassis.tank(0,0);
	



}


inline void redRingRush(){
	ringDoinker.extend();
	chassis.setPose(-50.165, 62.047, 100);
	chassis.moveToPoint(-20.975, 58.947, 1000, {.minSpeed = 30, .earlyExitRange = 5}); //move to intermediate point
	chassis.moveToPoint(-11.676, 54.298, 1000); //rush the rings
	intake.move(127);
	conveyor.move(127);
	stopNextRing = true;
	chassis.swingToHeading(270, DriveSide::RIGHT, 1000);
	chassis.moveToPoint(-41.382, 36.216, 1000); //thread the needle
	ringDoinker.retract();
	chassis.turnToPoint(-31.308, 29.499, 1000, {.forwards = false}); //go to grab mogo
	chassis.moveToPoint(-31.308, 29.499, 1000, {.forwards = false}); //go to grab mogo
	approachAndAutoClampMogo(500);
	conveyor.move(127);
	chassis.moveToPoint(-54.298, 51.714, 1500); //move to preload ring that was left beside bot


}

inline void blueRingRush(){
	chassis.setPose(49.5, 29, 285);
	ringDoinker.extend();
	intake.move(127);
	conveyor.move(127);
	chassis.moveToPoint(9.743, 41, 1000); //rush rings
	delay(400);
	stopNextRing = true;
	chassis.moveToPoint(14.78, 39.565, 700, {.forwards = false});
	chassis.turnToPoint(10.023, 30.791, 700, {.forwards = false, .maxSpeed = 80});
	// chassis.moveToPoint(10.023, 30.791, 800, {.forwards = false, .minSpeed = 20, .earlyExitRange = 1});
	chassis.moveToPose(11.056, 24.591, 300, 1200, {.forwards = false});
	// chassis.turnToHeading(300, 600, {.minSpeed = 20, .earlyExitRange = 10});
	// chassis.moveToPoint(14.78, 28.385, 600, {.forwards = false});
	// chassis.moveToPoint(18.896, 37.585, 600, {.forwards = false, .minSpeed = 30, .earlyExitRange = 1}); //move to intermediate point
	// chassis.turnToPoint(21, 24.789, 600, {.forwards = false}); //move back into mogo
	// chassis.moveToPoint(21, 24.789, 1300, {.forwards = false}); //move back into mogo
	approachAndAutoClampMogo(500); //clamp first mogo
	ringDoinker.retract();
	conveyor.move(127);
	chassis.turnToPoint(21, 58.431, 1000);
	chassis.moveToPoint(21, 58.431, 1000, {.maxSpeed = 80}); //move to double ring stack behind rushed rings
	delay(400); //intake ring
	chassis.turnToPoint(53.936, 61.789, 800); //move to corner
	chassis.moveToPoint(53.936, 61.789, 1500); //move to corner
	chassis.turnToHeading(45, 700);
	chassis.waitUntilDone();
	chassis.tank(80, 80);
	intake.move(127);
	delay(500);
	chassis.tank(100, 60);
	delay(500);
	chassis.tank(60, 100);
	delay(500);
	chassis.tank(80, 80);
	delay(500);
	chassis.moveToPoint(51, 51, 1000, {.forwards = false}); //move back out
	intakeRiser.toggle();
	chassis.moveToPoint(59.327, 57.974, 1500); //move back to corner
	chassis.tank(80, 80);
	intake.move(127);
	delay(2000);
	chassis.moveToPoint(53, 53, 1000, {.forwards = false}); //move back out
	intakeRiser.toggle();
	chassis.turnToPoint(54.242, 42.237, 600);
	chassis.moveToPoint(54.242, 42.237, 1000); //move back to ring preload and intake it
}




inline void redMogoRushClampedMogo(){
	chassis.waitUntilDone();
	conveyor.move(127);


	// chassis.moveToPoint(-14.001, -43.862, 1000, {.forwards = false});
	// chassis.waitUntilDone();
	// delay(600);
	// mogoclamp.retract(); //unclamp first mogo

	chassis.moveToPoint(-38.282, -44.637, 1000, {.minSpeed = 30, .earlyExitRange = 4}); //intermediate point
	chassis.moveToPose(-58.947, -58.844, 223.6, 1500); //move to corner
	chassis.waitUntilDone();
	chassis.tank(80, 80);
	intake.move(127);
	delay(1000);
	chassis.moveToPoint(-55.072, -54.775, 1000, {.forwards = false});
	chassis.moveToPose(-58.947, -58.844, 223.6, 800);
	chassis.waitUntilDone();
	chassis.tank(80, 80);
	delay(1000);
	chassis.moveToPoint(-55.072, -54.775, 1000, {.forwards = false});
	chassis.moveToPose(-58.947, -58.844, 223.6, 800);
	chassis.waitUntilDone();
	stopNextRing = true;
	chassis.tank(80, 80);
	delay(1000);
	chassis.moveToPose(-35.182, -29.654, 240, 1500);
	approachAndAutoClampMogo(500);
	conveyor.move(12);
}

/**
 * Setup center tile, right of blue ring, hs far forward, on the start line
 * FOR PROVS
 */
inline void redMogoRush(){
	reactiveClawClampOn = true;
	clawDoinker.extend();
	chassis.setPose(-49.906, -36.887, 110);
	intake.move(127);
	chassis.moveToPoint(-17.875, -47.8, 1500, {.minSpeed = 127}); //rush mogo
	chassis.moveToPoint(-34.407, -42.57, 2000, {.forwards = false});
	claw.extend();
	reactiveClawClampOn = false;
	chassis.waitUntilDone();
	claw.retract();
	delay(400);
	clawDoinker.retract();
	chassis.tank(-40, -40);
	delay(600);
	chassis.turnToPoint(-22, -42, 1200, {.forwards = false}); //turn to the rushed mogo
	chassis.moveToPoint(-22, -42, 1200, {.forwards = false, .maxSpeed = 100});
	chassis.waitUntilDone();
	chassis.tank(0, -100);
	delay(150);
	approachAndAutoClampMogo(80, 400); //clamp the rushed mogo
	
	if(mogo_distance.get_distance() < 10){ //we have clamped mogo
		redMogoRushClampedMogo();
	}
	else{
		mogoclamp.retract();
		delay(200);
		chassis.turnToPoint(-22, -34, 1000, {.forwards = false}); //go to second mogo
		intake.move(0);
		conveyor.move(0);
		chassis.moveToPoint(-22, -34, 1000, {.forwards = false});
		chassis.waitUntilDone();
		chassis.tank(0, -100);
		delay(200);
		// chassis.moveToPose(-24, -34, 180, 1000, {.forwards = false});
		approachAndAutoClampMogo(500);
		conveyor.move(127);
	}
	

}

