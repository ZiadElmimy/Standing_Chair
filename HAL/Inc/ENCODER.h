/*
 * Encoder.h
 *
 *  Created on: Apr 13, 2024
 *      Author: zaynab
 */

#ifndef STANDING_CHAIR_HAL_INC_ENCODER_H_
#define STANDING_CHAIR_HAL_INC_ENCODER_H_

#include "../../MCAL/Inc/Timers.h"
#include "../../MCAL/Inc/EXT_Interrupt.h"
#include "../../Standard_Types.h"

<<<<<<< HEAD
f64 ENCODER_voidUpdateSpeed(Timer_PreScaler prescaler ,u64 clock_frequency);
void ENCODER_voidInit(void);
void ENCODER_voidInterruptHandler(void);
void TIMER0_OVF_f(void);
=======
f64 ENCODER_voidUpdateSpeed(void);
void ENCODER_voidInit(void);
void ENCODER_voidIsr(void);

>>>>>>> e8878c0f7f1ad3aa2023c0a498336ae8cee11d8b



#endif /* STANDING_CHAIR_HAL_INC_ENCODER_H_ */
