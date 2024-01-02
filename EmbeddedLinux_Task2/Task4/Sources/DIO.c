/*
 * DIO.c
 *
 * Created: 12/03/2023 10:10:24 PM
 *  Author: Alaa
 */ 

#include "Bit_Math.h"
#include "Typedefs.h"
#include "stdRegs.h"
#include "DIO.h"
#include "PORT_cfg.h"
extern PORT_StrPinsConfig;


#if (CONFIG_TYPE == PRE_COMPILE)
/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumWrongConfig;
	#if (NUM_OF_PORTS == 1)
	if(Copy_enumPortNum>DIO_enumPortA)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 2)
	if(Copy_enumPortNum>DIO_enumPortB)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 3)
	if(Copy_enumPortNum>DIO_enumPortC)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 4)
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#endif
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enumErrorStatus = DIO_enumWrongPin;
	}
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
				case DIO_enumPortA:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
					CLR_BIT(PORTA,Copy_enumPinNum);
					break;
					case DIO_enumLogicHigh:
					SET_BIT(PORTA,Copy_enumPinNum);
					break;
					default:
					break;
				}
				break;

				case DIO_enumPortB:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
					CLR_BIT(PORTB,Copy_enumPinNum);
					break;
					case DIO_enumLogicHigh:
					SET_BIT(PORTB,Copy_enumPinNum);
					break;
					default:
					break;
				}
				break;
		
				case DIO_enumPortC:
					switch(Copy_enumLogicState)
					{
						case DIO_enumLogicLow:
							CLR_BIT(PORTC,Copy_enumPinNum);
							break;
						case DIO_enumLogicHigh:
							SET_BIT(PORTC,Copy_enumPinNum);
							break;
						default:
							break;
					}
					break;
		
				case DIO_enumPortD:
					switch(Copy_enumLogicState)
					{
						case DIO_enumLogicLow:
							CLR_BIT(PORTD,Copy_enumPinNum);
							break;
						case DIO_enumLogicHigh:
							SET_BIT(PORTD,Copy_enumPinNum);
							break;
						default:
							break;
					}
					break;
		
				default:
					break;
		
		}
	}
	return Ret_enumErrorStatus;
}


/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumWrongConfig;
	#if (NUM_OF_PORTS == 1)
	if(Copy_enumPortNum>DIO_enumPortA)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 2)
	if(Copy_enumPortNum>DIO_enumPortB)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 3)
	if(Copy_enumPortNum>DIO_enumPortC)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 4)
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#endif
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
					PORTA = 0x00;
					break;
					case DIO_enumLogicHigh:
					PORTA = 0xff;
					break;
					default:
					break;
				}
				break;

			case DIO_enumPortB:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
					PORTB = 0x00;
					break;
					case DIO_enumLogicHigh:
					PORTB = 0xff;
					break;
					default:
					break;
				}
				break;
			
			case DIO_enumPortC:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
					PORTC = 0x00;
					break;
					case DIO_enumLogicHigh:
					PORTC = 0xff;
					break;
					default:
					break;
				}
				break;
			
			case DIO_enumPortD:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
					PORTD = 0x00;
					break;
					case DIO_enumLogicHigh:
					PORTD = 0xff;
					break;
					default:
					break;
				}
				break;
			
			default:
				break;
			
		}
	}
	return Ret_enumErrorStatus;
}


/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumWrongConfig;
	#if (NUM_OF_PORTS == 1)
	if(Copy_enumPortNum>DIO_enumPortA)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 2)
	if(Copy_enumPortNum>DIO_enumPortB)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 3)
	if(Copy_enumPortNum>DIO_enumPortC)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 4)
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#endif
	else if(Add_Pu8PinValue==NULL)
	{
		Ret_enumErrorStatus = DIO_enumNullPointer;
	}
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			*Add_Pu8PinValue = GET_BIT(PINA,Copy_enumPinNum);
			break;

			case DIO_enumPortB:
			*Add_Pu8PinValue = GET_BIT(PINB,Copy_enumPinNum);
			break;
			
			case DIO_enumPortC:
			*Add_Pu8PinValue = GET_BIT(PINC,Copy_enumPinNum);
			break;
			
			case DIO_enumPortD:
			*Add_Pu8PinValue = GET_BIT(PIND,Copy_enumPinNum);
			break;
			
			default:
			break;
		}
	}
	return Ret_enumErrorStatus;
}

