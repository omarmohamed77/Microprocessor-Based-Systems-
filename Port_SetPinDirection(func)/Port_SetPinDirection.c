
#include"Port_SetPinDirection.h"
void Port_SetPinDirection(uint8 port_index, uint8 pins_mask, Port_PinDirectionType pins_direction){
	uint32 Port_reg;
	switch(port_index){
		case 0:
			Port_reg=GPIO_PORTA_DIR_R;
	     break;
		case 1:
			Port_reg=GPIO_PORTB_DIR_R;
		   break;
	case 2:
			Port_reg=GPIO_PORTC_DIR_R;
		   break;
	
	case 3:
			Port_reg=GPIO_PORTD_DIR_R;
		   break;
	case 4:
			Port_reg=GPIO_PORTE_DIR_R;
		   break;
		case 5:
			Port_reg=GPIO_PORTF_DIR_R;
		   break;
	
	}
if(pins_direction){ //when the mask want to set bit 
Port_reg |= pins_mask;
}
else{// when want to clear bit
Port_reg &= (~(pins_mask));
}
}