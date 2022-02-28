/*
 * File:   main.c
 * Author: Darwin Latorre
 *
 * Created on February 25, 2022, 11:53 PM
 */

#include "BITS_Configuration.h"
#include "LCD_20x4Lib.h"
#include "DHT11Lib.h"
#include <stdint.h>
#include <stdio.h>

void main(void) 
{
    char LCD_Buffer [20];
    short DHT_State;
    int varCurrentTemp;
    int varCurrentHum;
    int varUserTemp = 30, varUserHum = 20;
    
    ADCON1bits.PCFG = 0x0F;             // Coloca todos los pines como digitales
    
    PORTD=0x00;
    
    LCD_Init();
    //LCD_XY_CHAR(1, 1, "   PRJ.Incubator    ");
    //LCD_XY_CHAR(2, 1, "    Bienvenido...   ");
    //LCD_XY_CHAR(3, 1, "   MC: PIC18F4550   ");
    //LCD_XY_CHAR(4, 1, " By: Darwin Latorre ");
    //delay_ms(500);
    LCD_Clear();

    while(1)
    {
        DHT_State = DHT11_Read_Data(&varCurrentTemp, &varCurrentHum);
        
        if(DHT_State == 1)
        {
            LCD_XY_CHAR(1, 1, "       Estado:      ");
            sprintf(LCD_Buffer, "Temp:%02dC ", varCurrentTemp);
            LCD_XY_CHAR(2, 1, LCD_Buffer);
            sprintf(LCD_Buffer, "Hum:%02d%", varCurrentHum);
            LCD_XY_CHAR(2, 12, LCD_Buffer);
            LCD_XY_CHAR(3, 1, "   Configuracion:   ");
            sprintf(LCD_Buffer, "Temp: %02dC", varUserTemp);
            LCD_XY_CHAR(4, 1, LCD_Buffer);
            sprintf(LCD_Buffer, "Hum: %02d%", varUserHum);
            LCD_XY_CHAR(4, 12, LCD_Buffer);
        }
        else
        {
            LCD_Clear();
            LCD_XY_CHAR(1, 1, "--------------------");
            LCD_XY_CHAR(2, 1, "       Estado:      ");
            LCD_XY_CHAR(3, 1, "      Error...      ");
            LCD_XY_CHAR(4, 1, "--------------------");
        }
    }
    delay_ms(1000);
    return;
}
