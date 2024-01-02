/*
 * stdRegs.h
 *
 * Created: 11/29/2023 3:13:15 PM
 *  Author: Alaa
 */ 

#ifndef stdRegs_H_
#define stdRegs_H_

#define DDRA *((volatile char*)0x3A)
#define DDRB *((volatile char*)0x37)
#define DDRC *((volatile char*)0x34)
#define DDRD *((volatile char*)0x31)
#define PORTA *((volatile char*)0x3B)
#define PORTB *((volatile char*)0x38)
#define PORTC *((volatile char*)0x35)
#define PORTD *((volatile char*)0x32)
#define PINA *((volatile char*)0x39)
#define PINB *((volatile char*)0x36)
#define PINC *((volatile char*)0x33)
#define PIND *((volatile char*)0x30)
#define SFIOR *((volatile char*)0x50)


#endif /* stdRegs_H_ */