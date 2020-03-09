/*
 * timer.c
 *
 * Author: Justin Bee
 * Date: 3.2.2020
 *
 * This class initializes the timer interrupt
 */

/* includes */
#include "timer.h"
#include "nrf52.h"
#include "led.h"

/* definitions */
NRF_TIMER_Type *timer0 = NRF_TIMER0_BASE;

/*
 * timer_init()
 *
 * This function initializes the timer0
 */
void timer_init(){
  /* enable the interrupt */
  timer0->INTENSET = 0x10;
  /* start the timer */


}


/* timer interrupt
 *
 */
void timerInterrupt() __attribute__((interrupt (*IRQ*));

void timerInterrupt(void){
  
  /* toggle the led */
  led_toggle_red();
  /* reset the timer */
}