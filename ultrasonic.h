/*
 * ultrasonic.h
 *
 *  Created on: Oct 5, 2022
 *      Author: MacNCheese
 */

#include "pwm.h"
#include "msp.h"
#include <stdio.h>

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define ERR_LESS_THAN_MIN_DIST 0x0002
#define ERR_GRTR_THAN_MAX_DIST 0x0190

void timer_a_0_init_trig(void);
void ultrasonic_calc_distance_cm(volatile uint32_t *cap_vals);
void ultrasonic_calc_distance_cb(void);

#endif /* ULTRASONIC_H_ */
