/*
 * File:   LAB3.c
 * Author: rodri
 *
 * Created on 8 de febrero de 2020, 01:36 PM
 */
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
/*#define RS RE0
#define EN RE1
#define D0 RB0
#define D1 RB1
#define D2 RB2
#define D3 RB3
#define D4 RB4
#define D5 RB5
#define D6 RB6
#define D7 RB7*/
#define _XTAL_FREQ 4000000 

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "LCD.h"
#include "ADC.h"
#include "USART.h"


void configIO(void);
void enviar(float a);
float conversion(uint8_t b);
char lecturaUSART=0;
uint8_t contador=0;
uint8_t ADC1, ADC2;
float Volt1=0.0,Volt2=0.0;
char datos[20];

void __interrupt() ISR(){
    if(RCIF==1){
        RCIF=0;
        lecturaUSART=Read_USART(); 
        if(lecturaUSART=='+'){contador++;}
        else if(lecturaUSART=='-'){contador--;}
    }
}

void main(void) {
    configIO();
    configADC();
    USART_Init(9600);
    LCD_Init();
    LCD_clear();
    while(1){
        ADC1=lecADC(0);
        ADC2=lecADC(1);
        Volt1=conversion(ADC1);
        Volt2=conversion(ADC2);
        Write_USART_String("V1   V2   contador \n");
        sprintf(datos, "%2.1f   %2.1f   %d", Volt1,Volt2,contador);
        Write_USART_String(datos);
        Write_USART(13);
        Write_USART(10);
        LCD_clear();
        LCD_Set_Cursor(1,1);
        print_LCD_String("V1   V2   conta");
        LCD_Set_Cursor(2,0);
        print_LCD_String(datos);
        __delay_ms(500);
    }
    return;
}
void configIO(){
    TRISB=0;
    TRISA=0;
    TRISE=0;
    ANSEL=0;
    ANSELH=0;
    PORTB=0;
    PORTE=0;
    INTCONbits.PEIE=1;
    PIE1bits.RCIE=1;
    PIR1bits.RCIF=0;
    INTCONbits.GIE=1;
}


float conversion(uint8_t b){
    return b*0.0196;
}