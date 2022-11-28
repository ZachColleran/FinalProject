#include "msp.h"
#include "scheduler.h"
#include "ultrasonic.h"
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
//    timer_a_0_init_trig(); // Timer A0 for trigger pulse
//    timer_a_2_init_measure_echo_cci(); // Timer A2 for echo timing
    //ultrasonic_test_calc_distance_cm();

    config_nvic();

    //todo config gpio
    start_pwm();
    __enable_interrupt();

    while(1) {
//        if(ULTRASONIC_END_CB & get_scheduled_event()){
//          remove_scheduled_event(ULTRASONIC_END_CB);
//          ultrasonic_calc_distance_cb();
//        }
    }
}
