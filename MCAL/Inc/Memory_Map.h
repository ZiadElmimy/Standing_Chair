#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#define TWBR       (*(volatile unsigned char *)0x20)
#define TWSR       (*(volatile unsigned char *)0x21)
#define TWAR       (*(volatile unsigned char *)0x22)
#define TWDR       (*(volatile unsigned char *)0x23)
#define ADCL       (*(volatile unsigned char *)0x24)
#define ADCH       (*(volatile unsigned char *)0x25)
#define ADCSRA     (*(volatile unsigned char *)0x26)
#define ADMUX      (*(volatile unsigned char *)0x27)
#define ACSR       (*(volatile unsigned char *)0x28)
#define UBRRL      (*(volatile unsigned char *)0x29)
#define UCSRB      (*(volatile unsigned char *)0x2A)
#define UCSRA      (*(volatile unsigned char *)0x2B)
#define UDR        (*(volatile unsigned char *)0x2C)
#define SPCR       (*(volatile unsigned char *)0x2D)
#define SPSR       (*(volatile unsigned char *)0x2E)
#define SPDR       (*(volatile unsigned char *)0x2F)
#define PIND       (*(volatile unsigned char *)0x30)
#define DDRD       (*(volatile unsigned char *)0x31)
#define PORTD      (*(volatile unsigned char *)0x32)
#define PINC       (*(volatile unsigned char *)0x33)
#define DDRC       (*(volatile unsigned char *)0x34)
#define PORTC      (*(volatile unsigned char *)0x35)
#define PINB       (*(volatile unsigned char *)0x36)
#define DDRB       (*(volatile unsigned char *)0x37)
#define PORTB      (*(volatile unsigned char *)0x38)
#define PINA       (*(volatile unsigned char *)0x39)
#define DDRA       (*(volatile unsigned char *)0x3A)
#define PORTA      (*(volatile unsigned char *)0x3B)
#define EECR       (*(volatile unsigned char *)0x3C)
#define EEDR       (*(volatile unsigned char *)0x3D)
#define EEARL      (*(volatile unsigned char *)0x3E)
#define EEARH      (*(volatile unsigned char *)0x3F)
#define UCSRC      (*(volatile unsigned char *)0x40)
#define UBRRH      (*(volatile unsigned char *)0x40)
#define WDTCR      (*(volatile unsigned char *)0x41)
#define ASSR       (*(volatile unsigned char *)0x42)
#define OCR2       (*(volatile unsigned char *)0x43)
#define TCNT2      (*(volatile unsigned char *)0x44)
#define TCCR2      (*(volatile unsigned char *)0x45)
//#define ICR1L      (*(volatile unsigned char *)0x46)
//#define ICR1H      (*(volatile unsigned char *)0x47)
#define ICR1       (*(volatile unsigned short *)0x46)
//#define OCR1BL     (*(volatile unsigned char *)0x48)
//#define OCR1BH     (*(volatile unsigned char *)0x49)
#define OCR1B      (*(volatile unsigned short *)0x48)
//#define OCR1AL     (*(volatile unsigned char *)0x4A)
//#define OCR1AH     (*(volatile unsigned char *)0x4B)
#define OCR1A      (*(volatile unsigned short *)0x4A)
//#define TCNT1L     (*(volatile unsigned char *)0x4C)
//#define TCNT1H     (*(volatile unsigned char *)0x4D)
#define TCNT1      (*(volatile unsigned short *)0x4C)
#define TCCR1B     (*(volatile unsigned char *)0x4E)
#define TCCR1A     (*(volatile unsigned char *)0x4F)
#define SFIOR      (*(volatile unsigned char *)0x50)
#define OCDR       (*(volatile unsigned char *)0x51)
#define OSCCAL     (*(volatile unsigned char *)0x51)
#define TCNT0      (*(volatile unsigned char *)0x52)
#define TCCR0      (*(volatile unsigned char *)0x53)
#define MCUCSR     (*(volatile unsigned char *)0x54)
#define MCUCR      (*(volatile unsigned char *)0x55)
#define TWCR       (*(volatile unsigned char *)0x56)
#define SPMCR      (*(volatile unsigned char *)0x57)
#define TIFR       (*(volatile unsigned char *)0x58)
#define TIMSK      (*(volatile unsigned char *)0x59)
#define GIFR       (*(volatile unsigned char *)0x5A)
#define GICR       (*(volatile unsigned char *)0x5B)
#define OCR0       (*(volatile unsigned char *)0x5C)
#define SPL        (*(volatile unsigned char *)0x5D)
#define SPH        (*(volatile unsigned char *)0x5E)
#define SREG       (*(volatile unsigned char *)0x5F)

