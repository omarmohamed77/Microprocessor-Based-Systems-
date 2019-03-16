#ifndef MCAL_H_
#define MCAL_H_

#include "arm_config.h"
#include "std_types.h"
#include "common macros.h"

uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask);

#endif /* MCAL_H_ */