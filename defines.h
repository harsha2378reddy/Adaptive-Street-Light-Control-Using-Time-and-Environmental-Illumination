//defines.h

// Writes an 8-bit value at the specified bit position
#define WRITEBYTE(WORD,STARTBIT,BYTE) WORD=((WORD&(~(0XFF<<STARTBIT)))|(BYTE<<STARTBIT))  

  // Reads the specified bit and returns its value (0 or 1)
#define READBIT(WORD,BIT)((WORD>>BIT)&1)              

// Writes a 4-bit value at the specified bit position
#define WRITENIBBLE(WORD,STARTBIT,NIBBLE)WORD = ((WORD & (~(0xF << STARTBIT)))|((NIBBLE & 0xF) << STARTBIT)) 

// Reads 4 bits starting from the specified bit position
#define READNIBBLE(WORD,STARTNIBBLE) ((WORD>>STARTNIBBLE)&0XF)                           

// Sets the specified bit to 1
#define SETBIT(WORD,BIT) (WORD |= (1 << BIT))                                

 // Clears the specified bit to 0
#define CLRBIT(WORD,BIT)(WORD &= ~(1 << BIT))    
