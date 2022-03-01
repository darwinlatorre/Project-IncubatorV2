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
    LCD_Clear();

    LCD_XY_CHAR(1, 1, "       Estado:      ");
    LCD_XY_CHAR(2, 1, "Temp:");
    LCD_XY_CHAR(2, 12, "Hum:");
    LCD_XY_CHAR(3, 1, "   Configuracion:   ");
    LCD_XY_CHAR(4, 1, "Temp:");
    LCD_XY_CHAR(4, 12, "Hum:");
    
    while(1)
    {
        DHT_State = DHT11_Read_Data(&varCurrentTemp, &varCurrentHum);
        
        if(DHT_State == 1)
        {
            sprintf(LCD_Buffer, "%02d C", varCurrentTemp);
            LCD_XY_CHAR(2, 6, LCD_Buffer);
            sprintf(LCD_Buffer, "%02d%%", varCurrentHum);
            LCD_XY_CHAR(2, 16, LCD_Buffer);
            sprintf(LCD_Buffer, "%02d C", varUserTemp);
            LCD_XY_CHAR(4, 6, LCD_Buffer);
            sprintf(LCD_Buffer, "%02d%%", varUserHum);
            LCD_XY_CHAR(4, 16, LCD_Buffer);
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
