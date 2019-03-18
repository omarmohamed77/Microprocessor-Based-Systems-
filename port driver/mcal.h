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
void DIO_WritePort (uint8 port_index, uint8 pins_mask, enum Dio_LevelType pins_level);
void Port_SetPinDirection(uint8 port_index, uint8 pins_mask,enum Port_PinDirectionType pins_direction);
uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask);
#endif /* MCAL_H_ */
