/*
 * gpio.c
 *
 *  Created on: Oct 5, 2022
 *      Author: MacNCheese
 */
#include "gpio.h"
#include "scheduler.h"

void config_button_gpio(void) {

    // button 1
    P4->DIR &= ~BIT0;
    P4->OUT |= BIT0;

    // button 2
    P4->DIR &= ~BIT2;
    P4->OUT |= BIT2;

    // button 3
    P4->DIR &= ~BIT4;
    P4->OUT |= BIT4;

    // button 4
    P4->DIR &= ~BIT5;
    P4->OUT |= BIT5;

    // button 5
    P4->DIR &= ~BIT7;
    P4->OUT |= BIT7;

}


void config_pwm_gpio(void){
    P2->DIR |= BIT4; // pin 2.4 timerA
    P2->OUT |= BIT4;
    P2->DS  |= BIT4;
    P2->SEL0 |=BIT4;
    P2->SEL1 &= BIT4;
}
