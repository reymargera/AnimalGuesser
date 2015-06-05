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
        pos_lcd(0,0);
        sprintf(buffer, "Does your animal . . .");
        puts_lcd2(buffer);
        
        pos_lcd(1,0);
        sprintf(buffer, questionBank[i]);
        puts_lcd2(buffer);
        
        // Question 5 so forth . . .
        if(i>=5)
        {
            clr_lcd();
            pos_lcd(0,0);
            sprintf(buffer, "Is your animal . . .");
            puts_lcd2(buffer);
            
            pos_lcd(1,0);
            sprintf(buffer, questionBank[i]);
            puts_lcd2(buffer);
            
            while(true) {
                // If button(#1) pressed (Yes)
                if(buttonPressed(0,4)) {
                    // apend true to the animalTrait[]
                    thisAnimalTraits[i] = true;
                    break;
                }
                if(buttonPressed(1,4))
                {
                    // append false to the animalTrait[]
                    thisAnimalTraits[i] = false;
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
                    break;
                }
                if(buttonPressed(1,4))
                {
                    // append false to the animalTrait[]
                    thisAnimalTraits[i] = false;
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
    sprintf(buffer, "Your animal is . . .");
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
			sprintf(buffer, "Play again?");
			puts_lcd2(buffer);
			break;
		}
	
		// NO - wrong answer append the trait into an array
		if(buttonPressed(1,4))
		{
			clr_lcd();
			pos_lcd(0,0);
			sprintf(buffer, "What was it?");
			puts_lcd2(buffer);
			
			pos_lcd(1,0);
			//Add function to allow typing
		}
	}
}