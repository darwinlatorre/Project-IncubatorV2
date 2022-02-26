/*
 * File:   DHT11Lib.h
 * Author: Darwin Latorre
 *
 * Created on February 25, 2022, 11:53 PM
 */
#ifndef XC_DHT11Lib_H
#define	XC_DHT11Lib_H

#include "BITS_Configuration.h"
#include "adds.h"

#define DHT11_PIN_PORT 	PORTAbits.RA0
#define DHT11_PIN_LAT 	LATAbits.LA0
#define DHT11_PIN_DIR 	TRISAbits.TRISA0

void DHT11_Init(void);
void DHT11_Response(void);
int DHT11_Read_Bytes(void);
short DHT11_Read_Data(float *tem, float *hum);
unsigned DHT11_Join_Data(unsigned h, unsigned l);

#endif	/* XC_DHT11Lib_H */

