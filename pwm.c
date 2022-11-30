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
}

void stop_pwm(void)
{
    TIMER_A0 -> CTL = TIMER_A_CTL_MC__STOP;// set MC to halt, stop
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
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_CCIE; // enable interrupts for compare/capture

}

//C4 - 261.63 Hz = 3.82219 ms
//C#4/Db4 - 277.18 Hz = 3.60776 ms
//D4 - 293.66 Hz = 3.40529 ms
//D#4/Eb4 - 311.13 Hz = 3.21409 ms
//E4 - 329.63 Hz = 3.03370 ms

void config_nvic(void) {
    __NVIC_EnableIRQ(TA0_N_IRQn);
}

void config_pwm_ticks_a0(uint16_t ticks) {
    TIMER_A0->CCR[0] = ticks;
}




