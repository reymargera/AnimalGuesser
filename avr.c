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