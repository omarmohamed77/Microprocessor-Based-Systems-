#include "Tm4c123.h"	
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef enum
{
  	PORT_PIN_IN = 0,
  	PORT_PIN_OUT

} Port_PinDirectionType;
void Port_SetPinDirection(uint8 port_index, uint8 pins_mask, Port_PinDirectionType pins_direction);