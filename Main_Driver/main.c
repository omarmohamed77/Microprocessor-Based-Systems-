#include "DIO.h"
#include "LCD.h"
#include "port.h"
#include "delay.h"

#define PORTA_INDEX					0
#define PORTB_INDEX					1
#define ENABLE						  1
#define RST_BUTTON					0x10U		// Pin 4 is connected to increment switch
#define DEC_BUTTON					0x08U		// Pin 3 is connected to decrement switch
#define INC_BUTTON					0x04U		// Pin 2 is connected to Reset switch
#define PUSH_BUTTONS				0x1CU 	//Pins 0 and 4 are connected to Input Switches

void SystemInit(void){
	PORT_INT(PORTA_INDEX);
	PORT_INT(PORTB_INDEX);
	Port_SetPinDirection(PORTB_INDEX, 0xFF, PORT_PIN_OUT);
	Port_SetPinDirection(PORTA_INDEX, PUSH_BUTTONS, PORT_PIN_IN);
	Port_SetPinDirection(PORTA_INDEX, 0xE0, PORT_PIN_OUT);
	LCD_init();
	Port_SetPinPullUp(PORTA_INDEX,PUSH_BUTTONS, ENABLE);
}

int main(void){
	uint8 data;
	uint16 counter = 0;
	LCD_data(48);
	LCD_data(48);
	LCD_data(48);
	while(1){
		data = DIO_ReadPort(PORTA_INDEX, PUSH_BUTTONS);
		if(data == 0x18U){
			delay(20);
			data = DIO_ReadPort(PORTA_INDEX, PUSH_BUTTONS);
			if(data == 0x18U){
				// LCD Increment
				counter = (counter+1)%1000;
				LCD_command(CLEAR);
				LCD_data((uint8)((counter / 100) + 48));
				LCD_data((uint8)(((counter%100) / 10) + 48));
				LCD_data((uint8)((counter%10) + 48));
				delay(180);
			}
		}
		else if(data == 0x14U){
			delay(20);
			if(data == 0x14U){
				// LCD Decrement
				if(counter > 0)
					counter--;
				LCD_command(CLEAR);
				LCD_data((uint8)((counter / 100) + 48));
				LCD_data((uint8)(((counter%100) / 10) + 48));
				LCD_data((uint8)((counter%10) + 48));
			}
			while(data == 0x14U){
				data = DIO_ReadPort(PORTA_INDEX, PUSH_BUTTONS);
			}
		}
		else if(data == 0x0CU){
			delay(20);
			while(data == 0x0CU){
				data = DIO_ReadPort(PORTA_INDEX, PUSH_BUTTONS);
			}		
			// LCD Reset
			counter = 0;
			LCD_command(CLEAR);
			LCD_data(counter + 48);
			LCD_data(counter + 48);
			LCD_data(counter + 48);
		}
	}
}
