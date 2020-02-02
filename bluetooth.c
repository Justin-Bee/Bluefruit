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
    /* power to the peripheral */
    radio->POWER=1;
    /* start the radio */
    radio->TASKS_START = 1;
    /* enable TX */
    radio->TASKS_TXEN = 1;

    /* the packet */
    uint32_t * pack = 0x020106110707b9f9d750a420897740cbfd2cc1804809084247d3131312053;
    

    /* the packet pointer */
    radio->PACKETPTR = pack;
    /* send a packet */
   

}










/*************************** End of file ****************************/