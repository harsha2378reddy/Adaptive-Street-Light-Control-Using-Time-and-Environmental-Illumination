// RTCedit.h

#include "types.h"                              // Includes user-defined data types

// External variables for street light ON time
extern u32 ON_HOUR;                             // Stores the street light ON hour
extern u32 ON_MIN;                              // Stores the street light ON minute

// External variables for street light OFF time
extern u32 OFF_HOUR;                            // Stores the street light OFF hour
extern u32 OFF_MIN;                             // Stores the street light OFF minute

// Functions to edit RTC time
void Edit_Hour(void);                           // Edits the RTC hour
void Edit_Minute(void);                         // Edits the RTC minute
void Edit_Second(void);                         // Edits the RTC second

// Functions to edit RTC date
void Edit_Date(void);                           // Edits the date
void Edit_Month(void);                          // Edits the month
void Edit_Year(void);                           // Edits the year
void Edit_Day(void);                            // Edits the day of the week

// Functions to edit street light ON and OFF timings
void Edit_ON_Hour(void);                        // Edits the street light ON hour
void Edit_ON_Min(void);                         // Edits the street light ON minute
void Edit_OFF_Hour(void);                       // Edits the street light OFF hour
void Edit_OFF_Min(void);                        // Edits the street light OFF minute
