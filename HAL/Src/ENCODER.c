/*
 * Encoder.c
 *
 *  Created on: Apr 13, 2024
 *      Author: zaynab
 */

#include "../Inc/ENCODER.h"


#include "../../MCAL/Inc/Timers.h"


//  ************************[NOTE]code for one encoder **********************

volatile u32 encoder_count = 0;  // Stores encoder pulse count
volatile unsigned long timer0_overflows = 0;  // Counts Timer0 overflows

// Variables for elapsed time calculation
volatile unsigned char last_timer0_count = 0;  // Last TCNT0 value



f64 ENCODER_voidUpdateSpeed(Timer_PreScaler prescaler ,u64 clock_frequency)
{
	  // Get current timer count
	  unsigned char current_timer0_count = TCNT0;

	  // Calculate elapsed time in milliseconds (considering overflows)
	  u64 elapsed_time_ms = 0;
	  elapsed_time_ms = (timer0_overflows * 256) + current_timer0_count;  // Total counts

	  // Calculate elapsed time in seconds
	  f64 elapsed_time_sec = (f64)elapsed_time_ms / (f64)(clock_frequency / prescaler) / 1000.0;  // Adjust for clock and prescaler

	  // Rest of the speed calculation remains the same
	  f64 speed = (f64)encoder_count * 60.0 / elapsed_time_sec;
	  encoder_count = 0; // Reset count for next measurement
	  last_timer0_count = current_timer0_count;  // Update for next calculation

	  return speed;
}

void ENCODER_voidInit(void)
{
	// Set interrupt mode and register callback function
	Timer00_Initialization(Normal_Mode, PreScaler_64, Normal);
	Timer00_OVF_Enable();
	Timer00_SetCallBack(OVF00_Interrupt,TIMER0_OVF_f);

	EXT_Interrupt_Mode(INT_0, RISING_EDGE);
	EXT_Int00_CallBAck(ENCODER_voidInterruptHandler);
	EXT_Int_Enable(INT_0);

	last_timer0_count = TCNT0;


}


// Interrupt service routine (for encoder pulse)
void ENCODER_voidInterruptHandler(void) {
  encoder_count++;
}



// Timer0 overflow interrupt service routine (replace if needed)
void TIMER0_OVF_f(void) {
  timer0_overflows++;
}

