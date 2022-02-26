/*
 * File:   main.c
 * Author: Darwin Latorre
 *
 * Created on February 25, 2022, 11:53 PM
 */

#include "LCD_20x4Lib.h"
#include <stdint.h>
#include <stdio.h>

char LCD_Buffer [20];
float Decimal   = 0.78;
uint16_t Entero = 427;


void main(void) {
    
    PORTD=0x00;
    LCD_Init();
    LCD_Clear();
    
    LCD_XY_CHAR(1,1,"   PRJ.Incubator    ");
    LCD_XY_CHAR(2,1,"    Bienvenido...   ");
    LCD_XY_CHAR(3,1,"   MC: PIC18F4550   ");
    LCD_XY_CHAR(4,1," By: Darwin Latorre ");
    delay_ms(1000);
    
    while(1)
    {
        
        
    }
    return;
}
