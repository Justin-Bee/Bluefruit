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

/* variable for the uart enum referenced in nrf52.h */
 NRF_UARTE_Type * myUart; 
 NRF_UART_Type * uart;

 /*
  * uart_init()
  *
  * This function initializes the uart
  */
 void uart_init(){
    
 
    /* to enable the UART need to disable other porcesses with same ID - Instantiation Table pg 24. */
    uart->ENABLE = 0;
    /* enable the uart by setting 4 to register */
    myUart->ENABLE |= 8;
    /* set the baudrate to 115200 */
    myUart->BAUDRATE |= 0x01D6000;


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
