#include "Memory_Map.h"
#include "DIO.h"
#include "EXT_Interrupt.h"
#include "ADC.h"
#include "LCD.h"

/*defining the pins for joystick*/
#define X_DIR         PinA0
#define Y_DIR         PinA1
#define JOYSTICK_SW   PinD6

#define X_Channel     Ch_0
#define Y_Channel     Ch_1


int main()
{
	u16 Joystick_X, Joystick_Y;

	// init the total GPIO pins
	DIO_Initialization();
	// init the ADC
	ADC_Initialization(AVCC,Scaler_8);
	// enable the ADC
    ADC_Enable();
	// start the conversion on the channels of the joystick
	ADC_StartConversion(X_Channel);
	ADC_StartConversion(Y_Channel);

	LCD_initialization();

	while(1)
	{
		// get the ADC values from the joystick channels
		Joystick_X = ADC_getRead(X_Channel);
		Joystick_Y = ADC_getRead(Y_Channel);
//		LCD_Cursor(0,0);
//		LCD_WriteString("X: ");
//		LCD_Cursor(4,0);
//		LCD_WriteNum_5D(Joystick_X);
//		LCD_Cursor(0,1);
//		LCD_WriteString("Y: ");
//		LCD_Cursor(4,1);
//		LCD_WriteNum_5D(Joystick_Y);

		if((Joystick_X > 120 && Joystick_X < 140) && (Joystick_Y > 120 && Joystick_Y < 140))
		{
			/* the motors stop, and that means that the user doesn't move the joystick */
		}
		else if((Joystick_X > 140 && Joystick_X <= 255) && (Joystick_Y > 120 && Joystick_Y < 140))
		{
			/* the chair moves left */
		}
		else if((Joystick_X < 120 && Joystick_X >= 0) && (Joystick_Y > 120 && Joystick_Y < 140))
		{
			/* the chair moves right */
		}
		else if((Joystick_X > 120 && Joystick_X < 140) && (Joystick_Y > 140 && Joystick_Y <= 255))
		{
			/* the chair moves forward */
		}
		else if((Joystick_X > 120 && Joystick_X < 140) && (Joystick_Y < 120 && Joystick_Y >= 0))
		{
			/* the chair moves backward */
		}
	}
	return 0;
}
