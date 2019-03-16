#include "LCD.h"

void LCD_init(uint)
{
    LCD_command(DISPLAY_ON_CURSOR_OFF);
    LCD_command(FUNCTION_SET_8BIT_1LINE);
    LCD_command(ENTRY_MODE_LEFT_TO_RIGHT);
}