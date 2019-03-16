#include "tm4c123gh6pm.h"
#include "std_types.h"

#define GPIO_PF321_M				0x0EU 	//Pins 3, 2, and 1 are connected to RGB LED
#define GPIO_PF4_M					0x10U		// Pin 4 is connected to switch
#define GPIO_PF3_M					0x08U		// Pin 3 is connected to green	
#define GPIO_PF2_M					0x04U		// Pin 2 is connected to blue
#define GPIO_PF1_M					0x02U		// Pin 1 is connected to red
#define GPIO_PCTL_PF321_M		(GPIO_PCTL_PF3_M | GPIO_PCTL_PF2_M | GPIO_PCTL_PF1_M) // To combine masks, OR them together
typedef volatile unsigned long       vuint32;  /* 0 to 4,294,967,295*/

void RGBLED_Init(void);
void SW1_Init(void);
uint8 SW1_Input(void);
void RGB_Output(unsigned char out);

void SystemInit(void){
	SW1_Init();
	RGBLED_Init();
}

int main(void){
	uint8 in;
	uint8 led_out = GPIO_PF1_M; // Initalize LED to be red when button pressed first time
	for(;;){
		if(led_out == GPIO_PF4_M){
			led_out = GPIO_PF1_M; // Reset led_out to red after green
		}
		in = SW1_Input();
		if(in != GPIO_PF4_M){ // if switch is pressed in = 0x00
			RGB_Output(led_out);
			led_out <<= 1;			// shift left to next color
		}
	}
}

void RGBLED_Init(void){
	vuint32 delay;
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;  // PortF clock enable
  delay = SYSCTL_RCGCGPIO_R;        				// Delay   
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;   			// Unlock PortF Commit register  
  GPIO_PORTF_CR_R |= GPIO_PF321_M;          // Allow changes to PF321       
  GPIO_PORTF_AMSEL_R &= ~GPIO_PF321_M;      // Disable analog function
  GPIO_PORTF_PCTL_R &= ~GPIO_PCTL_PF321_M;  // GPIO clear bit PCTL  
  GPIO_PORTF_AFSEL_R &= ~GPIO_PF321_M;      // No alternate function
	GPIO_PORTF_DIR_R |= GPIO_PF321_M;         // PF321 output
  GPIO_PORTF_DEN_R |= GPIO_PF321_M;         // Enable digital pins PF4-PF0
  GPIO_PORTF_DATA_R &= ~GPIO_PF321_M;				// Initalize LEDs to be off
}

void SW1_Init(void){
	vuint32 delay;
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;  
  delay = SYSCTL_RCGCGPIO_R;        				
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;   			  
  GPIO_PORTF_CR_R |= GPIO_PF4_M;          	 
  GPIO_PORTF_AMSEL_R &= ~GPIO_PF4_M;      
  GPIO_PORTF_PCTL_R &= ~GPIO_PCTL_PF4_M;  
  GPIO_PORTF_AFSEL_R &= ~GPIO_PF4_M;      
	GPIO_PORTF_DIR_R &= ~GPIO_PF4_M;
	GPIO_PORTF_PUR_R |= GPIO_PF4_M;
  GPIO_PORTF_DEN_R |= GPIO_PF4_M;			
}

uint8 SW1_Input(void){
	return GPIO_PORTF_DATA_R&GPIO_PF4_M;
}

void RGB_Output(uint8 out){
	GPIO_PORTF_DATA_R &= ~GPIO_PF321_M; // reset all to off
	GPIO_PORTF_DATA_R |= out;
}
