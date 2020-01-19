/*
 * config.c
 * 
 * @Author: Justin Bee
 * @Date: 1/12/2019
 *
 */

 /* includes */
 #include <string.h>
 #include "config.h"

/*
 * config_init()
 *
 * Initializes the config struct
 */
 void config_init(){
   char * name = "Author: Justin Bee";
   char * device = "Device: nrf52832";
   char * version = "1.00.01";           
   // def.name = *name;
   strcpy(def.name, name);
   strcpy(def.device, device);
   strcpy(def.version, version);
 }

 
/*************************** End of file ****************************/