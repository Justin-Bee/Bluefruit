/*
 * bluetooth.c
 * 
 * @Author: Justin Bee
 * @Date: 1/26/2020
 *
 * This file contains all of the bluetooth functions
 */

/* includes */
#include "bluetooth.h"
#include "nrf52.h"

/* defines */
NRF_RADIO_Type * radio = 0x40001000;

/*
 * bluetooth_init()
 *
 * Intitialize the bluetooth
 */
void bluetooth_init(){
    /* start the radio */
    radio->TASKS_START = 1;
    /* enable TX */
    radio->TASKS_TXEN = 1;
   

}










/*************************** End of file ****************************/