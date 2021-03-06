/*
 * Main.c
 *
 *  Created on: Oct 15, 2021
 *      Author: 20128
 */

#include"std_types.h"
#include"lcd.h"
#include"Ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */

int main()
{
	uint16 distance;
	SREG |= (1<<7);	/* Enable Global Interrupt I-Bit */
	LCD_init();/*Enable LCD driver*/


	while(1)
	{
		Ultrasonic_init();/*Enable Ultrasonic driver*/
		LCD_moveCursor(0,0);
		LCD_displayString("The distance is   ");
		LCD_moveCursor(1,0);
		distance=Ultrasonic_readDistance();
		LCD_intgerToString(distance);
		LCD_displayString(" CM ");
	}


}
