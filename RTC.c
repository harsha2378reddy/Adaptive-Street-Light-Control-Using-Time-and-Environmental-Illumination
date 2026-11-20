//RTC.c

#include <LPC21xx.h>                    // Includes LPC21xx microcontroller register definitions
#include "types.h"                      // Includes user-defined data types
#include "RTC.h"                        // Includes RTC function declarations
#include "LCD.h"                        // Includes LCD function declarations
#include "LCD_defines.h"                // Includes LCD commands and pin definitions

// Function to initialize RTC
void Init_RTC(void)
{
	if((CCR & 0x01) == 0)
	{
		CCR = 0x02;                         // Resets RTC clock divider
 
	 	CIIR = 0;                           // Disables RTC interrupts

		PREINT = 456;                       // Loads integer prescaler value
		PREFRAC = 25024;                    // Loads fractional prescaler value

		SEC = 50;                           // Sets initial seconds
		MIN = 59;                           // Sets initial minutes
		HOUR = 23;                          // Sets initial hours

		DOM = 10;                           // Sets initial date
		MONTH = 11;                         // Sets initial month
		YEAR = 2026;                        // Sets initial year
		DOW = 2;                            // Sets initial day

		CCR = (1 << 0);                     // Enables internal RTC clock
	}
}

// Function to set RTC time
void RTC_SetTime(u32 hour, u32 minute, u32 second)
{
	// Checks whether the given time values are within valid range
	if(hour < 24 && minute < 60 && second < 60)
	{
		SEC = second;                       // Sets the seconds value
		MIN = minute;                       // Sets the minutes value
		HOUR = hour;                        // Sets the hours value
	}
}

// Function to set RTC date
void RTC_SetDate(u32 date, u32 month, u32 year, u32 day)
{
	// Checks whether the given date and time values are valid
	if(date >= 1 && date <= 31 &&
		 month >= 1 && month <= 12 &&
		 year >= 2000 && year <= 2099 &&
		 day <= 6)
	{
		DOM = date;                          // Sets the date
		MONTH = month;                       // Sets the month
		YEAR = year;                         // Sets the year
		DOW = day;                           // Sets the day of the week
	}
}

// Function to display time on LCD
void displaytime(void)
{
	Charlcd((HOUR / 10) + 48);             // Displays the tens digit of hours
	Charlcd((HOUR % 10) + 48);             // Displays the units digit of hours
	Charlcd(':');                          // Displays colon separator

	Charlcd((MIN / 10) + 48);              // Displays the tens digit of minutes
	Charlcd((MIN % 10) + 48);              // Displays the units digit of minutes
	Charlcd(':');                          // Displays colon separator

	Charlcd((SEC / 10) + 48);              // Displays the tens digit of seconds
	Charlcd((SEC % 10) + 48); 						 // Displays the units digit of seconds
}

// Function to display date on LCD
void displaydate(void)
{
	Charlcd((DOM / 10) + 48);         		 // Displays the tens digit of date
	Charlcd((DOM % 10) + 48);          		 // Displays the units digit of date
	Charlcd('-');                          // Displays hyphen separator

	Charlcd((MONTH / 10) + 48);            // Displays the tens digit of month
	Charlcd((MONTH % 10) + 48);            // Displays the units digit of month
	Charlcd('-');                          // Displays hyphen separator

	Charlcd((YEAR / 1000) + 48);           // Displays the thousands digit of year
	Charlcd(((YEAR / 100) % 10) + 48);     // Displays the hundreds digit of year
	Charlcd(((YEAR / 10) % 10) + 48);      // Displays the tens digit of year
	Charlcd((YEAR % 10) + 48);             // Displays the units digit of year
}

// Function to display complete RTC time and date on LCD
void RTC_Display(void)
{
	Cmdlcd(GOTO_LINE1_POS0);               // Moves LCD cursor to the first line

	displaytime();                         // Displays time(hours, minutes and seconds)

	Charlcd(' ');                          // Displays a space after the time

	if(DOW == 0)                           // Checks the day is Sunday
	{
			Strlcd("SUN");                     // Displays SUN on LCD
	}
	else if(DOW == 1)                      // Checks whether the day is Monday
	{
		Strlcd("MON");                       // Displays MON on LCD
	}
	else if(DOW == 2)                      // Checks whether the day is Tuesday
	{
		Strlcd("TUE");                       // Displays TUE on LCD
	}
	else if(DOW == 3)                      // Checks whether the day is Wednesday
	{
		Strlcd("WED");                       // Displays WED on LCD
	}
	else if(DOW == 4)                      // Checks whether the day is Thursday
	{
		Strlcd("THU");                       // Displays THU on LCD
	}
	else if(DOW == 5)                      // Checks whether the day is Friday
	{
		Strlcd("FRI");                       // Displays FRI on LCD
	}
	else                                   // Executes when the day value is 6
	{
		Strlcd("SAT");                       // Displays SAT on LCD
	}
	
	Strlcd("    ");                        // Displays four spaces to clear old characters.
	Cmdlcd(GOTO_LINE2_POS0);               // Moves LCD cursor to the second line.
	
	displaydate();                         // Displays date, month and year.
	
	Strlcd("      ");                      // Displays six spaces to clear old characters.
}
