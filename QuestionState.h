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

#include <stdbool.h>

char buffer[20];
static char *questionBank = {"Have 4 legs?", "Walk on land?","Eat only meat", "Have claws?", "Move fast?", "Domesticated?", "Found at a zoo?", "Eaten by people", "A mammal?", "Deadly?"};
static char *animal = {"Dog", "Cat", "Cow", "Fish", "Bird", "Bear", "Chicken"};
static bool animalCharacteristics[8][10]  =
{
	{true, true, true, true, true, true, false, false, true, true}, //Doge
	{true, true, true, true, true, true, false, false, true, false}, //Cat
	{true, true, false, false, false, true, false, true, true, false}, //Cow
	{false, false, false, false, true, true, true, true, false, false}, //Fish
	{false, false, false, true, true, true, false, false, false, false}, //Bird
	{true, true, false, true, false, false, true, false, true, true}, //Bear
	{false, true, false, false, false, true, false, true, false, true}, //Chicken
	{} //Blank for new animal
};


void askQuestions();

#endif /* QUESTIONSTATE_H_ */