#include "lcd.h"
void LCD_init(uint)
{
		LCD_command(CLEAR);
    LCD_command(DISPLAY_ON_CURSOR_OFF);
    LCD_command(FUNCTION_SET_8BIT_2LINE);
    LCD_command(ENTRY_MODE_LEFT_TO_RIGHT);
}
void LCD_command(char command)
{
	DIO_WritePort(PORTA, 0xE0, STD_LOW);//command mode(RS = 0), wirte mode (RW = 0), ENABLE = 0
	GPIO_PORTB_DATA_R = command;
	//Latch
	DIO_WritePort(PORTA, ENABLIE_BIT, STD_HIGH);// set Enable bit
	delay(2);
	DIO_WritePort(PORTA, ENABLIE_BIT, STD_LOW); // clear Enable bit
	delay(2);
}
void LCD_data(char data)
{
	DIO_WritePort(PORTA, 0x60, STD_LOW);// wirte mode (RW = 0), ENABLE = 0
	DIO_WritePort(PORTA, RS_BIT, STD_HIGH);// data mode(RS = 0)
	GPIO_PORTB_DATA_R = data;
	//Latch
	DIO_WritePort(PORTA, ENABLIE_BIT, STD_HIGH); // set Enable bit
	delay(2);
	DIO_WritePort(PORTA, ENABLIE_BIT, STD_LOW); // clear Enable bit
	delay(2);
}
void LCD_print(uint16 counter)
{
	LCD_command(CLEAR);
	LCD_data((uint8)((counter / 100) + 48));
	LCD_data((uint8)(((counter%100) / 10) + 48));
	LCD_data((uint8)((counter%10) + 48));
}