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

int main(void)
{
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
				
			//Guess Animal 
			case 2:
				guess();
				break;
			
			//Correct Answer State
			case 3:
				correctAnswer();
				break;
			
			//Wrong Answer State
			case 4:
				wrongAnswer();
				break;
			
			default:
				gameIntro();
		}     
    }
}