/* 
 * File:   Coleccion.h
 * Author:  Darwin Latorre
 * Comments: Configuracion de bits
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_COLECCION_H
#define	XC_COLECCION_H

#include "BITS_Configuration.h"
#include <xc.h>
#include "DHT11Lib.h"
#include "LCD_20x4Lib.h"
#include <stdint.h>
#include <stdio.h>


#define _XTAL_FREQ 8000000          // Definimos la velocidad del oscilador a 8MHz.

//Renombrado
#define delay_ms(x)	__delay_ms(x)
#define delay_us(x)	__delay_us(x)
#define delay_cycles(x) __delay32(x)

#endif	/* XC_COLECCION_H */

