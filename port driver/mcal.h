/*
 * port_int.h
 *
 *  Created on: Mar 10, 2019
 *      Author: omar
 */

#ifndef MCAL_H_
#define MCAL_H_

#include "arm_config.h"
#include "std_types.h"
#include "common macros.h"
void PORT_INT(uint8 port_index);
void Port_SetPinDirection(uint8 port_index, uint8 pins_mask,enum Port_PinDirectionType pins_direction);
void DIO_WritePort(uint8 port_index, uint8 pins_mask,enum Dio_LevelType pins_level);

#endif /* MCAL_H_ */
