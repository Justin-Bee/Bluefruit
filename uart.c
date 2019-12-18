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


 /*
  * uart_init()
  *
  * This function initializes the uart
  */
 void uart_init(){
    
    /* variable for the uart enum referenced in nrf52.h */
    NRF_UARTE_Type * myUart; 
    /* to enable the UART need to disable other porcesses with same ID - Instantiation Table pg 24. */

    /* enable the uart by setting 4 to register */
    myUart->ENABLE |= 0x04;
    /* set the baudrate to 115200 */
    myUart->BAUDRATE |= 0x01D7E000;


 }

/*
 * uart_writestr()
 * 
 * This function prints a str to uart 
 */
void uart_writestr(char * str){
    /* tranmission is started by triggering the STARTTX task */

    /* bytes are transmitted by writing to the TXD register */

    /*  */

}
