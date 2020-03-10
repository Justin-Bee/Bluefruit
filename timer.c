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
#include "nrf.h"
#include "led.h"
#include "uart.h"

/* definitions */
NRF_TIMER_Type *timer0 = NRF_TIMER0_BASE;

/*
 * timer_init()
 *
 * This function initializes the timer0
 */
void timer_init(){
  // 32-bit timer
  NRF_TIMER0->BITMODE = TIMER_BITMODE_BITMODE_32Bit << TIMER_BITMODE_BITMODE_Pos;

  // 1us timer period
  NRF_TIMER0->PRESCALER = 4 << TIMER_PRESCALER_PRESCALER_Pos;

  // 1000 us compare value, generates EVENTS_COMPARE[0]
  NRF_TIMER0->CC[0] = 10000000;

  // Enable IRQ on EVENTS_COMPARE[0]
  NRF_TIMER0->INTENSET = TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENSET_COMPARE0_Pos;

  // Clear the timer when COMPARE0 event is triggered
  NRF_TIMER0->SHORTS = TIMER_SHORTS_COMPARE0_CLEAR_Enabled << TIMER_SHORTS_COMPARE0_CLEAR_Pos;


  NVIC_EnableIRQ(TIMER0_IRQn);
  NRF_TIMER0->TASKS_START = 1;
}


/* timer interrupt
 *
 */
void TIMER0_IRQHandler(void)
{
  volatile uint32_t dummy;
  if (NRF_TIMER0->EVENTS_COMPARE[0] == 1)
  {
    NRF_TIMER0->EVENTS_COMPARE[0] = 0;
    led_toggle_red();
    uart_writestr("Int!");
    // Read back event register so ensure we have cleared it before exiting IRQ handler.
    dummy = NRF_TIMER0->EVENTS_COMPARE[0];
    dummy; // to get rid of set but not used warning
  }
}

//https://github.com/andenore/NordicSnippets/blob/master/examples/timer/main.c 

/*************************** End of file ****************************/