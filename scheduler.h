/*
 * scheduler.h
 *
 *  Created on: Oct 5, 2022
 *      Author: MacNCheese
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include "msp.h"

#define BUTTON_1_CB 0x01
#define BUTTON_2_CB 0x02
#define BUTTON_3_CB 0x04
#define BUTTON_4_CB 0x08
#define BUTTON_5_CB 0x10

void scheduler_init(void);

void add_scheduled_event(uint16_t event);

uint16_t get_scheduled_event(void);

void remove_scheduled_event(uint16_t event);

#endif /* SCHEDULER_H_ */
