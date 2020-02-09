
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __ADC_H_
#define	__ADC_H_

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdint.h>
void configADC(void);
uint8_t lecADC(uint8_t x);
#endif	/* XC_HEADER_TEMPLATE_H */

