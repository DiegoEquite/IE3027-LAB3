//* Liberia basada en la libreira LCD4bits de Pablo Mazariegos

#include <xc.h>
#include <stdint.h>
#include "LCD.h"
#define _XTAL_FREQ 4000000

//funcion para imprimir un caracter
void print_LCD_Char(char caracter){
    RS = 1;             // => RS = 1
    PUERTO(caracter);
    EN = 1;
    __delay_us(5);
    EN = 0;
    __delay_us(5);
    __delay_us(50);
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
//funcion para enviar datos a la LCD
void comandosLCD(uint8_t x){
    RS=0;
    PUERTO(x);
    EN=1;
    __delay_us(5);
    EN=0;
    __delay_us(5);
    __delay_ms(2);
}
//limpiar LCD
void LCD_clear(void){
    comandosLCD(0);
    comandosLCD(1);
}
//funcion para iniciar la LCD
void LCD_Init(){
    RS=0;
    EN=0;
    PUERTO(0x00);
   __delay_ms(50);
   comandosLCD(0x02);
   comandosLCD(0x38);
   comandosLCD(0x0C);
   comandosLCD(0x06);
   
}
//Funcion para configurar el cursor
void LCD_Set_Cursor(uint8_t x,uint8_t y){
	uint8_t a;
	if(x == 1)
	{
        a = 0x80 + y;
		comandosLCD(a);
	}
	else if(x == 2)
	{
		a = 0xC0 + y;
		comandosLCD(a);
	}
}
//funcion para enviar un string
void print_LCD_String(char *a){
	int i;
	for(i=0;a[i]!='\0';i++)
	   print_LCD_Char(a[i]);
}
//void Lcd_Shift_Right(){
//	comandosLCD(28);}
//void Lcd_Shift_Left(){
//	comandosLCD(24);}
//	comandosLCD(28);
//}
//void Lcd_Shift_Left(){
//	comandosLCD(24);
//}
