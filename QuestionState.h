/*
 * QuestionState.h
 *
 * Created: 6/3/2015 6:19:59 PM
 *  Author: Javier Vega
 */ 


#ifndef QUESTIONSTATE_H_
#define QUESTIONSTATE_H_

#include "avr.h"
#include "lcd.h"

const char* questionBank[] = {"Have 4 legs?", "Walk on land?","Eat only meat", "Have claws?", "Move fast?",
							  "Domesticated?", "Found at a zoo?", "Eaten by people", "A mammal?", "Deadly?"};

bool animalCharacteristics [7][10] = 
{
	{true, true, true, true, true, true, false, false, true, true}, //Doge
	{true, true, true, true, true, true, false, false, true, false}, //Cat
	{true, true, false, false, false, true, false, true, true, false}, //Cow
	{false, false, false, false, true, true, true, true, false, false}, //Fish
	{false, false, false, true, true, true, false, false, false, false}, //Bird
	{true, true, false, true, false, false, true, false, true, true}, //Bear
	{false, true, false, false, false, true, false, true, false, true} //Chicken
};


#endif /* QUESTIONSTATE_H_ */