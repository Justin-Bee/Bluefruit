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


 /* config struct */
struct config_struct{
    char name[20];
    char device[20];
    char version[7];
};

extern struct config_struct def;

/* config_init() */
void config_init();


#endif