//LCD_defines.h

// HD44780 LCD command definitions
#define CLEAR_LCD          0x01             // Clears the complete LCD display
#define RET_CUR_HOME       0x02             // Returns the cursor to the home position
#define SHIFT_CUR_RIGHT    0x06             // Shifts the cursor position towards the right
#define SHIFT_CUR_LEFT     0x07             // Shifts the cursor position towards the left
#define DSP_OFF            0x08             // Turns OFF the LCD display
#define DSP_ON_CUR_OFF     0x0C             // Turns ON the display and turns OFF the cursor
#define DSP_ON_CUR_ON      0x0E             // Turns ON the display and cursor
#define DSP_ON_CUR_BLK     0x0F             // Turns ON the display with a blinking cursor
#define SHIFT_DSP_LEFT     0x10             // Shifts the entire display towards the left
#define SHIFT_DSP_RIGHT    0x14             // Shifts the entire display towards the right

// LCD operating mode definitions
#define MODE_8BIT_1LINE    0x30             // Selects 8-bit mode with one display line
#define MODE_4BIT_1LINE    0x20             // Selects 4-bit mode with one display line
#define MODE_8BIT_2LINE    0x38             // Selects 8-bit mode with two display lines
#define MODE_4BIT_2LINE    0x28             // Selects 4-bit mode with two display lines

// LCD cursor position commands
#define GOTO_LINE1_POS0    0x80             // Moves cursor to the first line, position 0
#define GOTO_LINE2_POS0    0xC0             // Moves cursor to the second line, position 0
#define GOTO_LINE3_POS0    0x94             // Moves cursor to the third line, position 0
#define GOTO_LINE4_POS0    0xD4             // Moves cursor to the fourth line, position 0
#define GOTO_CGRAM_START   0x40             // Selects the starting address of CGRAM

// LCD pin connections
#define LCD_DATA           8                // LCD data pins connected to P0.8–P0.15
#define LCD_RS             4                // LCD RS pin connected to P0.4
#define LCD_RW             5                // LCD RW pin connected to P0.5
#define LCD_EN             6                // LCD Enable pin connected to P0.6

// LCD data mode
#define LCD_MODE           8                // Selects 8-bit LCD data mode
