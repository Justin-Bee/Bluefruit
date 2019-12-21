/*
 * led.c
 * 
 * @Author: Justin Bee
 * @Date: 12/21/2019
 *
 */

 /* includes */
#include "led.h"
#include "nrf.h"

/* defines */
#define LEDPIN (17UL)

/*
  * led_init()
  *
  * This function initializes the led
  */
void led_init(){
  /* setup the gpio for the ledpin */
  NRF_GPIO->PIN_CNF[LEDPIN] = (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos) |
                                (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos) |
                                (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos) |
                                (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos) |
                                (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos);
}

/*
 * led_on()
 *
 * This function turns on the led
 *
 */
void led_on(){
  /* turn the led on */
  NRF_GPIO->OUTSET = (1UL << LEDPIN);
}

/*
 * led_off()
 *
 * This function turns off the led
 */
void led_off(){
  /* turn off the led */
  NRF_GPIO->OUTCLR = (1UL << LEDPIN);
}