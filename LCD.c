//LCD.c

#include "types.h"                            // Includes user-defined data types
#include <LPC21xx.h>                          // Includes LPC21xx microcontroller register definitions
#include "LCD_defines.h"                      // Includes LCD commands and pin definitions
#include "defines.h"                          // Includes bit manipulation macros
#include "delay.h"                            // Includes delay function declarations
#include "LCD.h"                              // Includes LCD function declarations

// Function to send 8-bit data to LCD
void Writelcd(u8 dat)
{
	WRITEBYTE(IOPIN0, LCD_DATA, dat);           // Sends 8-bit data to LCD data pins

	IOCLR0 = (1 << LCD_RW);                     // Makes RW pin LOW to select write operation
	IOSET0 = (1 << LCD_EN);                     // Makes Enable pin HIGH
	delay_US(1);                                // Provides a small delay for LCD to read data

	IOCLR0 = (1 << LCD_EN);        				      // Makes Enable pin LOW to complete data transfer
	delay_MS(2);                                // Waits for the LCD operation to complete
}

// Function to send commands to LCD
void Cmdlcd(u8 cmd)
{
	IOCLR0 = (1 << LCD_RS);                     // Makes RS pin LOW to select the command register
	Writelcd(cmd);                              // Sends the command to LCD
}

// Function to display a single character on LCD
void Charlcd(u8 asciival)
{
	IOSET0 = (1 << LCD_RS);                     // Makes RS pin HIGH to select the data register
	Writelcd(asciival);                         // Sends the character to LCD
}

// Function to initialize LCD
void Initlcd(void)
{
	IODIR0 |= ((0xFF << LCD_DATA) |             // Configures 8 LCD data pins as output
						 (1 << LCD_RS) |                  // Configures RS pin as output
						 (1 << LCD_RW) |                  // Configures RW pin as output
						 (1 << LCD_EN));                  // Configures Enable pin as output

	delay_MS(15);                               // Waits for LCD power-on initialization
	Cmdlcd(0x30);                               // Sends the command to initialize LCD in 8-bit mode
	delay_MS(4);                                // Waits for the LCD to respond
	delay_US(100);                              // Provides a small delay
	Cmdlcd(0x30);                               // Sends the initialization command again
	delay_US(100);                              // Waits for the LCD to respond
	Cmdlcd(0x30);                               // Sends the initialization command once again

	Cmdlcd(MODE_8BIT_2LINE);                    // Selects 8-bit mode and 2-line LCD display
	Cmdlcd(DSP_ON_CUR_OFF);                     // Turns ON the display and turns OFF the cursor
	Cmdlcd(CLEAR_LCD);                          // Clears the LCD display
	Cmdlcd(SHIFT_CUR_RIGHT);                    // Sets the cursor movement direction to the right
}

// Function to display a string on LCD
void Strlcd(s8 *s)
{
	// Repeats until the null character is reached
	while(*s)                                     
	{
			Charlcd(*s++);                          // Displays the current character and moves to the next character
	}
}

// Function to display an unsigned 32-bit number on LCD
void u32lcd(u32 n)
{
	u8 a[10];                                   // Array to store the digits of the number
	s32 i = 0;                                  // Variable to track the array index
  
	// Checks whether the given number is zero
	if(n == 0)                                  
	{
		Charlcd('0');                             // Displays zero on LCD
	}
	else
	{
		// Repeats until all digits are extracted
		while(n > 0)                    
		{
			a[i] = (n % 10) + 48;                   // Extracts the last digit and converts it to ASCII
			n /= 10;                                // Removes the last digit from the number
			i++;                                    // Moves to the next array position
		}
    // Reads the stored digits in reverse order
		for(--i; i >= 0; i--)           
		{
			Charlcd(a[i]);                          // Displays each digit on LCD
		}
	}
}
