#include "msp.h"
#include "scheduler.h"
#include "pwm.h"
#include "gpio.h"
#include <stdbool.h>
/**
 * main.c
 */


void main(void)
{

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

    stop_pwm(); //KNOWN STATE
    config_pwm_gpio(); // timer output pin config at pin 2.4
    config_pwm_timer(); // config timer A0
    config_button_gpio(); // config input pin from external buttons
    start_pwm(); // start timer

    uint16_t average = 0;
    uint16_t total = 0;

    bool button_1 = false;
    bool button_2 = false;
    bool button_3 = false;
    bool button_4 = false;
    bool button_5 = false;

    /* would like to use interrupts but since there is no interrupt mode
     * that reacts to both rising and falling edge on an input we decided not to use them
     */
    while(1) {

        if(P4->IN & BIT0 == BIT0)
            button_1 = true;
        else
            button_1 = false;

        if(P4->IN & BIT2 == BIT2)
            button_2 = true;
        else
            button_2 = false;

        if(P4->IN & BIT4 == BIT4)
            button_3 = true;
        else
            button_3 = false;

        if(P4->IN & BIT5 == BIT5)
            button_4 = true;
        else
            button_4 = false;

        if(P4->IN & BIT7 == BIT7)
            button_5 = true;
        else
            button_5 = false;

        total = ((TICKS_5*button_5) + (TICKS_4*button_4) + (TICKS_3*button_3) + (TICKS_2*button_2) + (TICKS_1*button_1));
        average = total / (button_1 + button_2 + button_3 + button_4 + button_5);
        config_pwm_ticks_a0(average);

    }
}
