/*
 * led.h
 *
 * @Author: Justin Bee
 * @Date: 12/15/2019
 *
 * This file contains the function declarations for
 * the led.c class
 */

 #ifndef _LED_H_INCLUDED
 #define _LED_H_INCLUDED

 /* led_init() */
 void led_init();

 /* led_on_red() */
 void led_on_red();

/* led_off_red() */
void led_off_red();

/* led_on_blue() */
void led_on_blue();

/* led_off_blue() */
void led_off_blue();

/* led_blink_red() */
void led_toggle_red();

/* led_blink_blue() */
void led_toggle_blue();

 #endif /* _LED_H */

 
/*************************** End of file ****************************/