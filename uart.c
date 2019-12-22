/*
 * uart.c
 * 
 * @Author: Justin Bee
 * @Date: 12/15/2019
 *
 */

/* includes */
 #include "uart.h"
 #include "nrf52.h"
 #include "nrf.h"
 #include <stdio.h>

/* variable for the uart enum referenced in nrf52.h */
NRF_UARTE_Type * myUart = 0x40002000; 
NRF_UART_Type * uart = 0x40002000;



/* definitions */
#define UARTRX 8UL //8 or 29
#define UARTTX 6UL  //6 or 31
#define UARTCTS 7UL  //7 or 28
#define UARTRTS 5UL  //5 or 30

 /*
  * uart_init()
  *
  * This function initializes the uart
  */
 void uart_init(){

    /* to enable the UART need to disable other porcesses with same ID - Instantiation Table pg 24. */
    myUart->ENABLE = 0;
    /* enable the UART by setting 4 to enable*/
    uart->ENABLE = 4;
    /* set the pinselect to the uart pin */
    uart->PSELTXD = UARTTX;
    uart->PSELRXD = UARTRX;
    uart->PSELCTS = UARTCTS;
    uart->PSELRTS = UARTRTS;
    /* config the parity */
    uart->CONFIG = 0;
    /* set the baudrate to 115200 */
    uart->BAUDRATE = 0x01D7E000;


 }

/*
 * uart_writestr()
 * 
 * This function prints a str to uart 
 */
void uart_writechar(char str){

    uart->TASKS_STARTTX=1;
    if(uart->EVENTS_CTS){
      uart->TXD = str;
    }
    
}
