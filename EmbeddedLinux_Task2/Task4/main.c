/*
 * main.c
 *
 * Created: 12/9/2023 6:44:28 PM
 *  Author: Alaa
 */ 

#define F_CPU 8000000UL
#include <delay.h>
#include <PORT.h>
#include <DIO.h>

int main(void)
{
	PORT_vInit();
    while(1)
    {
        DIO_enumSetPin(DIO_enumPortB,DIO_enumPin0,DIO_enumLogicHigh);
        DIO_enumSetPin(DIO_enumPortB,DIO_enumPin1,DIO_enumLogicLow);
        delay(1000);
        DIO_enumSetPin(DIO_enumPortB,DIO_enumPin0,DIO_enumLogicLow);
        DIO_enumSetPin(DIO_enumPortB,DIO_enumPin1,DIO_enumLogicHigh);
        delay(1000);
         
    }
}
