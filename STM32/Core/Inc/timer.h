/*
 * timer.h
 *
 *  Created on: Nov 22, 2022
 *      Author: LENOVO
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

void setTimer1(int duration);
void setTimer2(int duration);

void timerRun();

extern int timer1_flag;
extern int timer2_flag;

#endif /* INC_TIMER_H_ */
