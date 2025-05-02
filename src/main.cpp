#include "main.h"
#include "lemlib/api.hpp"
#include "constants.h"
#include "globalStates.h"
#include "armController.h"
#include "./devices.h"
#include "macros.h"
#include <cmath>
#include "util.h"
#include "./tasks.h"
#include "autons.h"
// using json = nlohmann::json;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

  pros::lcd::initialize();
  colour_sensor.set_led_pwm(100);
  colour_sensor.set_integration_time(60);
  horizontal_tracker.set_data_rate(5);
  vertical_tracker.set_data_rate(5);
  imu.set_data_rate(5);
  horizontal_tracker.set_position(0);
  vertical_tracker.set_position(0);
  horizontal_tracker.reset();
  vertical_tracker.reset();
  chassis.calibrate();
  ladybrownMotor.tare_position();
  master.clear();
  pros::Task ladybrown(ladybrownTask);
  pros::Task color(color_task);
  pros::Task claw(reactiveClawClamp);
};


/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the pros::lcd.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  sorter_active = true;
  auton_active = true;
  team_color = 'r'; // KEEP THiS COLOR IN BOT
  redGoalRush();


}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

  sorter_active = true;
  auton_active = false;
  team_color = 'r';
  colour_sensor.set_led_pwm(100);
  colour_sensor.set_integration_time(60);
  while (true) {

    int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    // chassis.arcade(leftY, rightX, false, 0.75);
    chassis.arcade(leftY, rightX);

    // intake
    // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    //   conveyor.move(127);
    //   intake.move(127);
    // } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) &&
    //            !clawDoinker.is_extended()) {
    //   conveyor.move(-127);
    //   intake.move(-127);
    // } else {
    //   conveyor.move(0);
    //   intake.move(0);
    // }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
      if (mogoclamp.is_extended()) {
        mogoclamp.retract();
      } else {
        mogoclamp.extend();
      }
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
      if (clawDoinker.is_extended()) {
        clawDoinker.retract();

      } else {
        clawDoinker.extend();
      }
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
      if (intakeRiser.is_extended()) {
        intakeRiser.retract();
      } else {
        intakeRiser.extend();
      }
    }
    // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
    //   ladybrownMotor.move(127);
    // } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    //   ladybrownMotor.move(-127);
    // } else
    //   ladybrownMotor.move(0);

    // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    //   intake.move(127);
    //   conveyor.move(127);
    // } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    //   intake.move(-127);
    //   conveyor.move(-127);
    // } else {
    //   intake.move(0);
    //   conveyor.move(0);
    // }

    // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    //   if (mogoclamp.is_extended()) {
    //     mogoclamp.retract();
    //   } else {
    //     mogoclamp.extend();
    //   }
    // }
    // if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    // }

    // // print to brain screen
    // // pros::lcd::print(0, "x: %f", chassis.getPose().x);
    // pros::lcd::print(1, "y: %f", chassis.getPose().y);
    pros::lcd::print(2, "theta: %f", chassis.getPose().theta);
    pros::lcd::print(3, "hori tracker: %f",
                     horizontal_tracking_wheel.getDistanceTraveled());
    pros::lcd::print(4, "verti tracker: %f",
                     vertical_tracking_wheel.getDistanceTraveled());
    pros::delay(20);
  }
}