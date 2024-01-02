#include "Typedefs.h"
#include "delay.h"
#ifndef F_CPU
#define F_CPU 1000000UL
#endif
/*
*@brief : The function satisfies a certain delay 
*@param : The delay time 
*@return: void
*/
void delay(double delay)
{
	long double i;
	long double n = (delay * F_CPU)/20000;
	for(i=0;i<n;i++);
}

