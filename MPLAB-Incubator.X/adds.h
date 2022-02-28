/* 
 * File:   adds.h
 * Author:  Darwin Latorre
 * Comments: Configuracion de bits
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_ADDS_H
#define	XC_ADDS_H

//Renombrado
#define delay_ms(x)	__delay_ms(x)
#define delay_us(x)	__delay_us(x)
#define delay_cycles(x) __delay32(x)

#endif	/* XC_ADDS_H */

