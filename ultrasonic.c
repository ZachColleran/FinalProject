/*
 * ultrasonic.c
 *
 *  Created on: Oct 5, 2022
 *      Author: MacNCheese
 */
#include "ultrasonic.h"

volatile static uint32_t cap_vals[2];

void timer_a_0_init_trig(void){
    TIMER_A0->CTL |= TIMER_A_CTL_CLR;
    TIMER_A0->CTL |= TIMER_A_CTL_SSEL__TACLK;

    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7;
    TIMER_A0->CCTL[1] &= TIMER_A_CCTLN_OUTMOD_3; //set/reset mode

    TIMER_A0->CCR[0] = TICKS;
    TIMER_A0->CCR[1] = CCR1_DUTY_ULTRASONIC;

    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_CCIE;
}

void TA0_N_IRQHandler(void) {
    TIMER_A0->CTL = TIMER_A_CTL_MC__STOP;
    TIMER_A0->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG; //clear flag
    TIMER_A0->CCTL[1] &= ~TIMER_A_CCTLN_CCIE; //disable interrupt
}

void ultrasonic_calc_distance_cb(void){
    volatile uint32_t *ptr;
    ptr = cap_vals;
    ultrasonic_calc_distance_cm(ptr);
}

void ultrasonic_calc_distance_cm(volatile uint32_t *cap_vals) {
    float start = (float)cap_vals[0] * 0.0000005; // ticks to time conversion
    float end = (float)cap_vals[1] * 0.0000005;

    uint32_t distance = ((end-start)/2)*34300;
    if((distance > ERR_GRTR_THAN_MAX_DIST) | (distance < ERR_LESS_THAN_MIN_DIST)){
        printf("E: %lu\n", distance);
    }
    else{
        printf("In Range: %lu\n",distance);
    }
    TIMER_A0->CTL |= TIMER_A_CTL_SSEL__SMCLK;
    TIMER_A0->CTL |= TIMER_A_CTL_MC__UP; // start trig back up
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_CCIE; // enable interrupts for trig
}

void timer_a_2_init_measure_echo_cci(void) { // A2.3 on pin 6.6
    TIMER_A2 -> CTL |= TIMER_A_CTL_CLR; //clear R
    TIMER_A2 -> CTL |= TIMER_A_CTL_SSEL__TACLK;// config clk src TACLK

    TIMER_A2 -> CCTL[3] |= TIMER_A_CCTLN_OUTMOD_7; // Same for TimerA2.3
    TIMER_A2 -> CCTL[3] &= TIMER_A_CCTLN_OUTMOD_3;

    TIMER_A2 -> CCTL[3] |= TIMER_A_CCTLN_CM_3; // rising and falling edge
    TIMER_A2 -> CCTL[3] |= TIMER_A_CCTLN_CAP; // capture mode
    TIMER_A2 -> CCTL[3] |= TIMER_A_CCTLN_CCIS_0;
    TIMER_A2 -> CCTL[3] |= TIMER_A_CCTLN_SCCI;
    TIMER_A2 -> CCTL[3] |= TIMER_A_CCTLN_SCS;
    TIMER_A2 -> CCTL[3] |= TIMER_A_CCTLN_CCIE;
    TIMER_A2 -> CCR[0] = TICKS;
}

void TA2_N_IRQHandler(void){
    uint32_t int_flag = TIMER_A2->CCTL[3];
    TIMER_A2->CCTL[3] &= ~TIMER_A_CCTLN_CCIFG;

    if(int_flag & TIMER_A_CCTLN_CCIFG){ // first capture
        if(P6->IN & BIT6){
            TIMER_A2->CCTL[3] &= ~TIMER_A_CCTLN_COV;
            cap_vals[0] = TIMER_A2->CCR[3];
        }
        else { // second capture
            add_scheduled_event(ULTRASONIC_END_CB);
            if(!(TIMER_A2->CCTL[3] & TIMER_A_CCTLN_COV)){
                cap_vals[1] = TIMER_A2->CCR[3];
                TIMER_A2->CCTL[3] &= ~TIMER_A_CCTLN_COV;
            }
            else{
                cap_vals[1] = TIMER_A2->CCR[3] + 0xFFFF;
                TIMER_A2->CCTL[3] &= ~TIMER_A_CCTLN_COV;
            }
        }
    }
}

