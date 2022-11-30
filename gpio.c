/*
 * gpio.c
 *
 *  Created on: Oct 5, 2022
 *      Author: MacNCheese
 */
#include "gpio.h"


void config_button_gpio(void) {

    // button 1
    P4->DIR &= ~BIT0;
    P4->OUT |= BIT0;
    P4->IFG &= ~BIT0; // set flag to 0
    P4->IES &= ~BIT0; // set p4.0 for edge transition. 0= low->high, 1= high->low
    P4->IE |= BIT0; // enable interrupt

    // button 2
    P4->DIR &= ~BIT2;
    P4->OUT |= BIT2;
    P4->IFG &= ~BIT2; // set flag to 0
    P4->IES &= ~BIT2; // set p4.0 for edge transition. 0= low->high, 1= high->low
    P4->IE |= BIT2; // enable interrupt

    // button 3
    P4->DIR &= ~BIT4;
    P4->OUT |= BIT4;
    P4->IFG &= ~BIT4; // set flag to 0
    P4->IES &= ~BIT4; // set p4.0 for edge transition. 0= low->high, 1= high->low
    P4->IE |= BIT4; // enable interrupt

    // button 4
    P4->DIR &= ~BIT5;
    P4->OUT |= BIT5;
    P4->IFG &= ~BIT5; // set flag to 0
    P4->IES &= ~BIT5; // set p4.0 for edge transition. 0= low->high, 1= high->low
    P4->IE |= BIT5; // enable interrupt

    // button 5
    P4->DIR &= ~BIT7;
    P4->OUT |= BIT7;
    P4->IFG &= ~BIT7; // set flag to 0
    P4->IES &= ~BIT7; // set p4.0 for edge transition. 0= low->high, 1= high->low
    P4->IE |= BIT7; // enable interrupt

}


void config_pwm_gpio(void){
    P2->DIR |= BIT4; // pin 2.4 timerA
    P2->OUT |= BIT4;
    P2->DS  |= BIT4;
    P2->SEL0 |=BIT4;
    P2->SEL1 &= BIT4;
}
