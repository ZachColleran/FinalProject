/*
 * scheduler.h
 *
 *  Created on: Oct 5, 2022
 *      Author: MacNCheese
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include "msp.h"

#define ULTRASONIC_START_CB 0x01
#define ULTRASONIC_END_CB 0x02

void scheduler_init(void);

void add_scheduled_event(uint16_t event);

uint16_t get_scheduled_event(void);

void remove_scheduled_event(uint16_t event);

#endif /* SCHEDULER_H_ */
