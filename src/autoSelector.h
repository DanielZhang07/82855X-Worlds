#pragma once
#include "pros/rtos.hpp"
#include "pros/screen.hpp"
#include "pros/screen.h"
#include "util.h"
#include "globalStates.h"
inline void autoSelector(){
    //screen is 480 wide by 272 tall

	pros::screen::set_pen(pros::Color::blue);
	pros::screen::fill_rect(0, 0, 480, 136);
	pros::screen::set_pen(pros::Color::red);
	pros::screen::fill_rect(0, 136, 480, 272);
	pros::screen::set_pen(pros::Color::black);

	int numSeperatingLines = 5;
	for(int i = 1; i <= numSeperatingLines; i++){
		pros::screen::draw_line(i*480/(numSeperatingLines+1), 0, i*480/(numSeperatingLines+1), 272);
		//80 width per rectangle when numSepLines = 5
	}


	pros::screen::set_eraser(pros::Color::white);
	pros::screen::print(pros::E_TEXT_MEDIUM, 15, 50, "MOGO");
	pros::screen::print(pros::E_TEXT_MEDIUM, 15, 70, "RUSH");

	pros::screen::print(pros::E_TEXT_MEDIUM, 15, 212, "MID");
	pros::screen::print(pros::E_TEXT_MEDIUM, 15, 222, "RUSH");
	// pros::screen::print(E_TEXT_MEDIUM, 415, 200, "PONG");
	// pros::screen::print(E_TEXT_MEDIUM, 415, 60, "PONG");

	pros::screen_touch_status_s_t status;
	// Pong pongGame;

    while(true) {
		status = pros::c::screen_touch_status();
		if(status.touch_status == pros::E_TOUCH_PRESSED){
			if(coordinateWithinRectangle(status.x, status.y, 0, 136, 80, 272)){
				pros::screen::print(pros::E_TEXT_MEDIUM, 415, 200, "SELECTED");
				auto_selected = 2; //lower left rectangle
				return;
			}
			else if(coordinateWithinRectangle(status.x, status.y, 0, 0, 80, 180)){
				pros::screen::print(pros::E_TEXT_MEDIUM, 415, 60, "SELECTED");
				auto_selected = 1; //upper right rectangle
				return;
			}
			
		}
		// pongGame.update(status);
		// pongGame.draw();
		pros::delay(16);
    }
}