/**********************************Register Bits****************************************/
//ADC
//ADMUX
#define ADLAR  5
#define REFS0  6
#define REFS1  7
//ADCSRA
#define ADIE   3
#define ADIF   4
#define ADATA  5
#define ADSC   6
#define ADEN   7


//External interrupt
//MCUCR
#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3
#define SM0    4
#define SM1    5
#define SM2    6
#define SE     7
//MCYCSR
#define PORF   0
#define EXTRF  1
#define BORF   2
#define WORF   3
#define JTRF   4
#define ISC2   6
#define JTD    7
//GICR
#define IVCE   0
#define IVSEL  1
#define INT2   5
#define INT0   6
#define INT1   7
//GIFR
#define INTF2  5
#define INTF0  6
#define INTF1  7


//Timers
//TCCR0
#define WGM01  3
#define COM00  4
#define COM01  5
#define WGM00  6
#define FOC0   7
//TIMSK
#define TOIE0  0
#define OCIE0  1
#define TOIE1  2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2  6
#define OCIE2  7
//TIFR
#define TOV0   0
#define OCF0   1
#define TOV1   2
#define OCF1B  3
#define OCF1A  4
#define ICF1   5
#define TOV2   6
#define OCF2   7
//TCCR1A
#define WGM10  0
#define WGM11  1
#define FOC1B  2
#define FOC1A  3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7
//TCCR1B
#define CS10   0
#define CS11   1
#define CS12   2
#define WGM12  3
#define WGM13  4
#define ICES1  6
#define ICNC1  7
//TCCR2
#define WGM21  3
#define COM20  4
#define COM21  5
#define WGM20  6
#define FOC2   7
/******************************************************************************************************/
//Communication protocols
//UART
//UCSRA
#define MPCM   0
#define U2X    1
#define PE     2
#define DOR    3
#define FE     4
#define UDRE   5
#define TXC    6
#define RXC    7
//UCSRB
#define TXB8   0
#define RXB8   1
#define UCSZ2  2
#define TXEN   3
#define RXEN   4
#define UDRIE  5
#define TXCIE  6
#define RXCIE  7
//UCSRC
#define UCPOL  0
#define UCSZ0  1
#define UCSZ1  2
#define USBS   3
#define UPM0   4
#define UPM1   5
#define UMSEL  6
#define URSEL  7
//UBRRH
#define URSEL  7


//SPI
//SPCR
#define SPR0   0
#define SPR1   1
#define CPHA   2
#define CPOL   3
#define MSTR   4
#define DORD   5
#define SPE    6
#define SPIE   7
//SPSR
#define SPI2X  0
#define WCOL   6
#define SPIF   7


//I2C
//TWCR
#define TWIE   0
#define TWEN   2
#define TWWC   3
#define TWSTO  4
#define TWSTA  5
#define TWEA   6
#define TWINT  7
//TWSR
#define TWPS0  0
#define TWPS1  1
#define TWS3   3
#define TWS4   4
#define TWS5   5
#define TWS6   6
#define TWS7   7
//TWAR
#define TWGCE  0

#endif /* MEMORY_MAP_H_ */
