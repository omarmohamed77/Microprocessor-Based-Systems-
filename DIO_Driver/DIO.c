#include "DIO.h"

uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask)
{

    //Port_SetPinDirection(port_index, pins_mask, PORT_PIN_IN);
    //Port_SetPinPullUp(port_index, pins_mask, 1);

    return GPIO_PORTA_DATA_R & pins_mask;
}
