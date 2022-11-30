/*
 * pwm.h
 *
 *  Created on: Sep 19, 2022
 *      Author: Arielle
 */

#ifndef PWM_H_
#define PWM_H_
#include "msp.h"
#include "scheduler.h"

#define TICKS ((uint16_t) 0x0BB8) // 3000

#define TICKS_1 11466
#define TICKS_2 10823
#define TICKS_3 10216
#define TICKS_4 9642
#define TICKS_5 9101


// 1ms period
// (tassel * period) / input divider = ticks

#define CCR1_DUTY_ULTRASONIC (TICKS) - (TICKS/100)

//1KHZ -> 0.001ms Period
//TASSEL*(PERIOD)= TICKS
void config_pwm_timer(void);

void config_pwm_ticks_a0(uint16_t ticks);

void stop_pwm(void);

void start_pwm(void);

#endif /* PWM_H_ */
