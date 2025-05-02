#pragma once

//DON'T COMMUNICATE WITH MAIN THREAD. Reading is fine, never write
const float REST = 0;
const float CAPTURE = 50;
const float MANUAL = 350;
const float LADDER = 250;
inline float positions[3] = { REST, CAPTURE,MANUAL };
inline int lbTarget = 0; //NUMBER FROM 0-SIZE OF POSITIONS ARRAY, DO NOT PUT THE ACTUAL ANGLE
inline bool conveyor_locked = false;

inline float conveyor_speed = 127;

inline void driver_inputs() {
    if (!auton_active) { //don't run driver inputs if auton is active
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            conveyor.move(127);
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !clawDoinker.is_extended()) {
            conveyor.move(-127);
        } else {
            conveyor.move(0);
        }

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !clawDoinker.is_extended()) {
            intake.move(127);
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            intake.move(-127);
        } else {
            intake.move(0);
        }
    }
}
inline void ladybrownTask() {

    bool lbAboveCapture = false;
    bool newLBPress = false;
    bool manualLBMode = false;
    ladybrownMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    int lbTarget = 0;

    while (true) {

        float currTheta = ladybrownMotor.get_position() / 3;

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
            if (lbTarget < (sizeof(positions) / sizeof(positions[0])) - 1) {
                lbTarget++;
            }
        }
        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT) && positions[lbTarget] != MANUAL) {
            lbTarget = 0;
        }




        if (!auton_active) {
            if (positions[lbTarget] == CAPTURE) {
                float powerGiven = ladybrownController.update(currTheta, (positions[lbTarget] - currTheta));
                ladybrownMotor.move(powerGiven); //update PID and motor voltage
            } else { //manual mode is active
                if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) && master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
                    ladybrownMotor.move(0);
                } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
                    ladybrownMotor.move(127);
                } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
                    ladybrownMotor.move(-127);
                } else ladybrownMotor.move(0);
                if (currTheta < CAPTURE) lbTarget = 0;
            }
        }


        if(!conveyor_locked){
            driver_inputs();
        }


        pros::delay(15);
    }
}
inline void intakeAuton(){
    if(intake_state == 1){
        conveyor.move(127);
    }
    else conveyor.move(0);
}
inline void color_task() {

    

    char colour_detected = 'n'; // 'n' means empty
    bool wrong_color_detected = false;
    float wrong_color_detected_time = 0;
    int controller_print = 0;


    while (true) {
        
        double hue = colour_sensor.get_hue();
        double intakeVoltage = intake.get_voltage();
        double conveyorVoltage = conveyor.get_voltage();
        if (in_range(hue, 180, 230)) {
            colour_detected = 'b';
        } else if (in_range(hue, 1, 30)) {
            colour_detected = 'r';
        } else {
            colour_detected = 'n';
        }



        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) { //toggle whether color sort is active or not
            sorter_active = !sorter_active;
        }

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) { //toggle color sort setting
            if (team_color == 'r') {
                team_color = 'b';
            } else {
                team_color = 'r';
            }
        }

        


        if (sorter_active && team_color != 'n' && team_color != colour_detected && colour_detected != 'n' && distance_sensor.get() < CONVEYOR_DISTANCE_OFFSET) {
            conveyor_locked = true;
            pros::delay(50);
            conveyor.move(-127);
            pros::delay(300);
            conveyor.move(127); //reset the voltage to what it was before reversing the conveyor
            conveyor_locked = false;
            
        } else if (!conveyor_locked){
            if(!auton_active){
                driver_inputs();
            }
            else intakeAuton();
        }

        if (controller_print == 0) {
            master.print(0, 0, "Sorter State: %s", sorter_active ? "Active" : "Inactive");
            controller_print = 10;
        } else if (controller_print == 5) {
            master.print(1, 0, "Team Color: %s", team_color == 'r' ? "Red" : "Blue");
        }
        if (controller_print > 0) {
            controller_print--;
        }
        pros::delay(15);
    }
}

inline void reactiveClawClamp() {
    while (true) {
        if (reactiveClawClampOn) {
            if (clawLimitSwitch.get_new_press() == 1) {
                claw.extend();
                if (auton_active) {
                    chassis.cancelMotion();
                }
            }
        }
        pros::delay(30);
    }
}

// /// @brief Stops the conveyor when a ring is detected by the distance sensor
inline void monitor_and_stop_conveyor() {
     while (true) {
        if (auton_active) {
            if (stopNextRing) {
                if (distance_sensor.get() < CONVEYOR_DISTANCE_OFFSET) {
                    conveyor.move(0);
                    stopNextRing = false;
                }
            }
        }
        pros::delay(30);
    }
}
// inline void unjamLBTask() {

//     int jamCount = 0;

//     while (true) {
//         if (unjamLB) {
//             if (lbTarget == 0 && in_range(((float)ladybrownMotor.get_position()), 15, 33)) {
//                 if (jamCount >= 20) { // lb is not fully down despite being told to be down
//                     // set_LBPosition(1);
//                     int prevMotorState = conveyor.get_voltage();
//                     conveyor.move(-127);
//                     pros::delay(350);
//                     if (unjamLB) {
//                         if (prevMotorState > 2000) {
//                             conveyor.move(127);
//                         } else if (prevMotorState < -2000) {
//                             conveyor.move(-127);
//                         } else conveyor.move(0);
//                     }
//                     // set_LBPosition(0);
//                     jamCount = 0;
//                 }
//                 jamCount++;
//             }
//         }
//         pros::delay(30);
//     }
// }




inline void autoClampTask() {
    while (true) {
        if (clampRequested) {
            if (mogo_distance.get() < 7 && !mogoclamp.is_extended()) { // clamp the mogo when it is close enough
                mogoclamp.extend();
                clampRequested = false;
            }
        }
        pros::delay(30);
    }
}
