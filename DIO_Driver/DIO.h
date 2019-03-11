#ifndef MCAL_H_
#define MCAL_H_

#include "arm_config.h"
#include "std_types.h"
#include "common macros.h"

/*
steps to read from PORTX (assuming port is initialized):
1. Set direction of port pins.
2. Set drive strength through the GPIODR2R, GPIODR4R, and GPIODR8R
registers.
3. Program each pad in the port to have either pull-up, pull-down, or open drain functionality through
the GPIOPUR, GPIOPDR, GPIOODR register.
*/
uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask);

#endif /* MCAL_H_ */