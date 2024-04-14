#include "../Inc/DIO.h"
#include "../../Standard_Types.h"

void DIO_PinInitialization(DIO_Pin pin, DIO_Status status)
{
   DIO_Port port = pin/8;
   u8 new_pin = pin%8;

   switch(status)
   {
   case OUTPUT:
        switch(port)
        {
        case PA:
        	DDRA |= (1<<new_pin);
        	break;
        case PB:
        	DDRB |= (1<<new_pin);
        	break;
        case PC:
        	DDRC |= (1<<new_pin);
        	break;
        case PD:
        	DDRD |= (1<<new_pin);
        	break;
        }
        break;
   case INFREE:
	   switch(port)
	           {
	           case PA:
	           	DDRA &= ~(1<<new_pin);
	           	break;
	           case PB:
	           	DDRB &= ~(1<<new_pin);
	           	break;
	           case PC:
	           	DDRC &= ~(1<<new_pin);
	           	break;
	           case PD:
	           	DDRD &= ~(1<<new_pin);
	           	break;
	           }
	   break;
   case INPULLUP:
	   switch(port)
	   	           {
	   	           case PA:
	   	           	DDRA &= ~(1<<new_pin);
	   	           	PORTA |= (1<<new_pin);
	   	           	break;
	   	           case PB:
	   	           	DDRB &= ~(1<<new_pin);
	   	           	PORTB |= (1<<new_pin);
	   	           	break;
	   	           case PC:
	   	           	DDRC &= ~(1<<new_pin);
	   	           	PORTC |= (1<<new_pin);
	   	           	break;
	   	           case PD:
	   	           	DDRD &= ~(1<<new_pin);
	   	           	PORTD |= (1<<new_pin);
	   	           	break;
	   	           }
	   break;
   }
}

void DIO_WritePin(DIO_Pin pin, DIO_Voltage volt)
{
   DIO_Port port = pin/8;
   u8 new_pin = pin%8;

   switch(volt)
   {
   case HIGH:
	   switch(port)
	   {
	   case PA:
		   PORTA |= (1<<new_pin);
		   break;
	   case PB:
		   PORTB |= (1<<new_pin);
		   break;
	   case PC:
		   PORTC |= (1<<new_pin);
		   break;
	   case PD:
		   PORTD |= (1<<new_pin);
		   break;
	   }
	   break;
   case LOW:
	   switch(port)
	   	   {
	   	   case PA:
	   		   PORTA &= ~(1<<new_pin);
	   		   break;
	   	   case PB:
	   		   PORTB &= ~(1<<new_pin);
	   		   break;
	   	   case PC:
	   		   PORTC &= ~(1<<new_pin);
	   		   break;
	   	   case PD:
	   		   PORTD &= ~(1<<new_pin);
	   		   break;
	   	   }
	   	break;
   }

}

DIO_Voltage DIO_ReadPin(DIO_Pin pin)
{
  DIO_Port port = pin/8;
  u8 new_pin = pin%8;
  volatile DIO_Voltage volt;
  switch(port)
  {
  case PA:
	  volt = (1&(PINA>>new_pin));
	  break;
  case PB:
	  volt = (1&(PINB>>new_pin));
	  break;
  case PC:
	  volt = (1&(PINC>>new_pin));
	  break;
  case PD:
	  volt = (1&(PIND>>new_pin));
	  break;
  }
  return volt;
}


void DIO_PortInitialization(DIO_Port port, DIO_Status status)
{
	switch(status)
	{
	case OUTPUT:
		switch(port)
		{
		case PA:
			DDRA = 0xFF;
			break;
		case PB:
			DDRB = 0xFF;
			break;
		case PC:
			DDRC = 0xFF;
			break;
		case PD:
		DDRD = 0xFF;
		break;
		}
		break;
    case INFREE:
    	switch(port)
    	{
    	case PA:
    		DDRA = 0x00;
    		break;
    	case PB:
    		DDRB = 0x00;
    		break;
    	case PC:
    		DDRC = 0x00;
    		break;
    	case PD:
    		DDRD = 0x00;
    		break;
    	}
    	break;
    case INPULLUP:
    	switch(port)
    	{
    	case PA:
    	    DDRA = 0x00;
    	    PORTA = 0xFF;
    	    break;
    	case PB:
    	    DDRB = 0x00;
    	    PORTB = 0xFF;
    	    break;
    	case PC:
    	    DDRC = 0x00;
    	    PORTC = 0xFF;
    	    break;
    	case PD:
    	    DDRD = 0x00;
    	    PORTD = 0xFF;
    	    break;
    	}
        break;
	}
}

void DIO_WritePort(DIO_Port port, u8 data)
{
	switch(port)
	{
	case PA:
		PORTA = data;
		break;
	case PB:
		PORTB = data;
		break;
	case PC:
		PORTC = data;
		break;
	case PD:
		PORTD = data;
		break;
	}
}

u8 DIO_ReadPort(DIO_Port port)
{
	volatile u8 data;
	switch(port)
	{
	case PA:
		data = PINA;
		break;
	case PB:
		data = PINB;
		break;
	case PC:
		data = PINC;
		break;
	case PD:
		data = PIND;
		break;
	}
	return data;
}

void DIO_Initialization(void)
{
  for(DIO_Pin pin = PinA0; pin < total_pins; pin++)
  {
	  DIO_PinInitialization(pin,config[pin]);
  }
}
