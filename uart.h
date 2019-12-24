/*
 * uart.h
 *
 * @Author: Justin Bee
 * @Date: 12/15/2019
 *
 * This file contains the function declarations for
 * the uart.c class
 */

 #ifndef _UART_H
 #define _UART_H

 /* uart_init() */
 void uart_init();

 /* uart_writechar() */
 void uart_writechar(char str);

 /* uart_writestr() */
 void uart_writestr(char * str);

 #endif /* _UART_H */

