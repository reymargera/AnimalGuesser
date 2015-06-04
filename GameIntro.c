/*
 * CFile1.c
 *
 * Created: 6/3/2015 4:36:52 PM
 *  Author: Javier Vega
 */ 

#include "GameIntro.h"

//Prints game title to the LCD
void printTitleScreen()
{
	pos_lcd(0,0);
	sprintf(buffer, "10 Question");
	puts_lcd2(buffer);
	
	sprintf(buffer, "A to Start");
	pos_lcd(1,0);
	puts_lcd2(buffer);
}

void printInstructions()
{
	pos_lcd(0,0);
	sprintf(buffer, "Think of an Animal");
	puts_lcd2(buffer);
	
	pos_lcd(1,0);
	sprintf(buffer, "I will ask you");
	puts_lcd2(buffer);
	wait_avr(500);
	
	clr_lcd();
	pos_lcd(0,0);
	puts_lcd2(buffer);
	
	pos_lcd(1,0);
	sprintf(buffer, "10 question");
	puts_lcd2(buffer);
	wait_avr(500);
	
	clr_lcd();
	pos_lcd(0,0);
	puts_lcd2(buffer);
	
	pos_lcd(1,0);
	sprintf(buffer, "And I will");
	puts_lcd2(buffer);
	wait_avr(500);
	
	clr_lcd();
	pos_lcd(0,0);
	puts_lcd2(buffer);
	
	pos_lcd(1,0);
	sprintf(buffer, "Guess it");
	puts_lcd2(buffer);
	wait_avr(500);
	
	clr_lcd();
	pos_lcd(0,0);
	sprintf(buffer,"Press A when");
	puts_lcd2(buffer);
	
	pos_lcd(1,0);
	sprintf(buffer,"You're ready");
	puts_lcd2(buffer);	
}

void gameIntro() 
{
	printTitleScreen();
	
	//Wait for player to press A to start
	while(!buttonPressed(0,7));
	
	//Loop through instruction until A pressed
	while(!buttonPressed(0,7))
	{
		printInstructions();
		wait_avr(100);
	}
}