//KPM.c

#include <LPC21xx.h>                      // Includes LPC21xx microcontroller register definitions
#include "types.h"                        // Includes user-defined data types
#include "delay.h"                        // Includes delay function declarations
#include "defines.h"                      // Includes bit manipulation macros
#include "KPM_defines.h"                  // Includes keypad row and column pin definitions
#include "KPM.h"                          // Includes keypad function declarations
#include "LCD.h"                          // Includes LCD function declarations
#include "LCD_defines.h"                  // Includes LCD commands and pin definitions

// Keypad table to identify the pressed key
u8 kpmLUT[4][4]=
{
	{'7','8','9','/'},
	{'4','5','6','X'},
	{'1','2','3','-'},
	{'C','0','=','+'}
};

// Function to initialize the keypad
void InitKPM(void)
{
	// Configures all row pins as output
	SETBIT(IODIR1,ROW0);
	SETBIT(IODIR1,ROW1);
	SETBIT(IODIR1,ROW2);
	SETBIT(IODIR1,ROW3);

	// All column pins are configured as input by default
	// Column lines remain HIGH when no key is pressed
}

// Function to check the status of all column pins
u8 ColScan(void)
{
	u8 t;                                       // Variable to store the combined column status

	// Reads the status of all four column pins
	t=READBIT(IOPIN1,COL0)&
		READBIT(IOPIN1,COL1)&
		READBIT(IOPIN1,COL2)&
		READBIT(IOPIN1,COL3);

	return t;                                   // Returns 1 when no key is pressed and 0 when a key is pressed
}

// Function to identify which row key is pressed
u8 RowCheck(void)
{
	u8 r;                                       // Variable to store the pressed row number

	IOCLR1 = (1 << ROW0);                       // Makes ROW0 LOW
	IOSET1 = (1 << ROW1);                       // Makes ROW1 HIGH
	IOSET1 = (1 << ROW2);                       // Makes ROW2 HIGH
	IOSET1 = (1 << ROW3);                       // Makes ROW3 HIGH

	 // Checks whether a key is pressed in row 0
	if(ColScan() == 0)                         
	{
		r = 0;                                    // Stores row number as 0
		goto last;                                // Jumps to the last section
	}

	IOSET1 = (1 << ROW0);                       // Makes ROW0 HIGH
	IOCLR1 = (1 << ROW1);                       // Makes ROW1 LOW
	IOSET1 = (1 << ROW2);                       // Makes ROW2 HIGH
	IOSET1 = (1 << ROW3);                       // Makes ROW3 HIGH

	// Checks whether a key is pressed in row 1
	if(ColScan() == 0)                          
	{
		r = 1;                                    // Stores row number as 1
		goto last;                                // Jumps to the last section
	}

	IOSET1 = (1 << ROW0);                       // Makes ROW0 HIGH
	IOSET1 = (1 << ROW1);                       // Makes ROW1 HIGH
	IOCLR1 = (1 << ROW2);                       // Makes ROW2 LOW
	IOSET1 = (1 << ROW3);                       // Makes ROW3 HIGH

	// Checks whether a key is pressed in row 2
	if(ColScan() == 0)                          
	{
		r = 2;                                    // Stores row number as 2
		goto last;                                // Jumps to the last section
	}

	IOSET1 = (1 << ROW0);                       // Makes ROW0 HIGH
	IOSET1 = (1 << ROW1);                       // Makes ROW1 HIGH
	IOSET1 = (1 << ROW2);                       // Makes ROW2 HIGH
	IOCLR1 = (1 << ROW3);                       // Makes ROW3 LOW

	 // Checks whether a key is pressed in row 3
	if(ColScan() == 0)                         
	{
		r = 3;                                    // Stores row number as 3
	}

last:
	// Makes all row pins LOW after scanning
	IOCLR1 = (1 << ROW0);
	IOCLR1 = (1 << ROW1);
	IOCLR1 = (1 << ROW2);
	IOCLR1 = (1 << ROW3);

	return r;                                   // Returns the pressed row number
}

