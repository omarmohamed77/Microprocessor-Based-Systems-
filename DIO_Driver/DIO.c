#include "DIO.h"

uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask)
{

    //Port_SetPinDirection(port_index, pins_mask, PORT_PIN_IN);
    //Port_SetPinPullUp(port_index, pins_mask, 1);
    volatile uint32 *PORT = GPIO_PORTA_DATA_BITS_R + ((port_index & 0x03) << 12) + ((port_index >> 2) << 17);

    return PORT[pins_mask];
}
