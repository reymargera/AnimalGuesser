#include "avr.h"

void
ini_avr(void)
{
  WDTCR = 15;
}

void
wait_avr(unsigned short msec)
{
  TCCR0 = 3;
  while (msec--) {
    TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001);
    SET_BIT(TIFR, TOV0);
    WDR();
    while (!GET_BIT(TIFR, TOV0));
  }
  TCCR0 = 0;
}

//Detects button pressed on the keypad based on row/column
unsigned char buttonPressed(unsigned char row, unsigned char column)
{
	DDRC   = 0;
	DDRC  |= (1 << row);
	PORTC |= (1 << column);
	
	//Wait for read and oscillating button 
	wait_avr(5);
	
	return ((PINC & (1 << column)) == 0 ? 1:0);
}

//Scans the entire keyboard to check which buttons are being pressed
unsigned char scanKeypad()
{
	unsigned char row,col;
	for(row=0;row<4;row++)
	{
		for(col=4;col<8;col++)
		{
			if(buttonPressed(row,col))
			{
				return (row*4) + (col-4) + 1;
			}
		}
	}
	return 0;
}

//Returns letters corresponding to 
char decodeButton(unsigned char button, unsigned char times)
{
	switch (button)
	{
		case 2:
			if (times == 1)
				return 'a';
			else if (times == 2)
				return 'b';
			else
				return 'c';
				
		case 3:
			if (times == 1)
				return 'd';
			else if (times == 2)
				return 'e';
			else
				return 'f';
		
		case 5:
			if (times == 1)
				return 'g';
			else if (times == 2)
				return 'h';
			else
				return 'i';
				
		case 6:
			if (times == 1)
				return 'j';
			else if (times == 2)
				return 'k';
			else
				return 'l';
				
		case 7:
			if (times == 1)
				return 'm';
			else if (times == 2)
				return 'n';
			else
				return 'o';
		
		case 9:
			if (times == 1)
				return 'p';
			else if (times == 2)
				return 'r';
			else
				return 's';
				
		case 10:
			if (times == 1)
				return 't';
			else if (times == 2)
				return 'u';
			else
				return 'v';
		
		case 11:
			if (times == 1)
				return 'w';
			else if (times == 2)
				return 'x';
			else
				return 'y';
		
		case 14:
			return 'z';
		
		default: 
			return 0;
	}
}