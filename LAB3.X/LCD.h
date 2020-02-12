
#ifndef __LCD_H_
#define	__LCD_H_

#ifndef RS
#define RS RE0
#endif 

#ifndef EN
#define EN RE1
#endif 

#ifndef D0
#define D0 RB0 
#endif 
#ifndef D1
#define D1 RB1 
#endif 
#ifndef D2
#define D2 RB2 
#endif 
#ifndef D3
#define D3 RB3 
#endif 
#ifndef D4
#define D4 RB4 
#endif 
#ifndef D5
#define D5 RB5 
#endif 
#ifndef D6
#define D6 RB6 
#endif 
#ifndef D7
#define D7 RB7 
#endif 

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void LCD_Init(void);
void print_LCD_Char(char caracter);
void comandosLCD(uint8_t x);
void PUERTO(uint8_t x);
void LCD_clear(void);
void LCD_Set_Cursor(uint8_t x,uint8_t y);
void print_LCD_String(char *a);
//void Lcd_Shift_Right();
//void Lcd_Shift_Left();
#endif	/* XC_HEADER_TEMPLATE_H */
