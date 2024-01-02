#ifndef DELAY_H_
#define DELAY_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif
#include "Typedefs.h"
/*
*@brief : The function satisfies a certain delay
*@param : The delay time
*@return: void
*/
void delay(double time);


#endif /* DELAY_H_ */
