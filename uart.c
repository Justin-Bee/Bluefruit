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

/* variables */
int received =0;
 /*
  * uart_init()
  *
  * This function initializes the uart
  */
 void uart_init(){
    /* set the pinselect to the uart pin */
    uart->PSELTXD = UARTTX;
    uart->PSELRXD = UARTRX;
    uart->PSELCTS = UARTCTS;
    uart->PSELRTS = UARTRTS;

    /* to enable the UART need to disable other porcesses with same ID - Instantiation Table pg 24. */
   // uart->ENABLE = 0;
    /* enable the UART by setting 4 to enable*/
    uart->ENABLE = 4;
    uart->SHORTS = 0;
    uart->INTENSET = 0;
    uart->INTENCLR = 0;
    /* config the parity */
   // uart->CONFIG = 0x07;
    /* set the baudrate to 115200 */
    uart->BAUDRATE = 0x01D7E000UL;
 
 }

/*
 * uart_writestr()
 * 
 * This function prints a str to uart 
 */
void uart_writechar(char str){
    /* start the transmission sequence */
    uart->TASKS_STARTTX=1;
    /* write the character to the TDX */
    uart->TXD = str; 
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
    for(int i=0; i<=length; i++){
      /* write the current character */
      uart_writechar(str[i]); 
      /* wait for the rdy signal */
      while(!uart->EVENTS_TXDRDY){}
      /* added delay for uart(wouldn't work without it */
      unsigned long tmo = 1000000;
      while(tmo >0){
      tmo--;
      }
      /* stop the transmission */
      uart->TASKS_STOPTX=1;
    }
 }


 /*
  * uart_getstr()
  *
  * this function gets the str from the uart 
  */
 unsigned char * uart_getstr(){
    /* buffer for the message */
    unsigned char * msg;
    /* trigger the receive message event */
    uart->TASKS_STARTRX=1;
    /* variable to increment */
    int i=0;

    uart->EVENTS_RXDRDY = 1;
    while(!uart->EVENTS_RXDRDY){}
    /* store the first byte in the msg variable */
    msg = "test";
   

    /* set received to 1 */
    received = 1;
    /* return the message */
    return msg;

 }


/*
 * uart_msgReceived()
 *
 * Returns: 1 if msg received 0 otherwise
 */
 int uart_msgReceived(){
   /* check the status of the msg received variable */
   if(received){
      received = 0;
      return 1;
   }
   else{
      return received;
   }
 }