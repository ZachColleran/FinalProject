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
#define TICKS_2 ((uint16_t) 0xFFFF) // max

// 1ms period
// (tassel * period) / input divider = ticks

#define CCR1_DUTY_ULTRASONIC (TICKS) - (TICKS/100)

//1KHZ -> 0.001ms Period
//TASSEL*(PERIOD)= TICKS
void config_pwm_timer(void);

void stop_pwm(void);

void start_pwm(void);

void config_pwm_gpio(void);
void timer_a_2_init_measure_echo_cci(void);

void config_pwm_timer_ultrasonic(void);

void config_nvic(void);

uint16_t read_distance(void);

void ultrasonic_start_pulse(void);

#endif /* PWM_H_ */
