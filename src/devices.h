#pragma once
#include "main.h"
#include "lemlib/api.hpp"
#include "ArmController.h"
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

inline pros::MotorGroup left({-4,-5,-6}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::rotations);
inline pros::MotorGroup right({1,2,3}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::rotations);



inline pros::Motor intake(10, pros::v5::MotorGears::rpm_200);
inline pros::Motor conveyor(9, pros::v5::MotorGears::blue);
inline pros::Motor ladybrownMotor(8, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
inline pros::Imu imu(20);

inline pros::Rotation horizontal_tracker(-11);
inline pros::Rotation vertical_tracker(-12);

inline pros::Distance mogo_distance(7);

inline pros::Optical colour_sensor(19);
inline pros::Distance distance_sensor(18);

inline pros::Distance left_distance(10);
inline pros::Distance back_distance(13);
inline pros::GPS gps_sensor(10);


inline pros::adi::Pneumatics mogoclamp('e', false);
inline pros::adi::Pneumatics clawDoinker('b', false);
inline pros::adi::Pneumatics claw('a', false);
inline pros::adi::Pneumatics ringDoinker('c', false);
inline pros::adi::Button clawLimitSwitch('g');
inline pros::adi::Pneumatics intakeRiser('d', false);

inline lemlib::PID ladybrownPID(1.2, // kP
    0, // kI
    0, // kD
    5, // integral anti windup range
    false); // don't reset integral when sign of error flips

inline armController ladybrownController(
    13, // Kcos
    ladybrownPID
);

//drivetrain is 12 inches wide and 11.5 inches from back to front, all measured from midwheels
inline lemlib::Drivetrain drivetrain(&left, &right, 12, lemlib::Omniwheel::NEW_275, 600, 2);

inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracker, lemlib::Omniwheel::NEW_275, 1.59448913102);
inline lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracker, lemlib::Omniwheel::NEW_275, -1.2087590096);

inline lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu);

// lemlib::ControllerSettings lateral_controller(10, 0, 60, 3, 1, 500, 3, 750, 15);
inline lemlib::ControllerSettings lateral_controller(18.5, 0,200, 3, 1, 100, 3, 500, 50);


// lemlib::ControllerSettings angular_controller(4.1, 0.35, 42, 3, 1, 100, 3, 500, 25);
inline lemlib::ControllerSettings angular_controller(7.5, 0, 90, 0, 2, 65, 3, 115, 20);



inline lemlib::ExpoDriveCurve throttle_curve(1, 10, 1.025);
inline lemlib::ExpoDriveCurve steer_curve(1, 10, 1.025);

inline lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve);