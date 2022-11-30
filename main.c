#include "msp.h"
#include "scheduler.h"
#include "pwm.h"
#include "gpio.h"
/**
 * main.c
 */


void main(void)
{
    // Once trigger is sent, starting CNT value is stored in CCR[2], need to store previous value somewhere because CCR[2] will change
    // time between events = (current-previous)*(time per tick)
    // Set CAP and CCI

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer
    __disable_interrupt();
    stop_pwm(); //KNOWN STATE
    config_pwm_gpio();
    config_pwm_timer();
    config_nvic();
    start_pwm();
    __enable_interrupt();

    while(1) {
//        if(ULTRASONIC_END_CB & get_scheduled_event()){
//          remove_scheduled_event(ULTRASONIC_END_CB);
//          ultrasonic_calc_distance_cb();
//        }
    }
}
