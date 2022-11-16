/*
 * gpio.c
 *
 *  Created on: Oct 5, 2022
 *      Author: MacNCheese
 */
#include "gpio.h"

void config_pwm_gpio(void){
    P2->DIR |= BIT4; // pin 2.4 timerA
    P2->OUT |= BIT4;
    P2->DS  |= BIT4;
    P2->SEL0 |=BIT4;
    P2->SEL1 &= BIT4;

    P6->DIR &= ~BIT6; // pin 6.6 timerA
    P6->REN &= ~BIT6;
    P6->SEL0 |=BIT6;
    P6->SEL1 &= ~BIT6;
}
