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

/* variable for the uart enum referenced in nrf52.h */
 NRF_UARTE_Type * myUart; 
 NRF_UART_Type * uart;

/* definitions */
#define UARTRX 8 //8 or 29
#define UARTTX 6  //6 or 31
#define UARTCTS 7  //7 or 28
#define UARTRTS 5  //5 or 30

 /*
  * uart_init()
  *
  * This function initializes the uart
  */
 void uart_init(){
    /* set the pinselect to the uart pin */
    myUart->PSEL.TXD = UARTTX;
    myUart->PSEL.RXD = UARTRX;
    myUart->PSEL.CTS = UARTCTS;
    myUart->PSEL.RTS = UARTRTS;
    /* to enable the UART need to disable other porcesses with same ID - Instantiation Table pg 24. */
    uart->ENABLE = 0;
    /* enable the uart by setting 8 to register */
    myUart->ENABLE |= 0x08;
    /* set the baudrate to 115200 */
    myUart->BAUDRATE |= 0x01D60000;


 }

/*
 * uart_writestr()
 * 
 * This function prints a str to uart 
 */
void uart_writestr(char * str){
    /* write the intial address pointer to TXD.PTR */
    myUart->TXD.PTR = *str;
    /* and the number of bytes in the RAM buffer to TXD.MAXCNT */
    myUart->TXD.MAXCNT = sizeof(str);
    /* tranmission is started by triggering the STARTTX task */
    myUart->TASKS_STARTTX = 1;
    /* bytes are transmitted by writing to the TXD register */

    /*  */

}
