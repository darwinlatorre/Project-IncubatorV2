/*
 * File:   main.c
 * Author: Darwin Latorre
 *
 * Created on February 25, 2022, 11:53 PM
 */

#include "LCD_20x4Lib.h"
#include "DHT11Lib.h"
#include <stdint.h>
#include <stdio.h>

char LCD_Buffer [20];
short DHT_State;
float atrTemperatura;
float atrHumedad;


void main(void) 
{
    ADCON1bits.PCFG = 0x0F;             // Coloca todos los pines como digitales
    PORTD=0x00;
    LCD_Init();
    LCD_Clear();
    
    LCD_XY_CHAR(1, 1, "   PRJ.Incubator    ");
    LCD_XY_CHAR(2, 1, "    Bienvenido...   ");
    LCD_XY_CHAR(3, 1, "   MC: PIC18F4550   ");
    LCD_XY_CHAR(4, 1, " By: Darwin Latorre ");
    delay_ms(1000);
    

    
    while(1)
    {
        DHT_State = DHT11_Read_Data(&atrTemperatura, &atrHumedad);
        
        if(DHT_State == 1)
        {
            LCD_XY_CHAR(1, 1, "       Estado:      ");
            sprintf(LCD_Buffer, "Temp:%0.1fC ", atrTemperatura);
            LCD_XY_CHAR(2, 1, LCD_Buffer);
            sprintf(LCD_Buffer, "Hum:%0.1f%%", atrHumedad);
            LCD_XY_CHAR(2, 12, LCD_Buffer);
            LCD_XY_CHAR(3, 1, "--------------------");
            LCD_XY_CHAR(4, 1, "--------------------");
        }
        else
        {
            LCD_Clear();
            LCD_XY_CHAR(1, 1, "       Estado:      ");
            LCD_XY_CHAR(2, 1, "      Error...      ");
            LCD_XY_CHAR(3, 1, "--------------------");
            LCD_XY_CHAR(4, 1, "--------------------");
        }
    }
    delay_ms(1000);
    return;
}
