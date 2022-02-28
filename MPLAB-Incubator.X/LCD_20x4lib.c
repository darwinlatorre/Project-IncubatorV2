/*
 * File:   LCD_20x4.c
 * Author: Darwin Latorre
 *
 * Created on February 26, 2022, 12:23 AM
 */

#include "LCD_20x4Lib.h"

void LCD_Cmd(char prm_out_char) 
{
    LCD_RS = 0;

    LCD_D4 = (prm_out_char & 0x10)?1:0;
    LCD_D5 = (prm_out_char & 0x20)?1:0;
    LCD_D6 = (prm_out_char & 0x40)?1:0;
    LCD_D7 = (prm_out_char & 0x80)?1:0;
    LCD_STROBE;

    LCD_D4 = (prm_out_char & 0x01)?1:0;
    LCD_D5 = (prm_out_char & 0x02)?1:0;
    LCD_D6 = (prm_out_char & 0x04)?1:0;
    LCD_D7 = (prm_out_char & 0x08)?1:0;
    LCD_STROBE;

    if(prm_out_char == 0x01)delay_ms(2);
}

void LCD_Clear( void)
{
    LCD_Cmd(_LCD_CLEAR);
}

void LCD_ConfChar(char prmRow, char prmColumn, char prm_out_char)
{
    switch(prmRow) {
        case 1:
            LCD_Cmd(0x80 + (prmColumn - 1));
            break;
        case 2:
            LCD_Cmd(0xC0 + (prmColumn - 1));
            break;
        case 3:
            LCD_Cmd(0x94 + (prmColumn - 1));
            break;
        case 4:
            LCD_Cmd(0xD4 + (prmColumn - 1));
            break;
    }

    LCD_RS = 1;

    LCD_D4 = (prm_out_char & 0x10)?1:0;
    LCD_D5 = (prm_out_char & 0x20)?1:0;
    LCD_D6 = (prm_out_char & 0x40)?1:0;
    LCD_D7 = (prm_out_char & 0x80)?1:0;
    LCD_STROBE;

    LCD_D4 = (prm_out_char & 0x01)?1:0;
    LCD_D5 = (prm_out_char & 0x02)?1:0;
    LCD_D6 = (prm_out_char & 0x04)?1:0;
    LCD_D7 = (prm_out_char & 0x08)?1:0; 
    LCD_STROBE;
}

void LCD_Init() 
{
    delay_ms(200);

    LCD_RS_Direction = 0;
    LCD_EN_Direction = 0;
    LCD_D4_Direction = 0;
    LCD_D5_Direction = 0;
    LCD_D6_Direction = 0;
    LCD_D7_Direction = 0;
 
    LCD_RS = 0;
    LCD_EN = 0;
    LCD_D4 = 0;
    LCD_D5 = 0;
    LCD_D6 = 0;
    LCD_D7 = 0; 
    delay_ms(30);
    LCD_D4 = 1;
    LCD_D5 = 1;
    LCD_D6 = 0;
    LCD_D7 = 0;
    LCD_STROBE
    delay_ms(30);
    LCD_D4 = 1;
    LCD_D5 = 1;
    LCD_D6 = 0;
    LCD_D7 = 0;
    LCD_STROBE
    delay_ms(30);
    LCD_D4 = 1;
    LCD_D5 = 1;
    LCD_D6 = 0;
    LCD_D7 = 0;
    LCD_STROBE
    delay_ms(30);
    LCD_D4 = 0;
    LCD_D5 = 1;
    LCD_D6 = 0;
    LCD_D7 = 0;
    LCD_STROBE
    delay_ms(30);
    LCD_Cmd(0x28);
    LCD_Cmd(0x06);
    LCD_Cmd(_LCD_CURSOR_OFF);
    
}

void LCD_XY_CHAR(char varRow, char prmColumn, char *prmText) 
{
    while(*prmText)
         LCD_ConfChar(varRow, prmColumn++, *prmText++);
}