#ifndef PORT_H_
#define PORT_H_

#include "PORT_cfg.h"

#if (CONFIG_TYPE == PRE_COMPILE)

#define PORT_LOW 0
#define PORT_HIGH 1

#define HELPER(PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1,PIN0)  0b##PIN7##PIN6##PIN5##PIN4##PIN3##PIN2##PIN1##PIN0
#define CONCAT(Pin7,Pin6,Pin5,Pin4,Pin3,Pin2,Pin1,Pin0)  HELPER(Pin7,Pin6,Pin5,Pin4,Pin3,Pin2,Pin1,Pin0)

#endif

void PORT_vInit();

#endif