#include "Standard_Types.h"
#include "Memory_Map.h"
#include "DIO.h"
#include "EXT_Interrupt.h"
#include "ADC.h"
#include "Timers.h"

/*defining the pins for joystick*/
#define X_DIR         PinA0
#define Y_DIR         PinA1

#define X_Channel     Ch_0
#define Y_Channel     Ch_1

/*
 * motor 1 is the left one
 * motor 2 is the right one
 */

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


	Timer00_Initialization(FastPWM_Mode, PreScaler_8, Clear);
	Timer01_Initialization(FastPWM_Mode, PreScaler_8, Clear, Clear);
	Timer02_Initialization(FastPWM_Mode, PreScaler_8, Clear);
    // set the max value for timer 1
	ICR1 = 1023;
	// set the TCNT register for all timers to 0
    TCNT0 = 0;
    TCNT1 = 0;
    TCNT2 = 0;

	while(1)
	{
		// get the ADC values from the joystick channels
		Joystick_X = ADC_getRead(X_Channel);
		Joystick_Y = ADC_getRead(Y_Channel);
		Joystick_X /= 4;
		Joystick_Y /= 4;

		if((Joystick_X > 120 && Joystick_X < 140) && (Joystick_Y > 120 && Joystick_Y < 140))
		{
			/*
			 * the motors stop, and that means that the user doesn't move the joystick
			 */
            // for motor 1
            OCR1A = 0;
            OCR1B = 0;
            // for motor 2
            OCR0 = 0;
            OCR2 = 0;

		}
		else if((Joystick_X > 140 && Joystick_X <= 255) && (Joystick_Y > 120 && Joystick_Y < 140))
		{
			/*
			 * the chair moves left by running the motor 1 as a ratio from joystick input
			 * and motor 1 at around 25% of its speed
			 */
			// for motor 1
			OCR1A = 255;
			OCR1B = 0;
			// for motor 2
			OCR0 = Joystick_X;
			OCR2 = 0;
		}
		else if((Joystick_X < 120 && Joystick_X >= 0) && (Joystick_Y > 120 && Joystick_Y < 140))
		{
			/*
			 * the chair moves right by running the motor 1 as a ratio from joystick input
			 * and motor 2 at around 25% of its speed
			 */
			// for motor 1
			OCR1A = ((Joystick_X + 120) * 4);
			OCR1B = 0;
			// for motor 2
			OCR0 = 64;
			OCR2 = 0;
		}
		else if((Joystick_X > 120 && Joystick_X < 140) && (Joystick_Y > 140 && Joystick_Y <= 255))
		{
			/* the chair moves forward */
			// for motor 1
			OCR1A = 1023;
			OCR1B = 0;
		    // for motor 2
			OCR0 = 255;
			OCR2 = 0;
		}
		else if((Joystick_X > 120 && Joystick_X < 140) && (Joystick_Y < 120 && Joystick_Y >= 0))
		{
			/* the chair moves backward */
			// for motor 1
			OCR1A = 0;
			OCR1B = 1023;
		    // for motor 2
			OCR0 = 0;
			OCR2 = 255;
		}
	}
	return 0;
}
