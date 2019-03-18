#include "mcal.h"
#include "delay.h"

void Button_Operation_Mode(uint8 port_index, uint8 button, uint8 operation)
{
	static uint8 out = 0x02U;
	switch (port_index)
	{
		case 0 :                                                     // Port A
			break ;
		
		case 1 :                                                     // Port B
			break ;
		
		case 2 :                                                      // Port C
			break ;
		
		case 3 :                                                    // Port D
			break ;
		
		case 4 :                                                    // Port E
			break ;
		
		case 5 :                                                   // Port F
          if(operation==1)
			{
				delay(200);
				if(DIO_ReadPort(port_index, button) != button){
					if(out == button){
						out = 0x02U; // Reset led_out to red after green
					}
					else if(out == (button>>4)){
						out = 0x04U;
					}
					GPIO_PORTF_DATA_R &= ~(0x0EU); // reset all to off
					GPIO_PORTF_DATA_R |= out;	
					out <<= 1;					
				}					
			}                          				
			else if(operation==2)
			{
				if(out == button){
					out = 0x08U; // Reset led_out to red after green
				}
				else if(out == (button<<4)){
					out = 0x04U;
				}
				GPIO_PORTF_DATA_R &= ~(0x0EU); // reset all to off
				GPIO_PORTF_DATA_R |= out;	
				out >>= 1;					
				delay(200);
				while(DIO_ReadPort(port_index, button) != button);
			}
			else if(operation==3)
			{
				delay(200);
				while(DIO_ReadPort(port_index, button) != button);
				GPIO_PORTF_DATA_R &= ~(0x0EU); // reset all to off
			}							
			break ;
   }
}