/**
 *@brief : Function to Set the whole Port(8 pins) to a Value passed by the user.
 *@param : Port Number,Value.
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetValueToPort(DIO_enumPorts_t Copy_enumPortNum,uint8 Copy_u8Value)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumWrongConfig;
	#if (NUM_OF_PORTS == 1)
	if(Copy_enumPortNum>DIO_enumPortA)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 2)
	if(Copy_enumPortNum>DIO_enumPortB)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 3)
	if(Copy_enumPortNum>DIO_enumPortC)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 4)
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#endif
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			ASSIGN_REG(PORTA,Copy_u8Value);
			break;

			case DIO_enumPortB:
			ASSIGN_REG(PORTB,Copy_u8Value);
			break;
		
			case DIO_enumPortC:
			ASSIGN_REG(PORTC,Copy_u8Value);
			break;
		
			case DIO_enumPortD:
			ASSIGN_REG(PORTD,Copy_u8Value);
			break;
		
			default:
			break;
		}
	}
	return Ret_enumErrorStatus;
}



#elif (CONFIG_TYPE == POST_COMPILE)

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumWrongConfig;
	#if (NUM_OF_PORTS == 1)
	if(Copy_enumPortNum>DIO_enumPortA)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 2)
	if(Copy_enumPortNum>DIO_enumPortB)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 3)
	if(Copy_enumPortNum>DIO_enumPortC)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 4)
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#endif
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enumErrorStatus = DIO_enumWrongPin;
	}
	else
	{ 
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
						CLR_BIT(PORTA,Copy_enumPinNum);
						break;
					case DIO_enumLogicHigh:
						SET_BIT(PORTA,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;

			case DIO_enumPortB:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
						CLR_BIT(PORTB,Copy_enumPinNum);
						break;
					case DIO_enumLogicHigh:
						SET_BIT(PORTB,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			
			case DIO_enumPortC:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
						CLR_BIT(PORTC,Copy_enumPinNum);
						break;
					case DIO_enumLogicHigh:
						SET_BIT(PORTC,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			
			case DIO_enumPortD:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
						CLR_BIT(PORTD,Copy_enumPinNum);
						break;
					case DIO_enumLogicHigh:
						SET_BIT(PORTD,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			
			default:
				break;
		}
	}
	return Ret_enumErrorStatus;
}


/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumWrongConfig;
	#if (NUM_OF_PORTS == 1)
	if(Copy_enumPortNum>DIO_enumPortA)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 2)
	if(Copy_enumPortNum>DIO_enumPortB)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 3)
	if(Copy_enumPortNum>DIO_enumPortC)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 4)
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#endif
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
						PORTA = 0x00;
						break;
					case DIO_enumLogicHigh:
						PORTA = 0xff;
						break;
					default:
						break;
				}
				break;

			case DIO_enumPortB:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
						PORTB = 0x00;
						break;
					case DIO_enumLogicHigh:
						PORTB = 0xff;
						break;
					default:
						break;
				}
				break;
				
			case DIO_enumPortC:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
						PORTC = 0x00;
						break;
					case DIO_enumLogicHigh:
						PORTC = 0xff;
						break;
					default:
						break;
				}
				break;
			
			case DIO_enumPortD:
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicLow:
						PORTD = 0x00;
						break;
					case DIO_enumLogicHigh:
						PORTD = 0xff;
						break;
					default:
						break;
				}
				break;
			
			default:
				break;
		}
	}
	return Ret_enumErrorStatus;
}


/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumWrongConfig;
	#if (NUM_OF_PORTS == 1)
	if(Copy_enumPortNum>DIO_enumPortA)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 2)
	if(Copy_enumPortNum>DIO_enumPortB)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 3)
	if(Copy_enumPortNum>DIO_enumPortC)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#elif (NUM_OF_PORTS == 4)
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	#endif
	else if(Add_Pu8PinValue==NULL)
	{
		Ret_enumErrorStatus = DIO_enumNullPointer;
	}
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
				*Add_Pu8PinValue = GET_BIT(PINA,Copy_enumPinNum);
				break;

			case DIO_enumPortB:
				*Add_Pu8PinValue = GET_BIT(PINB,Copy_enumPinNum);
				break;
				
			case DIO_enumPortC:
				*Add_Pu8PinValue = GET_BIT(PINC,Copy_enumPinNum);
				break;
			
			case DIO_enumPortD:
				*Add_Pu8PinValue = GET_BIT(PIND,Copy_enumPinNum);
				break;
			
			default:
				break;
		}
	}
	return Ret_enumErrorStatus;
}

#endif
