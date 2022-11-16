/*
 * scheduler.c
 *
 *  Created on: Oct 5, 2022
 *      Author: MacNCheese
 */
#include "scheduler.h"

static unsigned int event_scheduled;

void scheduler_init(void) {
    event_scheduled = 0;
}

void add_scheduled_event(uint16_t event) {
    __disable_interrupt();
    event_scheduled |= event;
    __enable_interrupt();
}

uint16_t get_scheduled_event(void) {
    return event_scheduled;
}

void remove_scheduled_event(uint16_t event) {
    __disable_interrupt();
    event_scheduled &= ~event;
    __enable_interrupt();
}

