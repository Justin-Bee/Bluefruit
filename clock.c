/*
 * clock.c
 * 
 * @Author: Justin Bee
 * @Date: 12/25/2019
 *
 */

/* includes */
#include "clock.h"
#include "nrf52.h"

/* clock struct */
NRF_CLOCK_Type * CLOCK = 0x40000000;

/*
 * clock_init()
 *
 * Intitialize the clock
 */
 void clock_init(){
    
    /* start the clock */
    CLOCK->TASKS_HFCLKSTART = 1;

 }


 
/*************************** End of file ****************************/