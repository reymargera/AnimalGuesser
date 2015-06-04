/*
 * GameIntro.h
 *
 * Created: 6/3/2015 5:55:08 PM
 *  Author: Javier Vega
 */ 


#ifndef GAMEINTRO_H_
#define GAMEINTRO_H_

#include "lcd.h"
#include "avr.h"
char buffer[20];

void printTitleScreen();
void printInstructions();
void gameIntro();




#endif /* GAMEINTRO_H_ */