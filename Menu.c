//MENU.c

#include <LPC214x.h>                            // Includes LPC214x microcontroller register definitions
#include "types.h"                              // Includes user-defined data types
#include "LCD.h"                                // Includes LCD function declarations
#include "LCD_defines.h"                        // Includes LCD commands and pin definitions
#include "KPM.h"                                // Includes keypad function declarations
#include "RTC.h"                                // Includes RTC function declarations
#include "RTCedit.h"                            // Includes RTC editing function declarations
#include "menu.h"                               // Includes menu function declarations
#include "delay.h"                              // Includes delay function declarations


// Function to display the main menu    
void Menu(void)
{
	u32 choice, subchoice, subchoice1;            // Variables to store main menu, submenu and item selections

	// Repeats the main menu until the user selects EXIT
	while(1)                                    
	{
		Cmdlcd(CLEAR_LCD);                          // Clears the LCD display
		Strlcd("1.TIME  2.DATE");                   // Displays TIME and DATE options on the first line

		Cmdlcd(GOTO_LINE2_POS0);                    // Moves the LCD cursor to the beginning of the second line
		Strlcd("3.L_TIME 4.EXIT");                  // Displays LIGHT TIME and EXIT options

		choice = ReadNum();                         // Reads the main menu option entered through the keypad

		// Checks whether the user selected TIME
		if(choice == 1)
		{
			// Repeats the TIME submenu until EXIT is selected
			while(1)                    
			{
				Cmdlcd(CLEAR_LCD);                     // Clears the LCD display
				Strlcd("1.HOUR  2.MIN");               // Displays HOUR and MINUTE options

				Cmdlcd(GOTO_LINE2_POS0);               // Moves the LCD cursor to the second line
				Strlcd("3.SEC   4.EXIT");              // Displays SECOND and EXIT options

				subchoice = ReadNum();                 // Reads the TIME submenu option

				// Checks whether the user selected HOUR
				if(subchoice == 1)
				{
					Edit_Hour();                         // Calls the function to edit RTC hour
				}

				// Checks whether the user selected MINUTE
				else if(subchoice == 2)
				{
					Edit_Minute();                       // Calls the function to edit RTC minutes
				}

				// Checks whether the user selected SECOND
				else if(subchoice == 3)
				{
					Edit_Second();                       // Calls the function to edit RTC seconds
				}

				// Checks whether the user selected EXIT
				else if(subchoice == 4)
				{
					break;                               // Exits the TIME submenu and returns to the main menu
				}

				// Executes when an invalid option is entered
				else
				{
					Cmdlcd(CLEAR_LCD);                   // Clears the LCD display
					Strlcd("INVALID OPTION");            // Displays an error message
					delay_MS(500);                       // Provides a delay to view the error message
				}
			}
		}

		// Checks whether the user selected DATE
		else if(choice == 2)
		{
			// Repeats the DATE submenu until EXIT is selected
			while(1)                                  
			{
				Cmdlcd(CLEAR_LCD);                     // Clears the LCD display
				Strlcd("1.DATE  2.MONTH");             // Displays DATE and MONTH options
 
	 			Cmdlcd(GOTO_LINE2_POS0);               // Moves the LCD cursor to the second line
				Strlcd("3.YR 4.DAY 5.EXT");            // Displays YEAR, DAY and EXIT options

				subchoice = ReadNum();                 // Reads the DATE submenu option

				// Checks whether the user selected DATE
				if(subchoice == 1)
				{
					Edit_Date();                         // Calls the function to edit calendar date
				}

				// Checks whether the user selected MONTH
				else if(subchoice == 2)
				{
					Edit_Month();                        // Calls the function to edit calendar month
				}

				// Checks whether the user selected YEAR
				else if(subchoice == 3)
				{
					Edit_Year();                         // Calls the function to edit calendar year
				}

				// Checks whether the user selected DAY
				else if(subchoice == 4)
				{
					Edit_Day();                          // Calls the function to edit day of the week
				}

				// Checks whether the user selected EXIT
				else if(subchoice == 5)
				{
					break;                               // Exits the DATE submenu and returns to the main menu
				}

				// Executes when an invalid option is entered
				else
				{
					Cmdlcd(CLEAR_LCD);                   // Clears the LCD display
					Strlcd("INVALID OPTION");            // Displays an error message
					delay_MS(500);                       // Provides a delay to view the error message
				}
			}
		}

		// Checks whether the user selected LIGHT TIME
		else if(choice == 3)
		{
			// Repeats the LIGHT TIME submenu until EXIT is selected
			while(1)                                  
			{
				Cmdlcd(CLEAR_LCD);                     // Clears the LCD display
				Strlcd("1.ON TIME ");                  // Displays ON TIME option
 
	 			Cmdlcd(GOTO_LINE2_POS0);               // Moves the LCD cursor to the second line
				Strlcd("2.OFF_TIME 3.EXT");            // Displays OFF TIME and EXIT options

				subchoice = ReadNum();                 // Reads the LIGHT TIME submenu option

				// Checks whether the user selected ON TIME
				if(subchoice == 1)
				{
					// Repeats the ON TIME submenu until EXIT is selected
					while(1)                          
					{
						Cmdlcd(CLEAR_LCD);                // Clears the LCD display
						Strlcd("1.HOUR  2.MIN");          // Displays HOUR and MINUTE options

						Cmdlcd(GOTO_LINE2_POS0);          // Moves the LCD cursor to the second line
						Strlcd("3.EXIT");                 // Displays EXIT option

						subchoice1 = ReadNum();           // Reads the ON TIME submenu option

						// Checks whether the user selected HOUR
						if(subchoice1 == 1)
						{
							Edit_ON_Hour();                 // Calls the function to edit street-light ON hour
						} 

						// Checks whether the user selected MINUTE
						else if(subchoice1 == 2)
						{
							Edit_ON_Min();                  // Calls the function to edit street-light ON minutes
						}

						// Checks whether the user selected EXIT
						else if(subchoice1 == 3)
						{
							break;                          // Exits the ON TIME submenu
						}

						// Executes when an invalid option is entered
						else
						{
							Cmdlcd(CLEAR_LCD);              // Clears the LCD display
							Strlcd("INVALID OPTION");       // Displays an error message
							delay_MS(500);                  // Provides a delay to view the error message
						}
					}
				}

				// Checks whether the user selected OFF TIME
				else if(subchoice == 2)
				{  
					// Repeats the OFF TIME submenu until EXIT is selected
					while(1)             
					{
						Cmdlcd(CLEAR_LCD);               // Clears the LCD display
						Strlcd("1.HOUR  2.MIN");         // Displays HOUR and MINUTE options

						Cmdlcd(GOTO_LINE2_POS0);         // Moves the LCD cursor to the second line
						Strlcd("3.EXIT");                // Displays EXIT option

						subchoice1 = ReadNum();          // Reads the OFF TIME submenu option

						// Checks whether the user selected HOUR
						if(subchoice1 == 1)
						{
							Edit_OFF_Hour();               // Calls the function to edit street-light OFF hour
						}

						// Checks whether the user selected MINUTE
						else if(subchoice1 == 2)
						{
							Edit_OFF_Min();                // Calls the function to edit street-light OFF minutes
						}

						// Checks whether the user selected EXIT
						else if(subchoice1 == 3)
						{
							break;                         // Exits the OFF TIME submenu
						}

						// Executes when an invalid option is entered
						else
						{
							Cmdlcd(CLEAR_LCD);             // Clears the LCD display
							Strlcd("INVALID OPTION");      // Displays an error message
							delay_MS(500);                 // Provides a delay to view the error message
						}
					}
				}

				// Checks whether the user selected EXIT
				else if(subchoice == 3)
				{
					break;                             // Exits the LIGHT TIME submenu and returns to the main menu
				}

				// Executes when an invalid option is entered
				else
				{
					Cmdlcd(CLEAR_LCD);                 // Clears the LCD display
					Strlcd("INVALID OPTION");          // Displays an error message
					delay_MS(500);                     // Provides a delay to view the error message
				}
			}
		}

		// Checks whether the user selected EXIT from the main menu
		else if(choice == 4)
		{
			break;                                 // Exits the main menu
		}

		// Executes when an invalid main menu option is entered
		else
		{
			Cmdlcd(CLEAR_LCD);                     // Clears the LCD display
			Strlcd("INVALID OPTION");              // Displays an error message
			delay_MS(500);                         // Provides a delay to view the error message
		}
	}
}

