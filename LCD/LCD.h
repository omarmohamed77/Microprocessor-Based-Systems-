#define CLEAR 0x01                    // clear the display & reset the cursor to address 00 H position
#define RESET 0x03                    // return the cursor to address 00 H position
#define RIGHT_DIR 0x14                // cursor moves to right
#define LEFT_DIR 0x10                 // cursor moves to left
#define DISPLAY_OFF 0x08              // turn off the display
#define DISPLAY_ON_CURSOR_OFF 0x0C    // turn on the display & open cursor & cursor flashing
#define FUNCTION_SET_8BIT_1LINE 0x30  // display setting: 8 bit, 1 line, 5x8 dots font
#define ENTRY_MODE_LEFT_TO_RIGHT 0x06 //cursor moving direction from

#include "std_types.h"
#include "../port driver/mcal.h"
#include "delay.h"

void LCD_init();
void LCD_command(char command);