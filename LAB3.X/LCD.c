#include <xc.h>
#include <stdint.h>
#include "LCD.h"
#define _XTAL_FREQ 4000000


void print_LCD_Char(char caracter){
    char temp,y;
    temp = caracter&0x0F;
    y = caracter&0xF0;
    RS = 1;             // => RS = 1
    PUERTO(y>>4);             //Data transfer
    EN = 1;
    __delay_us(40);
    EN = 0;
    PUERTO(temp);
    EN = 1;
    __delay_us(40);
    EN = 0;
}
void PUERTO(uint8_t x){
    if(x & 1){D0=1;}else{D0=0;}
    if(x & 2){D1=1;}else{D1=0;}
    if(x & 4){D2=1;}else{D2=0;}
    if(x & 8){D3=1;}else{D3=0;}
    if(x & 16){D4=1;}else{D4=0;}
    if(x & 32){D5=1;}else{D5=0;}
    if(x & 64){D6=1;}else{D6=0;}
    if(x & 128){D7=1;}else{D7=0;}

}
void comandosLCD(uint8_t x){
    RS=0;
    EN=1;
    PUERTO(x);
    __delay_ms(5);
    EN=0;
}
void LCD_clear(void){
    comandosLCD(1);
}
void LCD_Init(){
  PUERTO(0x00);
   __delay_ms(20);
  PUERTO(48);
	__delay_ms(5);
  PUERTO(48);
	__delay_ms(11);
  PUERTO(48);
  /////////////////////////////////////////////////////
  PUERTO(56);
  PUERTO(8);
  PUERTO(1);
  PUERTO(6);
}
void LCD_Set_Cursor(uint8_t x,uint8_t y){
	uint8_t a;
	if(x == 1)
	{
        a = 0x80 + y - 1;
		//z = temp>>4;
		//y = temp & 0x0F;
		//Lcd_Cmd(z);
		comandosLCD(a);
	}
	else if(x == 2)
	{
		a = 0xC0 + y - 1;
		//z = temp>>4;
		//y = temp & 0x0F;
		comandosLCD(a);
		//Lcd_Cmd(y);
	}
}
void print_LCD_String(char *a){
	int i;
	for(i=0;a[i]!='\0';i++)
	   print_LCD_Char(a[i]);
}
void Lcd_Shift_Right()
{
	comandosLCD(28);
}
void Lcd_Shift_Left()
{
	comandosLCD(24);
}