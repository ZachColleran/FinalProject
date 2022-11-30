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

    stop_pwm(); //KNOWN STATE
    config_pwm_gpio();
    config_pwm_timer();
    config_button_gpio();
    start_pwm();

    uint16_t average = 0;
    uint16_t total = 0;
    uint16_t buttons_pressed = 0;

    while(1) {

        if(P4->IN & BIT0 == BIT0) {
            buttons_pressed++;
            average = ((total + TICKS_1) / buttons_pressed);
            config_pwm_ticks_a0(average);
        }
        else {
            buttons_pressed--;
            average = (total - TICKS_1) / buttons_pressed;
            config_pwm_ticks_a0(average);
        }

        if(P4->IN & BIT2 == BIT2) {
            buttons_pressed++;
            average = (total + TICKS_2) / buttons_pressed;
            config_pwm_ticks_a0(average);
        }
        else {
            buttons_pressed--;
            average = (total - TICKS_2) / buttons_pressed;
            config_pwm_ticks_a0(average);
        }

        if(P4->IN & BIT4 == BIT4) {
            buttons_pressed++;
            average = (total + TICKS_3) / buttons_pressed;
            config_pwm_ticks_a0(average);
        }
        else {
            buttons_pressed--;
            average = (total - TICKS_3) / buttons_pressed;
            config_pwm_ticks_a0(average);
        }

        if(P4->IN & BIT5 == BIT5) {
            buttons_pressed++;
            average = (total + TICKS_4) / buttons_pressed;
            config_pwm_ticks_a0(average);
        }
        else {
            buttons_pressed--;
            average = (total - TICKS_4) / buttons_pressed;
            config_pwm_ticks_a0(average);
        }

        if(P4->IN & BIT7 == BIT7) {
            buttons_pressed++;
            average = (total + TICKS_5) / buttons_pressed;
            config_pwm_ticks_a0(average);
        }
        else {
            buttons_pressed--;
            average = (total - TICKS_5) / buttons_pressed;
            config_pwm_ticks_a0(average);
        }
    }
}
