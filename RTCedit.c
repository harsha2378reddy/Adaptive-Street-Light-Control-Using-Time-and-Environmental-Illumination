//RTCedit.c

#include <LPC214x.h>                                      // Includes LPC214x microcontroller register definitions
#include "types.h"                                        // Includes user-defined data types
#include "LCD.h"                                          // Includes LCD function declarations
#include "LCD_defines.h"                                  // Includes LCD commands and pin definitions
#include "KPM.h"                                          // Includes keypad function declarations
#include "RTC.h"                                          // Includes RTC function declarations
#include "RTCedit.h"                                      // Includes RTC editing function declarations
#include "delay.h"                                        // Includes delay function declarations

// Global variables to store street-light ON and OFF timings
u32 ON_HOUR = 18;                                         // Default street-light ON hour
u32 ON_MIN = 0;                                           // Default street-light ON minute

u32 OFF_HOUR = 6;                                         // Default street-light OFF hour
u32 OFF_MIN = 0;                                          // Default street-light OFF minute

// Function to edit RTC hour
void Edit_Hour(void)
{
	u32 hour;                                               // Variable to store the entered hour

Hour:                                                     // Label used to repeat input if the entered hour is invalid

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("ENTER HOUR");                                   // Displays the hour input message

	hour = ReadNum();                                       // Reads the hour value from the keypad

	// Checks whether the entered hour is within the valid range (0-23)
	if(hour >= 24)
	{
		Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
		Strlcd("INVALID HOUR");                               // Displays an error message
		delay_MS(500);                                        // Provides a delay to view the error message
		goto Hour;                                            // Returns to the Hour label to enter again
	}

	RTC_SetTime(hour, MIN, SEC);                            // Updates hour while keeping existing minutes and seconds

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("HOUR UPDATED");                                 // Displays the update confirmation message
	delay_MS(500);                                          // Provides a delay to view the message
}

// Function to edit RTC minutes
void Edit_Minute(void)
{
	u32 minute;                                             // Variable to store the entered minutes

Minute:                                                   // Label used to repeat input if the entered minute is invalid

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("ENTER MINUTE");                                 // Displays the minute input message

	minute = ReadNum();                                     // Reads the minute value from the keypad

	// Checks whether the entered minute is within the valid range (0-59)
	if(minute >= 60)
	{
		Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
		Strlcd("INVALID MINUTE");                             // Displays an error message
		delay_MS(500);                                        // Provides a delay to view the error message
		goto Minute;                                          // Returns to the Minute label to enter again
	}

	RTC_SetTime(HOUR, minute, SEC);                         // Updates minutes while keeping existing hour and seconds

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("MIN UPDATED");                                  // Displays the update confirmation message
	delay_MS(500);                                          // Provides a delay to view the message
}

// Function to edit RTC seconds
void Edit_Second(void)
{
	u32 second;                                             // Variable to store the entered seconds

Second:                                                   // Label used to repeat input if the entered second is invalid

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("ENTER SECOND");                                 // Displays the second input message

	second = ReadNum();                                     // Reads the second value from the keypad

	// Checks whether the entered second is within the valid range (0-59)
	if(second >= 60)
	{
		Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
		Strlcd("INVALID SECOND");                             // Displays an error message
		delay_MS(500);                                        // Provides a delay to view the error message
		goto Second;                                          // Returns to the Second label to enter again
	}

	RTC_SetTime(HOUR, MIN, second);                         // Updates seconds while keeping existing hour and minutes

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("SEC UPDATED");                                  // Displays the update confirmation message
	delay_MS(500);                                          // Provides a delay to view the message
}

// Function to edit calendar date
void Edit_Date(void)
{
	u32 date;                                               // Variable to store the entered date

Date:                                                     // Label used to repeat input if the entered date is invalid

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("ENTER DATE");                                   // Displays the date input message

	date = ReadNum();                                       // Reads the date value from the keypad

	// Checks whether the entered date is within the valid range (1-31)
	if(date < 1 || date > 31)
	{
		Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
		Strlcd("INVALID DATE");                               // Displays an error message
		delay_MS(500);                                        // Provides a delay to view the error message
		goto Date;                                            // Returns to the Date label to enter again
	}

	RTC_SetDate(date, MONTH, YEAR, DOW);                    // Updates date while keeping existing month, year and day

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("DATE UPDATED");                                 // Displays the update confirmation message
	delay_MS(500);                                          // Provides a delay to view the message
}

// Function to edit calendar month
void Edit_Month(void)
{
	u32 month;                                              // Variable to store the entered month

Month:              																		  // Label used to repeat input if the entered month is invalid
 
	Cmdlcd(CLEAR_LCD); 		  																// Clears the LCD display
	Strlcd("ENTER MONTH"); 	  															// Displays the month input message

	month = ReadNum(); 				  														// Reads the month value from the keypad

	// Checks whether the entered month is within the valid range (1-12)
	if(month < 1 || month > 12)
	{
		Cmdlcd(CLEAR_LCD); 				    												// Clears the LCD display
		Strlcd("INVALID MONTH"); 			    										// Displays an error message
		delay_MS(500);   									    							  // Provides a delay to view the error message
		goto Month;      											    					  // Returns to the Month label to enter again
	}

	RTC_SetDate(DOM, month, YEAR, DOW);                 		// Updates month while keeping existing date, year and day

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("MONTH UPDATED"); 												  			// Displays the update confirmation message
	delay_MS(500);   																	  	  // Provides a delay to view the message
}

