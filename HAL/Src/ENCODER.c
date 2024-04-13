/*
 * Encoder.c
 *
 *  Created on: Apr 13, 2024
 *      Author: zaynab
 */

#include "../Inc/ENCODER.h"

//  ************************[NOTE]code for one encoder **********************

volatile u32 encoder_count = 0;  // Stores encoder pulse count
volatile u64 last_pulse_time = 0;  // Time of the last encoder pulse

ENCODER_voidUpdateSpeed(void)
{
	// Calculate speed based on encoder count and elapsed time
	u64 current_time =  millis(); // do some thing with this to calculate the time
	f64 elapsed_time = (f64)(current_time - last_pulse_time) / 1000.0; // with seconds
	f64 speed = (f64)encoder_count * 60.0 / elapsed_time;
	encoder_count = 0; // Reset count for next measurement
	return speed;
}

void ENCODER_voidInit(void)
{
	// Set interrupt mode and register callback function
	EXT_Interrupt_Mode(INT_0, RISING_EDGE);
	EXT_Int00_CallBAck(ENCODER_voidIsr);
	EXT_Int_Enable(INT_0);

}
void ENCODER_voidIsr(void)
{
	// Interrupt service routine logic
	encoder_count++;

}



