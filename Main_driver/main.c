#include "mcal.h"
#include "Button_Modes.h"

#define PORTF_INDEX					5
#define INPUT						  	0
#define OUTPUT						  1
#define GPIO_PF321_M				0x0EU 	//Pins 3, 2 and 1 are connected to RGB LED
#define GPIO_PF4_M					0x10U		// Pin 4 is connected to switch_1
#define GPIO_PF3_M					0x08U		// Pin 3 is connected to green	
#define GPIO_PF2_M					0x04U		// Pin 2 is connected to blue
#define GPIO_PF1_M					0x02U		// Pin 1 is connected to red
#define GPIO_PF0_M					0x01U		// Pin 4 is connected to switch_2
#define GPIO_PF40_M					0x11U 	//Pins 0 and 4 are connected to Input Switches

void SystemInit(void){
	PORT_INT(PORTF_INDEX);
	Port_SetPinDirection(PORTF_INDEX, GPIO_PF321_M, OUTPUT);
	Port_SetPinDirection(PORTF_INDEX, GPIO_PF40_M, INPUT);
	Port_SetPinPullUp(PORTF_INDEX,GPIO_PF40_M, 1);
}

int main(void){
	unsigned char data;
	for(;;){
		data = DIO_ReadPort(PORTF_INDEX, GPIO_PF40_M);
		if(data == GPIO_PF0_M){
			Button_Operation_Mode(PORTF_INDEX, GPIO_PF4_M, 1);
		}
		else if(data == GPIO_PF4_M){
			Button_Operation_Mode(PORTF_INDEX, GPIO_PF0_M, 2);
		}
	}
}
