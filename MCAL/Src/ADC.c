#include "ADC.h"

void ADC_Initialization(ADC_Reference reference, ADC_PreScaler scaler)
{
   //choose the reference for ADC
   switch(reference)
   {
   case AREF:
	   ADMUX &= ~(1<<REFS1);
	   ADMUX &= ~(1<<REFS0);
	   break;
   case AVCC:
	   ADMUX &= ~(1<<REFS1);
	   ADMUX |= (1<<REFS0);
	   break;
   case RESERVED:
	   ADMUX |= (1<<REFS1);
	   ADMUX &= ~(1<<REFS0);
	   break;
   case In256_Ref:
	   ADMUX |= (1<<REFS1);
	   ADMUX |= (1<<REFS0);
	   break;
   }

   //set the pre-scaler
   ADCSRA &= 0xF8; //to make sure that the bits are 0
   ADCSRA |= scaler;

   //set the read mode
   ADMUX &= ~(1<<ADLAR);
}

void ADC_Enable(void)
{
   ADCSRA |= (1<<ADEN);
}

void ADC_Disable(void)
{
   ADCSRA &= ~(1<<ADEN);
}

u16 ADC_getRead(ADC_Channel channel)
{
	volatile static u16 adc_read;
	//choose the channel
    ADMUX &= 0xF8;
    ADMUX |= channel;
   //start the conversion
	ADCSRA |= (1<<ADSC);
   while((1&(ADCSRA>>ADSC)) == 1);
   adc_read = ADCL | (u16)ADCH << 8;
   return adc_read;
}

void ADC_StartConversion(ADC_Channel channel)
{
	//choose the channel
	    ADMUX &= 0xF8;
	    ADMUX |= channel;
	   //start the conversion
		ADCSRA |= (1<<ADSC);
}

u16 ADC_Voltage(ADC_Channel ch)
{
   volatile static u16 read = 0, volt = 0;
   read = ADC_getRead(ch);
   volt = ((u64)read * 5000)/1023;
   return volt;
}

