/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*            (c) 2014 - 2019 SEGGER Microcontroller GmbH             *
*                                                                    *
*           www.segger.com     Support: support@segger.com           *
*                                                                    *
**********************************************************************
*                                                                    *
* All rights reserved.                                               *
*                                                                    *
* Redistribution and use in source and binary forms, with or         *
* without modification, are permitted provided that the following    *
* conditions are met:                                                *
*                                                                    *
* - Redistributions of source code must retain the above copyright   *
*   notice, this list of conditions and the following disclaimer.    *
*                                                                    *
* - Neither the name of SEGGER Microcontroller GmbH                  *
*   nor the names of its contributors may be used to endorse or      *
*   promote products derived from this software without specific     *
*   prior written permission.                                        *
*                                                                    *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND             *
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,        *
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF           *
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE           *
* DISCLAIMED.                                                        *
* IN NO EVENT SHALL SEGGER Microcontroller GmbH BE LIABLE FOR        *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR           *
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  *
* OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;    *
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF      *
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT          *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  *
* USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
* DAMAGE.                                                            *
*                                                                    *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "uart.h"
#include "led.h"
#include "clock.h"
#include "bluetooth.h"
#include "timer.h"
#include "nrf.h"


/* external varaibles */
struct config_struct def;
/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/
int main(void) {
  /* initialize the clock */
  clock_init();
  /* initialize the uart */
  uart_init();
  /* initialize the led */
  led_init();
  /* initialize the config */
  config_init();
  /* initialize the bluetooth radio */
  bluetooth_init();
  /* initiailze the timer */
  timer_init();
  /* for simple timer*/
  long volatile tmo;
  
  /* test message */
  unsigned char * msg = "Justin Bee\r\n";
  
  /* banner message */
  uart_writestr(def.name);
  uart_writestr("\r\n");
  uart_writestr(def.device);
  uart_writestr("\r\n");
  uart_writestr(def.version);
  uart_writestr("\r\n");  /*todo maybe write a function that handles this logic */
  /* endless loop */
  while (1){
    __WFE();
    /* need to add interrupt */
   // msg = uart_getstr();

    /* if the msg has been received */
   // if(uart_msgReceived()){
    //  uart_writestr("you entered: ");
    //  uart_writestr(msg);
   // }

  }
}

/*************************** End of file ****************************/
