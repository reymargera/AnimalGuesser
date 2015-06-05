/*
 * FinalProject.c
 *
 * Created: 6/3/2015 3:27:05 PM
 *  Author: Javier Vega
 */ 


#include <avr/io.h>
#include "avr.h"
#include "lcd.h"
#include "GameIntro.h"
#include "QuestionState.h"
 
int main(void)
{
	ini_avr();
	ini_lcd();
	//Variable to hold the state of the program, initialized to initial state
	unsigned char currentState = 0;
    while(1)
    {
		switch (currentState)
		{
			//Initial State
			case 0:
				gameIntro();
				currentState++;
				break;
			
			//Question Asking State
			case 1:
				askQuestions();
				break;
				
			default:
				gameIntro();
		}     
    }
}