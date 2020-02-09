//Libreria baaada en Using UART of PIC Microcontroller BY LIGO GEORGE
//extraido de https://electrosome.com/uart-pic-microcontroller-mplab-xc8/

#include <xc.h>
#include <stdint.h>
#include "USART.h"

char UART_Init(const long int baudrate){
  unsigned int x;
  x = (_XTAL_FREQ - baudrate*64)/(baudrate*64);   //SPBRG for Low Baud Rate
  if(x>255)                                       //If High Baud Rage Required
  {
    x = (_XTAL_FREQ - baudrate*16)/(baudrate*16); //SPBRG for High Baud Rate
    BRGH = 1;                                     //Setting High Baud Rate
  }
  if(x<256)
  {
    SPBRG = x;                                    //Writing SPBRG Register
    SYNC = 0;                                     //Setting Asynchronous Mode, ie UART
    SPEN = 1;                                     //Enables Serial Port
    TRISC7 = 1;                                   //As Prescribed in Datasheet
    TRISC6 = 1;                                   //As Prescribed in Datasheet
    CREN = 1;                                     //Enables Continuous Reception
    TXEN = 1;                                     //Enables Transmission
    return 1;                                     //Returns 1 to indicate Successful Completion
  }
  return 0;                                       //Returns 0 to indicate UART initialization failed
}
void Write_USART(uint8_t x){
    while(!TMRT){
        TXREG=x;
    }
}
void Write_USART_String(uint8_t a){
    uinit8_t i;
    for(i=0;a[i]=!"/0";i++){
        Write_USART(a[i]);
    }
}
uint8_t Read_USART(){
  while(!RCIF){
      return RCREG;
  }  
} 
void Read_USART_String(char *Output, unsigned int length){
  unsigned int i;
  for(int i=0;i<length;i++)
  Output[i] = Read_USART();
}