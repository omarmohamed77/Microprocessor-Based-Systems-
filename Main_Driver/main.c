#include "DIO.h"
#include "LCD.h"
#include "port.h"
#include "delay.h"

#define PORTA_INDEX					0
#define PORTB_INDEX					1
#define RST_BUTTON					0x0CU		// Pin 4 is connected to increment switch
#define DEC_BUTTON					0x14U		// Pin 3 is connected to decrement switch
#define INC_BUTTON					0x18U		// Pin 2 is connected to Reset switch
#define PUSH_BUTTONS					0x1CU 	//Pins 0 and 4 are connected to Input Switches

void SystemInit(void){
	PORT_INT(PORTA_INDEX);
	PORT_INT(PORTB_INDEX);
	Port_SetPinDirection(PORTB_INDEX, 0xFF, PORT_PIN_OUT);
	Port_SetPinDirection(PORTA_INDEX, PUSH_BUTTONS, PORT_PIN_IN);
	Port_SetPinDirection(PORTA_INDEX, 0xE0, PORT_PIN_OUT);
	LCD_init();
	Port_SetPinPullUp(PORTA_INDEX,PUSH_BUTTONS, STD_HIGH);
}

int main(void){
	uint8 Data_IN;
	uint16 counter = 0;
	LCD_print(counter);
	while(1){
		Data_IN = DIO_ReadPort(PORTA_INDEX, PUSH_BUTTONS);
		if(Data_IN == INC_BUTTON){
			delay(200);
			Data_IN = DIO_ReadPort(PORTA_INDEX, PUSH_BUTTONS);
			if(Data_IN == INC_BUTTON){
				// LCD Increment
				counter = (counter+1)%1000;
				LCD_print(counter);
				// delay(180);
			}
		}
		else if(Data_IN == DEC_BUTTON){
			delay(20);
			if(Data_IN == DEC_BUTTON){
				// LCD Decrement
				if(counter > 0)
					counter--;
				LCD_print(counter);
			}
			while(Data_IN == DEC_BUTTON){
				Data_IN = DIO_ReadPort(PORTA_INDEX, PUSH_BUTTONS);
			}
		}
		else if(Data_IN == RST_BUTTON){
			delay(20);
			while(Data_IN == RST_BUTTON){
				Data_IN = DIO_ReadPort(PORTA_INDEX, PUSH_BUTTONS);
			}		
			// LCD Reset
			counter = 0;
			LCD_print(counter);
		}
	}
}
