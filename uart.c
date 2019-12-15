/*
 * uart.c
 * 
 * @Author: Justin Bee
 * @Date: 12/15/2019
 *
 */

 #include uart.h

 /* defines */
  #define ENABLE (*(volatile char *) 0x500)
  #define BAUDRATE (*(volatile char *) 0x524)

 /*
  * uart_init()
  *
  * This function initializes the uart
  */
 void uart_init(){
    /* enable the uart by setting 4 to register */
    ENABLE |= 0x04;
    /* set the baudrate to 115200 */
    BAUDRATE |= 0x01D7E000;


 }

/*
 * uart_writestr()
 * 
 * This function prints a str to uart 
 */
void uart_writestr(char * str){

}
