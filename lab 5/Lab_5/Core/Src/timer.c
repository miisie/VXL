/*
 * timer.c
 *
 *  Created on: Dec 10, 2021
 *      Author: buiqu
 */
#include "timer.h"
int timer_counter = 0;
int timer_flag = 0;
int TIMER_CYCLE = 10;

void setTimer ( int duration_led ){
	timer_counter = duration_led / TIMER_CYCLE ;
	timer_flag = 0;
}

void timer_run (){
	if( timer_counter > 0){
		timer_counter --;
		if( timer_counter == 0) {
			timer_flag = 1;
		}
	}
}
