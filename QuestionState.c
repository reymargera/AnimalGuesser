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
    bool animalTraits[][];
    
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
            pos_lcd(0,0);
            sprintf(buffer, "Is your animal . . .");
            puts_lcd2(buffer);
            
            pos_lcd(1,0);
            sprintf(buffer, questionBank[i]);
            puts_lcd2(buffer);
            
            // If button(#1) pressed (Yes)
            if(buttonPressed(0,4)) {
                // apend true to the animalTrait[][]
                
            }
            else
            {
                // append false to the animalTrait[][]
            }
        }
        
        // If button(#1) pressed (Yes)
        if(buttonPressed(0,4)) {
            // apend true to the animalTrait[][]
            
        }
        else
        {
            // append false to the animalTrait[][]
        }
    }

}