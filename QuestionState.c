//
//  QuestionState.c
//  
//
//  Created by Kay Lab on 6/3/15.
//
//

#include "QuestionState.h"


void askAQuestion() {
    int numberOfQuestions = questionBank.sizeof();
    bool animalTraits[10];
    
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
    for (int i=0; i<x; i++) {
        int count = 0;
        for(int j=0; j<y; j++)
        {
            if(thisAnimalTraits[0][j] == animalCharactertistics[i][j])
            {
                count++;
            }
        }
        if(count > max)
        {
            pos = i;
        }
    }
    
    
    clr_lcd()
    
    pos_lcd(0,0);
    sprintf(buffer, "Your animal is . . .");
    puts_lcd2(buffer);
    
    pos_lcd(1,0);
    sprintf(buffer, animal[pos]);
    puts_lcd2(buffer);
    
    // YES - correct answer done
    if(buttonPressed(0,4))
    {
        clr_lcd()
        
        pos_lcd(0,0);
        sprintf(buffer, "Play again?");
        puts_lcd2(buffer);
    }
    // NO - wrong answer append the trait into an array
    if(buttonPressed(1,4))
    {
        for (int i=x-1; i<x; i++) {
            for(int j=0; j<y; j++)
            {
                // APPEND THE NEW ANIMAL TRAIT TO THE CHARACTERISTICS
            }
        }
    }

}