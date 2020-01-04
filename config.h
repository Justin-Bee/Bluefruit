/*
 * config.h
 *
 * @Author: Justin Bee
 * @Date: 12/31/2019
 *
 * This file contains the function declarations for
 * the config.c class
 */

 #ifndef _CONFIG_H
 #define _CONFIG_H

/* the config struct */
typedef struct{
  char[5] name;
    

}config_struct;

/* public struct */
config_struct config;

/* initialize the struct */
void config_init();




 #endif //_CONFIG_H