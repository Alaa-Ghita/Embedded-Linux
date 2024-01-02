/*
 * DIO.h
 *
 * Created: 12/3/2023 10:03:15 PM
 *  Author: Alaa
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "PORT_cfg.h"
#include "Typedefs.h"

/*Include here Your Standard Types File that contains  typedef, SET,CLEAR,Toggle...etc */

/**
 *@brief : The ports Type of the AVR                            
 */
#if (NUM_OF_PORTS == 1)
typedef enum
{
	DIO_enumPortA,

}DIO_enumPorts_t;
#elif (NUM_OF_PORTS == 2)
typedef enum
{
	DIO_enumPortA,
	DIO_enumPortB,
}DIO_enumPorts_t;
#elif (NUM_OF_PORTS == 3)
typedef enum
{
	DIO_enumPortA,
	DIO_enumPortB,
	DIO_enumPortC
}DIO_enumPorts_t;
#elif (NUM_OF_PORTS == 4)
typedef enum
{
	DIO_enumPortA,
	DIO_enumPortB,
	DIO_enumPortC,
	DIO_enumPortD
}DIO_enumPorts_t;
#endif

/**
 *@brief : The Error List Type                                           
 */
typedef enum 
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	DIO_enumOk,             
	/**
	 *@brief : NULL Pointer is passed.
	 */
	DIO_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	DIO_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	DIO_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	DIO_enumWrongConfig    
	
}DIO_enumError_t;
	
/**
 *@brief : The Configuration Type of Pins to be Input or Output !        
 */
	
/**
 *@brief :  Logic State Type : HIGH (5V) or LOW(0V )                     
 */
typedef enum
{   
	DIO_enumLogicLow,
	DIO_enumLogicHigh
}DIO_enumLogicState_t;

/**
 *@brief :  Pins Number Per Each Port                                  
 */
#if (NUM_OF_PINS_PER_PORT == 4)
typedef enum
{
	DIO_enumPin0,
	DIO_enumPin1,
	DIO_enumPin2,
	DIO_enumPin3
}DIO_enumPins_t;
#elif (NUM_OF_PINS_PER_PORT == 8)
typedef enum
{
	DIO_enumPin0,
	DIO_enumPin1,
	DIO_enumPin2,
	DIO_enumPin3,
	DIO_enumPin4,
	DIO_enumPin5,
	DIO_enumPin6,
	DIO_enumPin7
}DIO_enumPins_t;
#endif

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState);

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState); 

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue);

/**
 *@brief : Function to Set the whole Port(8 pins) to a Value passed by the user.
 *@param : Port Number,Value.
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetValueToPort(DIO_enumPorts_t Copy_enumPortNum,uint8 Copy_u8Value);

#endif /* DIO_H_ */