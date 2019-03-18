#include "mcal.h"

uint8 DIO_ReadPort(uint8 port_index, uint8 pins_mask)
{
	switch (port_index)
	{
		case 0 :                                        // Port A
			return GPIO_PORTA_DATA_R&pins_mask;
		
		case 1 :                                        // Port B
			return GPIO_PORTB_DATA_R&pins_mask;	
		
		case 2 :                                        // Port C
			return GPIO_PORTC_DATA_R&pins_mask;		
		
		case 3 :                                        // Port D
			return GPIO_PORTD_DATA_R&pins_mask;					                                   
		
		case 4 :                                        // Port E
			return GPIO_PORTE_DATA_R&pins_mask;							
		
		case 5 :                                        // Port F
			return GPIO_PORTF_DATA_R&pins_mask;				
			
		/*default :
			return GPIO_PORTF_DATA_R&pins_mask;*/
   }
}