// Function to edit day of the week
void Edit_Day(void)
{
	u32 day;       																		      // Variable to store the entered day of the week

Day:                																	    // Label used to repeat input if the entered day is invalid

	Cmdlcd(CLEAR_LCD);					    												// Clears the LCD display
	Strlcd("DAY 0-SUN TO 6");	    													// Displays the valid day values

	day = ReadNum();  																   	  // Reads the day value from the keypad

	// Checks whether the entered day is within the valid range (0-6)
	if(day > 6)
	{
		Cmdlcd(CLEAR_LCD); 															      // Clears the LCD display
		Strlcd("INVALID DAY"); 													      // Displays an error message
		delay_MS(500);                                        // Provides a delay to view the error message
		goto Day;                                             // Returns to the Day label to enter again
	}

	RTC_SetDate(DOM, MONTH, YEAR, day);                     // Updates day of the week while keeping other date values

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("DAY UPDATED");                                  // Displays the update confirmation message
	delay_MS(500);                                          // Provides a delay to view the message
}


// Function to edit calendar year
void Edit_Year(void)
{
	u32 year;                                               // Variable to store the entered year

Year:                                                     // Label used to repeat input if the entered year is invalid

	Cmdlcd(CLEAR_LCD);                                      // Clears the LCD display
	Strlcd("ENTER YEAR");                                   // Displays the year input message

	year = ReadNum();                                       // Reads the year value from the keypad

	// Checks whether the entered year is within the valid range (2000-2099)
	if(year < 2000 || year > 2099)
	{
		Cmdlcd(CLEAR_LCD);                                   // Clears the LCD display
		Strlcd("INVALID YEAR");                              // Displays an error message
		delay_MS(500);                                       // Provides a delay to view the error message
		goto Year;                                           // Returns to the Year label to enter again
	}

	RTC_SetDate(DOM, MONTH, year, DOW);                    // Updates year while keeping existing date, month and day

	Cmdlcd(CLEAR_LCD);                                     // Clears the LCD display
	Strlcd("YEAR UPDATED");                                // Displays the update confirmation message
	delay_MS(500);                                         // Provides a delay to view the message
}

// Function to edit street-light ON hour
void Edit_ON_Hour(void)
{
On_hour:                                                // Label used to repeat input if the entered hour is invalid

	Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
	Strlcd("ON HOUR");                                    // Displays the ON hour input message

	ON_HOUR = ReadNum();                                  // Reads and stores the street-light ON hour

	// Checks whether the entered ON hour is within the valid range (0-23)
	if(ON_HOUR >= 24)
	{
		Cmdlcd(CLEAR_LCD);                                  // Clears the LCD display
		Strlcd("INVALID HOUR");                             // Displays an error message
		delay_MS(500);                                      // Provides a delay to view the error message
		goto On_hour;                                       // Returns to the On_hour label to enter again
	}

	Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
	Strlcd("ON HOUR UPDATED");                            // Displays the update confirmation message
	delay_MS(500);                                        // Provides a delay to view the message
}

// Function to edit street-light ON minutes
void Edit_ON_Min(void)
{
On_min:                                                 // Label used to repeat input if the entered minute is invalid

	Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
	Strlcd("ON MINUTE");                                  // Displays the ON minute input message

	ON_MIN = ReadNum();                                   // Reads and stores the street-light ON minutes

	// Checks whether the entered ON minutes are within the valid range (0-59)
	if(ON_MIN >= 60)
	{
		Cmdlcd(CLEAR_LCD);                                  // Clears the LCD display
		Strlcd("INVALID MINUTE");                           // Displays an error message
		delay_MS(500);                                      // Provides a delay to view the error message
		goto On_min;                                        // Returns to the On_min label to enter again
	}

	Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
	Strlcd("ON MIN UPDATED");                             // Displays the update confirmation message
	delay_MS(500);                                        // Provides a delay to view the message
}

// Function to edit street-light OFF hour
void Edit_OFF_Hour(void)
{ 
Off_hour:                                               // Label used to repeat input if the entered hour is invalid

	Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
	Strlcd("OFF HOUR");                                   // Displays the OFF hour input message

	OFF_HOUR = ReadNum();                                 // Reads and stores the street-light OFF hour

	// Checks whether the entered OFF hour is within the valid range (0-23)
	if(OFF_HOUR >= 24)
	{
		Cmdlcd(CLEAR_LCD);                                  // Clears the LCD display
		Strlcd("INVALID HOUR");                             // Displays an error message
		delay_MS(500);                                      // Provides a delay to view the error message
		goto Off_hour;                                      // Returns to the Off_hour label to enter again
	}

	Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
	Strlcd("OFF HOUR UPDATED");                           // Displays the update confirmation message
	delay_MS(500);                                        // Provides a delay to view the message
}

// Function to edit street-light OFF minutes
void Edit_OFF_Min(void)
{
Off_min:                                                // Label used to repeat input if the entered minute is invalid

	Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
	Strlcd("OFF MINUTE");                                 // Displays the OFF minute input message

	OFF_MIN = ReadNum();                                  // Reads and stores the street-light OFF minutes

	// Checks whether the entered OFF minutes are within the valid range (0-59)
	if(OFF_MIN >= 60)
	{
		Cmdlcd(CLEAR_LCD);                                  // Clears the LCD display
		Strlcd("INVALID MINUTE");                           // Displays an error message
		delay_MS(500);                                      // Provides a delay to view the error message
		goto Off_min;                                       // Returns to the Off_min label to enter again
	}

	Cmdlcd(CLEAR_LCD);                                    // Clears the LCD display
	Strlcd("OFF MIN UPDATED");                            // Displays the update confirmation message
	delay_MS(500);                                        // Provides a delay to view the message
}
