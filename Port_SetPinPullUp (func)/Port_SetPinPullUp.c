#include "Port_SetPinPullUp"
void Port_SetPinPullUp(uint8 port_index,uint8 pins_mask,uint8 enable){
uint32 Port_reg;
	switch(port_index){
		case 0:
			Port_reg=GPIO_PORTA_PUR_R;
	     break;
		case 1:
			Port_reg=GPIO_PORTB_PUR_R;
		   break;
	case 2:
			Port_reg=GPIO_PORTC_PUR_R;
		   break;
	
	case 3:
			Port_reg=GPIO_PORTD_PUR_R;
		   break;
	case 4:
			Port_reg=GPIO_PORTE_PUR_R;
		   break;
		case 5:
			Port_reg=GPIO_PORTF_PUR_R;
		   break;
	
	}
	if(enable){
	Port_reg |= pins_mask;
	}
  else{
   Port_reg &= (~(pins_mask));
     }

}