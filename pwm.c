/*
 * pwm.c
 *
 *  Created on: Sep 19, 2022
 *      Author: Arielle
 */
#include "pwm.h"
void start_pwm(void)
{
    TIMER_A0 -> CTL |= TIMER_A_CTL_MC__UP;// set MC to up
    TIMER_A2 -> CTL |= TIMER_A_CTL_MC__CONTINUOUS;// set MC to up
}


void stop_pwm(void)
{
    TIMER_A0 -> CTL = TIMER_A_CTL_MC__STOP;// set MC to halt, stop
    TIMER_A2 -> CTL = TIMER_A_CTL_MC__STOP;
}
void config_pwm_timer(void)
{
    TIMER_A0 -> CTL |= TIMER_A_CTL_CLR; //clear R
    TIMER_A0 -> CTL |= TIMER_A_CTL_SSEL__SMCLK;// config clk src SMCLK

    // CONFIG INPUT DIVIDER, already 1
    //want known state + NOR glitch occurs so use TIMER_A_CCTLN_OUTMOD_7 as intermediary state
    TIMER_A0 -> CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7; //NOR glitch set 1111 MODE
    TIMER_A0 -> CCTL[1] &= TIMER_A_CCTLN_OUTMOD_3; //TOGGLE MODE

    TIMER_A0->CCR[0] = TICKS;
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_CCIE; // enable inturrupts for compare/capture


    /* ////////// TIMER A2 ///////////// */

    TIMER_A2 -> CTL |= TIMER_A_CTL_CLR; //clear R

    TIMER_A2 -> CTL |= TIMER_A_CTL_SSEL__SMCLK;// config clk src SMCLK

    // CONFIG INPUT DIVIDER, already 1
    //want known state + NOR glitch occurs so use TIMER_A_CCTLN_OUTMOD_7 as intermediary state
    TIMER_A2 -> CCTL[3] |= TIMER_A_CCTLN_OUTMOD_7; //NOR glitch set 1111 MODE
    TIMER_A2 -> CCTL[3] &= TIMER_A_CCTLN_OUTMOD_3; //TOGGLE MODE

    TIMER_A2->CCR[3] = TICKS;
    TIMER_A2->CCTL[3] |= TIMER_A_CCTLN_CCIE; // enable inturrupts for compare/capture

}


void config_nvic(void) {
    __NVIC_EnableIRQ(TA0_N_IRQn);
    __NVIC_EnableIRQ(TA2_N_IRQn);
}




