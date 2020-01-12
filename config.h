/*
 * config.h
 *
 * @Author: Justin Bee
 * @Date: 12/31/2019
 *
 * This file contains the function declarations for
 * the config.c class
 */

#ifndef _CONFIG_H_INCLUDED
#define _CONFIG_H_INCLUDED

/*define the banner message params */
//variable declarations can cause multiple definition errors
struct config_struct{
    char name[20];
    char device[20];
}def = {"Author: Justin Bee", "Device: nrf52832"};



#endif