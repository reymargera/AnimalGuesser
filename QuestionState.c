//
//  QuestionState.c
//  
//
//  Created by Chia Huang on 6/3/15.
//
//

#include "QuestionState.h"


void askQuestions() {
    int numberOfQuestions = 10;
    bool thisAnimalTraits[10];
    
    for(int i=0; i < numberOfQuestions; i++)
    {
		clr_lcd();
        pos_lcd(0,0);
        sprintf(buffer, "Does your animal");
        puts_lcd2(buffer);
        
        pos_lcd(1,0);
        sprintf(buffer, questionBank[i]);
        puts_lcd2(buffer);
        
        // Question 5 so forth . . .
        if(i>=5)
        {
            clr_lcd();
            pos_lcd(0,0);
            sprintf(buffer, "Is your animal");
            puts_lcd2(buffer);
            
            pos_lcd(1,0);
            sprintf(buffer, questionBank[i]);
            puts_lcd2(buffer);
            
            while(true) {
                // If button(#1) pressed (Yes)
                if(buttonPressed(0,4)) {
                    // apend true to the animalTrait[]
                    thisAnimalTraits[i] = true;
					wait_avr(1000);
                    break;
                }
                if(buttonPressed(1,4))
                {
                    // append false to the animalTrait[]
                    thisAnimalTraits[i] = false;
					wait_avr(1000);
                    break;
                }
            }
        }
        else
        {
            while(true) {
                // If button(#1) pressed (Yes)
                if(buttonPressed(0,4)) {
                    // apend true to the animalTrait[]
                    thisAnimalTraits[i] = true;
					wait_avr(1000);
                    break;
                }
                if(buttonPressed(1,4))
                {
                    // append false to the animalTrait[]
                    thisAnimalTraits[i] = false;
					wait_avr(1000);
                    break;
                }
            }
        }
    }
    int max = 0;
    int pos = 0;
    for (int i=0; i<7; i++) {
        int count = 0;
        for(int j=0; j<10; j++)
        {
            if(thisAnimalTraits[j] == animalCharacteristics[i][j])
            {
                count++;
            }
        }
        if(count > max)
        {
			max = count;
            pos = i;
        }
    }
    
    
    clr_lcd();
    
    pos_lcd(0,0);
    sprintf(buffer, "Your animal is a");
    puts_lcd2(buffer);
    
    pos_lcd(1,0);
    sprintf(buffer, animal[pos]);
    puts_lcd2(buffer);
    
	while(true)
	{
		// YES - correct answer done
		if(buttonPressed(0,4))
		{
			clr_lcd();
			pos_lcd(0,0);
			sprintf(buffer, "I knew I was");
			puts_lcd2(buffer);
			pos_lcd(1,0);
			sprintf(buffer, "smarter than you");
			puts_lcd2(buffer);
			wait_avr(2000);
			clr_lcd();
			pos_lcd(0,0);
			sprintf(buffer, "Lets play again");
			puts_lcd2(buffer);
			wait_avr(2000);
			break;
		}
	
		// NO - wrong answer append the trait into an array
		if(buttonPressed(1,4))
		{
			clr_lcd();
			pos_lcd(0,0);
			sprintf(buffer, "What was it?");
			puts_lcd2(buffer);
			
			wait_avr(500);
			char typing = 1;
			unsigned char button, letterWanted = 0;
			unsigned char column = 0;
			unsigned char times = 0;
			char letter;
			char newAnimal[20] = "";
			wait_avr(500);
			while (typing)
			{				
				
				//Waits for input
				while(button == 0)
				{
					button = scanKeypad();
				}
				
				wait_avr(500);
				
				//If "A" (enter) is pressed it stops
				if(button == 4)
				{
					typing = 0;
					wait_avr(1000);
					continue;
				}
				
				sprintf(buffer, "-");
				pos_lcd(1,column);
				puts_lcd2(buffer);
				wait_avr(1500);
				
				while (letterWanted == 0)
				{
					letterWanted = scanKeypad();
				}
				
				wait_avr(1500);
				
				if (letterWanted == 8)
					times = 1;
				else if (letterWanted == 12)
					times = 2;
				else if (letterWanted == 16)
					times = 3;			
										
				//Gets the letter corresponding to the button press
				letter = decodeButton(button,times);
				newAnimal[column] = letter;
				clr_lcd();
				pos_lcd(0,0);
				sprintf(buffer, "What was it?");
				puts_lcd2(buffer);
				
				pos_lcd(1,0);
				sprintf(buffer, newAnimal);
				puts_lcd2(buffer);
				
				letterWanted = 0;
				button = 0;
				column++;
			}
			
			clr_lcd();
			pos_lcd(0,0);
			sprintf(buffer, "Thanks I'll");
			puts_lcd2(buffer);
			pos_lcd(1,0);
			sprintf(buffer, "remember that");
			puts_lcd2(buffer);
			
			//Adds new animal traits to saved animals
			for(int i = 0; i < 10; i++)
				animalCharacteristics[7][i] = thisAnimalTraits[i];
			
			animal[7] = newAnimal;
			sprintf(buffer, animal[7]);
			clr_lcd();
			pos_lcd(0,0);
			puts_lcd2(buffer);
			typing = 0;
			break;
			
		}
		
	}
}