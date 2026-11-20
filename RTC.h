// RTC.h

#include "types.h"                                        // Includes user-defined data types

void Init_RTC(void);                                      // Initializes the Real-Time Clock
void RTC_Display(void);                                   // Displays the current RTC time and date
void displaytime(void);                                   // Displays the current time
void displaydate(void);                                   // Displays the current date
void RTC_SetTime(u32 hour, u32 minute, u32 second);       // Sets the RTC time using hour, minute and second values
void RTC_SetDate(u32 date, u32 month, u32 year, u32 day); // Sets the RTC date using date, month, year and day values
