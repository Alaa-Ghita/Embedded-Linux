#ifndef PORT_CFG_H_
#define PORT_CFG_H_
/*
 * Choose the type of configuration PRE_COMPLIE or POST_COMPILE 
 * 
 * - PRE_COMPILE configuration produces smaller size of the code and can not be 
 *   changed in the run time.
 * 
 * - POST_COMPILE configuration produces a little bit larger size of the code, but 
 * 	 can be changed through the run time.
 */
#define PRE_COMPILE 0
#define POST_COMPILE 1


#define CONFIG_TYPE POST_COMPILE 

#if (CONFIG_TYPE == PRE_COMPILE)
	
	#define ONE_PORT 0
	#define TWO_PORTS 1 
	#define THREE_PORTS 2
	#define FOUR_PORTS 3
	/* Choose the number of ports:
	 * ONE_PORT
	 * TWO_PORTS
	 * THREE_PORTS
	 * FOUR_PORTS
	 */
	#define NUM_OF_PORTS FOUR_PORTS

	#define PORT_INPUT_PU 0 
	#define PORT_INPUT_HI 1 
	#define PORT_OUTPUT_HIGH 2 
	#define PORT_OUTPUT_LOW 3

	/*Here choose the configuration of each pin, there are 4 configurations:
	 *		INPUT_PU
	 *		INPUT_HI
	 *		OUTPUT_HIGH
	 *		OUTPUT_LOW
	 */ 
	#define PORT_PIN0  PORT_INPUT_PU
	#define PORT_PIN1  PORT_INPUT_HI
	#define PORT_PIN2  PORT_OUTPUT_HIGH
	#define PORT_PIN3  PORT_OUTPUT_LOW
	#define PORT_PIN4  PORT_OUTPUT_LOW
	#define PORT_PIN5  PORT_OUTPUT_LOW
	#define PORT_PIN6  PORT_OUTPUT_LOW
	#define PORT_PIN7  PORT_OUTPUT_LOW
	#define PORT_PIN8  PORT_OUTPUT_LOW
	#define PORT_PIN9  PORT_OUTPUT_LOW
	#define PORT_PIN10 PORT_OUTPUT_LOW
	#define PORT_PIN11 PORT_OUTPUT_LOW
	#define PORT_PIN12 PORT_OUTPUT_LOW
	#define PORT_PIN13 PORT_OUTPUT_LOW
	#define PORT_PIN14 PORT_OUTPUT_LOW
	#define PORT_PIN15 PORT_OUTPUT_LOW
	#define PORT_PIN16 PORT_OUTPUT_HIGH
	#define PORT_PIN17 PORT_OUTPUT_HIGH
	#define PORT_PIN18 PORT_OUTPUT_HIGH
	#define PORT_PIN19 PORT_OUTPUT_HIGH
	#define PORT_PIN20 PORT_OUTPUT_HIGH
	#define PORT_PIN21 PORT_OUTPUT_HIGH
	#define PORT_PIN22 PORT_OUTPUT_HIGH
	#define PORT_PIN23 PORT_OUTPUT_HIGH
	#define PORT_PIN24 PORT_OUTPUT_HIGH
	#define PORT_PIN25 PORT_OUTPUT_HIGH
	#define PORT_PIN26 PORT_OUTPUT_HIGH
	#define PORT_PIN27 PORT_OUTPUT_HIGH
	#define PORT_PIN28 PORT_OUTPUT_HIGH
	#define PORT_PIN29 PORT_OUTPUT_HIGH
	#define PORT_PIN30 PORT_OUTPUT_HIGH
	#define PORT_PIN31 PORT_OUTPUT_HIGH


#elif (CONFIG_TYPE == POST_COMPILE)

	/*Determine the number of ports*/
	#define NUM_OF_PORTS 4
	/*Determine the number of pins per port*/
	#define NUM_OF_PINS_PER_PORT 8


	#define NUM_OF_PINS (NUM_OF_PORTS * NUM_OF_PINS_PER_PORT)

	typedef enum{
		PORT_enuInput_PU,
		PORT_enuInput_HI,
		PORT_enuOUTPUT_HIGH,
		PORT_enuOUTPUT_LOW,
	}PORT_enuPinOPT_t;
	
	typedef struct{
		PORT_enuPinOPT_t PinCfg[NUM_OF_PINS];
	}PORT_StrPinCfg_t;
	

	#if (NUM_OF_PORTS == 1)
		typedef enum
		{  
			PORT_enuPortA,

		}PORT_enuPorts_t;
	#elif (NUM_OF_PORTS == 2)
		typedef enum
		{
			PORT_enuPortA,
			PORT_enuPortB,
		}PORT_enuPorts_t;
	#elif (NUM_OF_PORTS == 3)
		typedef enum
		{
			PORT_enuPortA,
			PORT_enuPortB,
			PORT_enuPortC
		}PORT_enuPorts_t;
	#elif (NUM_OF_PORTS == 4)
		typedef enum
		{
			PORT_enuPortA,
			PORT_enuPortB,
			PORT_enuPortC,
			PORT_enuPortD
		}PORT_enuPorts_t;
	#endif


#endif

#endif