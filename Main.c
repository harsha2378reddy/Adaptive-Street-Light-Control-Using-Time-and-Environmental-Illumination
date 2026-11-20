//Main.c

#include <LPC21xx.h>                             // Includes LPC21xx microcontroller register definitions
#include "types.h"                               // Includes user-defined data types
#include "LCD.h"                                 // Includes LCD function declarations
#include "LCD_defines.h"                         // Includes LCD commands and pin definitions
#include "ADC.h"                                 // Includes ADC function declarations
#include "KPM.h"                                 // Includes keypad function declarations
#include "RTC.h"                                 // Includes RTC function declarations
#include "INT.h"                                 // Includes external interrupt function declarations
#include "LED.h"                                 // Includes LED function declarations
#include "menu.h"                                // Includes menu function declarations
#include "delay.h"                               // Includes delay function declarations

#define LDR_THRESHOLD 500                        // Defines the threshold value for detecting darkness

// Function to check whether the current time is within streetlight ON time
u8 IsNightTime(void)
{
	u32 Current_time;                              // Stores current time in minutes
	u32 ON_TIME;                                   // Stores streetlight ON time in minutes
	u32 OFF_TIME;                                  // Stores streetlight OFF time in minutes

	Current_time = (HOUR * 60) + MIN;              // Converts current hours and minutes into total minutes

	ON_TIME = (ON_HOUR * 60) + ON_MIN;             // Converts ON schedule into total minutes
	OFF_TIME = (OFF_HOUR * 60) + OFF_MIN;          // Converts OFF schedule into total minutes

	// Checks if ON time is earlier than OFF time
	if(ON_TIME < OFF_TIME)
	{
		// Checks whether current time is between ON time and OFF time
		if(Current_time >= ON_TIME && Current_time < OFF_TIME)
		{
			return 1;                                  // Returns 1 if it is within the scheduled time
		}
		else
		{
			return 0;                                  // Returns 0 if it is outside the scheduled time
		}
	}

	// Checks if the ON schedule crosses midnight
	else if(ON_TIME > OFF_TIME)
	{
		// Checks whether current time is after ON time OR before OFF time
		if(Current_time >= ON_TIME || Current_time < OFF_TIME)
		{
			return 1;                                  // Returns 1 if it is within the scheduled time
		}
		else
		{
			return 0;                                  // Returns 0 if it is outside the scheduled time
		}
	}

	return 0;                                      // Returns 0 if ON time and OFF time are equal
}

// Main function: execution of the streetlight project starts here
int main()
{
	u16 ADC_value;                                 // Stores the digital value received from ADC
	f32 voltage;                                   // Stores the converted analog voltage
	u8 night;                                      // Stores the result of IsNightTime()
	u8 LDR_value = 0;                              // Stores the previous LDR condition to avoid repeated buzzer alerts

	// Initialize all project peripherals
	Initlcd();                                     // Initializes the LCD
	Init_RTC();                                    // Initializes the Real Time Clock
	Init_ADC();                                    // Initializes the ADC
	InitKPM();                                     // Initializes the keypad
	Init_LED();                                    // Initializes LEDs and buzzer
	Init_Interrupt();                              // Initializes external interrupt

	// Displays the project title on LCD
	Cmdlcd(CLEAR_LCD);                             // Clears the LCD display
	Strlcd("ADAPTIVE STREET");                     // Displays the first line
 
	Cmdlcd(GOTO_LINE2_POS0);                       // Moves the cursor to the second line
	Strlcd("LIGHT CONTROL");                       // Displays the second line

	delay_S(1);                                    // Waits for 2 seconds

	// Runs continuously
	while(1)
	{
		// Checks whether the external interrupt has activated the menu
		if(menu_flag == 1)
		{
			menu_flag = 0;                             // Clears the menu flag
			Menu();                                    // Calls the menu function
			LDR_value = 0;                             // Resets the previous LDR condition
			continue;                                  // Skips the remaining statements and starts the next loop
		}
		
		Read_ADC(1, &ADC_value, &voltage); 	 				 // Reads ADC channel 1 and gets digital value and voltage

		// Checks whether the current time is within the scheduled streetlight time
		night = IsNightTime();

		// Checks whether it is within the scheduled ON time
		if(night)
		{
			// Checks whether the LDR digital value is below the threshold
			if(ADC_value > LDR_THRESHOLD)
			{
				Streetlight_ON();                        // Switches ON all streetlight LEDs

				// Checks whether the previous LDR condition was not DARK
				if(LDR_value != 1)
				{
					LDR_value = 1;                         // Stores DARK condition

					Buzzer_Beep();                         // Gives a buzzer sound when the condition changes

					Cmdlcd(CLEAR_LCD);                     // Clears the LCD
					Cmdlcd(GOTO_LINE1_POS0);               // Moves cursor to first line
					Strlcd("LDR :");                       // Displays LDR label
					u32lcd(ADC_value);                     // Displays the ADC digital value
					Strlcd("  DARK  ");                    // Displays DARK condition

					Cmdlcd(GOTO_LINE2_POS0);               // Moves cursor to second line
					Strlcd("LIGHT : ON");                  // Displays streetlight ON status

					delay_S(1);                            // Displays the information for 1 second
					Cmdlcd(CLEAR_LCD);                     // Clears the LCD
				}
		}
		else
		{
			Streetlight_OFF();                         // Switches OFF all streetlight LEDs

			// Checks whether the previous LDR condition was not BRIGHT
			if(LDR_value != 2)
			{
				LDR_value = 2;                           // Stores BRIGHT condition

				Buzzer_Beep();                           // Gives a buzzer sound when the condition changes

				Cmdlcd(CLEAR_LCD);                       // Clears the LCD
				Cmdlcd(GOTO_LINE1_POS0);                 // Moves cursor to first line
				Strlcd("LDR :");                         // Displays LDR label
				u32lcd(ADC_value);                       // Displays the ADC digital value
				Strlcd(" BRIGHT ");                      // Displays BRIGHT condition

				Cmdlcd(GOTO_LINE2_POS0);                 // Moves cursor to second line
				Strlcd("LIGHT : OFF");                   // Displays streetlight OFF status

				delay_S(1);                              // Displays the information for 1 second
				Cmdlcd(CLEAR_LCD);                       // Clears the LCD
			}
		}
		
		RTC_Display();                               // Displays current time, day and date on LCD
		}
		else
		{
			Streetlight_OFF();                         // Switches OFF streetlight LEDs outside scheduled time
			LDR_value = 0;                             // Resets the previous LDR condition
			RTC_Display();                             // Displays current time, day and date on LCD
		}

		delay_S(1);                                  // Adds a 1-second delay before the next loop iteration
	}
}

