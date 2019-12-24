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
 #include <string.h>

/* variable for the uart enum referenced in nrf52.h */
//NRF_UARTE_Type * myUart = 0x40002000; 
NRF_UART_Type * uart = 0x40002000;



/* definitions */
#define UARTRX (8UL) //8 or 29
#define UARTTX (6UL)  //6 or 31
#define UARTCTS (7UL)  //7 or 28
#define UARTRTS (5UL)  //5 or 30

 /*
  * uart_init()
  *
  * This function initializes the uart
  */
 void uart_init(){

    /* to enable the UART need to disable other porcesses with same ID - Instantiation Table pg 24. */
    uart->ENABLE = 0;
    /* enable the UART by setting 4 to enable*/
    uart->ENABLE = 4;

    uart->SHORTS = 0;
    uart->INTENSET = 0;
    uart->INTENCLR = 0;
    /* set the pinselect to the uart pin */
    uart->PSELTXD = UARTTX;
    uart->PSELRXD = UARTRX;
    uart->PSELCTS = UARTCTS;
    uart->PSELRTS = UARTRTS;
    /* config the parity */
    uart->CONFIG = 0;
    /* set the baudrate to 115200 */
   // uart->BAUDRATE = 0x01D7E000UL;
    uart->BAUDRATE = 0x00275000UL; //9600 baud 
 }

/*
 * uart_writestr()
 * 
 * This function prints a str to uart 
 */
void uart_writechar(char str){
    //while(!uart->EVENTS_CTS){}
    uart->TASKS_STARTTX=1;
    uart->TXD = str; 
    while(!uart->EVENTS_TXDRDY){}
   // while(!uart->EVENTS_CTS){}

}

/*
 * uart_writestr()
 *
 * This function takes a string and iterates through
 * it char by char calling uart_writechar() to write the chars 
 */
 void uart_writestr(char * str){
    
    
    /* get the length of the string entered */
    int length= strlen(str);
  
    /* iterate through the chars */
    for(int i=0; i<length; i++){
      uart_writechar(str[i]); 
    }
    /* stop the transmission */
    uart->TASKS_STOPTX;
 }


 /*
  * uart_getstr()
  *
  * this function gets the str from the uart 
  */
 unsigned char * uart_getstr(){
    unsigned char * msg;
    uart->TASKS_STARTRX;
    msg = uart->RXD;
    return msg;

 }