// Function to identify which column key is pressed
u8 ColCheck(void)
{
	u8 c;                                       // Variable to store the pressed column number

	if(READBIT(IOPIN1,COL0)==0)                 // Checks whether column 0 is LOW
			c=0;                                    // Stores column number as 0
	else if(READBIT(IOPIN1,COL1)==0)            // Checks whether column 1 is LOW
			c=1;                                    // Stores column number as 1
	else if(READBIT(IOPIN1,COL2)==0)            // Checks whether column 2 is LOW
			c=2;                                    // Stores column number as 2
	else if(READBIT(IOPIN1,COL3)==0)            // Checks whether column 3 is LOW
			c=3;                                    // Stores column number as 3

	return c;                                   // Returns the pressed column number
}

// Function to identify the pressed key
u8 KeyScan(void)
{
	u8 r,c,keyV;                                // Variables to store row, column and key values

	// Waits until any keypad key is pressed
	while(ColScan());             
	r=RowCheck();                               // Identifies the row in which the key is pressed
	c=ColCheck();                               // Identifies the column in which the key is pressed
	keyV=kpmLUT[r][c];                          // Gets the key value from the keypad lookup table

	return keyV;                                // Returns the pressed key value
}

// Function to read a multi-digit number from the keypad
u32 ReadNum(void)
{
	u32 keyV,sum=0;                             // Variables to store the pressed key and entered number
	
	// Repeats until a non-numeric key is pressed
	while(1)                     
	{
		keyV=KeyScan();                           // Scans the keypad and stores the pressed key

		delay_MS(300);                            // Adds a 300 ms delay between key operations

		// Checks whether the pressed key is a digit (0–9)
		if((keyV>='0') && (keyV<='9'))          
		{
			sum=(sum*10)+(keyV-'0');                // Converts the character into a number and adds it to sum

			Cmdlcd(GOTO_LINE2_POS0);                // Moves the LCD cursor to the beginning of the second line
			Strlcd("                ");             // Clears the second line using 16 blank spaces
			Cmdlcd(GOTO_LINE2_POS0);                // Moves the cursor back to the beginning of the second line
			u32lcd(sum);                            // Displays the entered number on the LCD

			while(ColScan()==0);                    // Waits until the pressed key is released
		}
		else if(keyV=='X')                        // Checks whether the backspace key (X) is pressed
		{
			sum=sum/10;                             // Removes the last digit from the entered number

			Cmdlcd(GOTO_LINE2_POS0);                // Moves the cursor to the beginning of the second line
			Strlcd("                ");             // Clears the second line
			Cmdlcd(GOTO_LINE2_POS0);                // Moves the cursor back to the beginning of the second line

		  // Checks whether any digits remain after backspace
			if(sum)                             
			{
				u32lcd(sum);                          // Displays the remaining number if it is non-zero
			}

			while(ColScan()==0);                    // Waits until the X key is released
		}
		else                                      // Executes when a non-numeric key other than X is pressed
		{
			if(keyV=='C')                           // Checks whether the clear key (C) is pressed
			{
				Cmdlcd(CLEAR_LCD);                    // Clears the complete LCD display
			}

			// Waits until the pressed key is released
			while(ColScan()==0);                

			break;                                  // Exits the loop and stops reading the number
		}
	}

	return sum;                                 // Returns the final entered number to the calling function
}

// Function to read a number and store the last pressed key
void ReadNum2(u32 *num,u8 *lastKey)
{
	u32 count=0;                                 // Variable to count the number of entered digits

	while(1)                                     // Repeats until a non-numeric key is pressed
	{
		*lastKey=KeyScan();                        // Reads the pressed key and stores it in lastKey

		// Checks for a digit and limits input to 4 digits
		if(((*lastKey>='0')&&(*lastKey<='9')) && (count<4))  
		{
			*num=(*num * 10)+(*lastKey-'0');         // Converts the character into a number and adds it to num

			Cmdlcd(GOTO_LINE2_POS0+count++);         // Moves the LCD cursor to the next position
			Charlcd('*');                            // Displays * instead of the actual entered digit

			while(ColScan()==0);                     // Waits until the pressed key is released
		}
		else
		{
			if(*lastKey=='C')                        // Checks whether the clear key (C) is pressed
			{
					Cmdlcd(CLEAR_LCD);                   // Clears the LCD display
			}

			while(ColScan()==0);                     // Waits until the pressed key is released

			break;                                   // Stops reading the number
		}
	}
}
