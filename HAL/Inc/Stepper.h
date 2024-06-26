#ifndef STEPPER_H_
#define STEPPER_H_
#include "../../MCAL/Inc/DIO.h"

#define IN_1  PinC4
#define IN_2  PinC5
#define IN_3  PinC6
#define IN_4  PinC7

#define FB_1 PinB1
#define FB_2 PinB2

#define delay  600

void Forward_move(void);
void Backward_move(void);
void forward_angle(u16 angle); //the resolution angle is 8
void backword_angle(u16 angle); //the resolution angle is 8
void Forward_rounds(u8 rounds);
void Backward_rounds(u8 rounds);
void back_motor_move(void);

#endif /* STEPPER_H_ */
