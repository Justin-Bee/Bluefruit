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
#include "nrf_gpio.h"

/* defines */
#define LEDPIN (17UL)
#define LEDPIN2 (19UL)

/*
  * led_init()
  *
  * This function initializes the led
  */
void led_init(){
  /* setup the gpio for the ledpin (red led) */
  NRF_GPIO->PIN_CNF[LEDPIN] = (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos) |
                                (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos) |
                                (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos) |
                                (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos) |
                                (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos);

  /* setup the gpio for the blue led */
  NRF_GPIO->PIN_CNF[LEDPIN2] = (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos) |
                                (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos) |
                                (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos) |
                                (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos) |
                                (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos);
}

/*
 * led_on_red()
 *
 * This function turns on the led
 *
 */
void led_on_red(){
  /* turn the led on */
  NRF_GPIO->OUTSET = (1UL << LEDPIN);
}

/*
 * led_off()
 *
 * This function turns off the led
 */
void led_off_red(){
  /* turn off the led */
  NRF_GPIO->OUTCLR = (1UL << LEDPIN);
}

/*
 * led_on_red()
 *
 * This function turns on the led
 *
 */
void led_on_blue(){
  /* turn the led on */
  NRF_GPIO->OUTSET = (1UL << LEDPIN2);
}

/*
 * led_off()
 *
 * This function turns off the led
 */
void led_off_blue(){
  /* turn off the led */
  NRF_GPIO->OUTCLR = (1UL << LEDPIN2);
}

/**
 * led_toggle_red()
 *
 * Notes: Uses nrf_gpio_read() to read the status of the pin
 * if the pin is set then turn off the led, else turn on the led
 *
 */
void led_toggle_red(){
  if(nrf_gpio_pin_read(LEDPIN)){ //try this TODO 
    led_off_red();
    }
  else{
    led_on_red();
    }
}

/**
 *led_toggle_blue()
 *
 */
 void led_toggle_blue(){
   if(nrf_gpio_pin_read(LEDPIN2)){
     led_off_blue();
     }
   else{
     led_on_blue();
     }
 }





/*************************** End of file ****************************/