/* 
 * File:   BITS_Configuration.h
 * Author:  Darwin Latorre
 * Comments: Configuracion del lcd 20x4
 */
 
#ifndef XC_LCD_20x4Lib_H
#define	XC_LCD_20x4Lib_H

#include "Coleccion.h"

#define _LCD_FIRST_ROW          0x80     //Mueve el cursor a la 1ra columna
#define _LCD_SECOND_ROW         0xC0     //Mueve el cursor a la 2da columna
#define _LCD_THIRD_ROW          0x94     //Mueve el cursor a la 3ra columna
#define _LCD_FOURTH_ROW         0xD4     //Mueve el cursor a la 4ta columna
#define _LCD_CLEAR              0x01     //Limpia pantalla LCD
#define _LCD_RETURN_HOME        0x02     //Return cursor to home position, returns a
                                         //shifted display to its original position.
                                         //Display data RAM is unaffected.
#define _LCD_CURSOR_OFF         0x0C     //Desactiva el cursor
#define _LCD_UNDERLINE_ON       0x0E     //Habilita el guion bajo del cursor
#define _LCD_BLINK_CURSOR_ON    0x0F     //Habilita el blink del cursor
#define _LCD_MOVE_CURSOR_LEFT   0x10     //Move cursor left without changing
                                         //display data RAM
#define _LCD_MOVE_CURSOR_RIGHT  0x14     //Move cursor right without changing
                                         //display data RAM
#define _LCD_TURN_ON            0x0C     //Turn Lcd display on
#define _LCD_TURN_OFF           0x08     //Turn Lcd display off
#define _LCD_SHIFT_LEFT         0x18     //Shift display left without changing
                                         //display data RAM
#define _LCD_SHIFT_RIGHT        0x1E     //Shift display right without changing
                                         //display data RAM

#define LCD_RS LATDbits.LD2
#define LCD_EN LATDbits.LD3
#define LCD_D4 LATDbits.LD4
#define LCD_D5 LATDbits.LD5
#define LCD_D6 LATDbits.LD6
#define LCD_D7 LATDbits.LD7

#define LCD_RS_Direction TRISDbits.TRISD2
#define LCD_EN_Direction TRISDbits.TRISD3
#define LCD_D4_Direction TRISDbits.TRISD4
#define LCD_D5_Direction TRISDbits.TRISD5
#define LCD_D6_Direction TRISDbits.TRISD6
#define LCD_D7_Direction TRISDbits.TRISD7

#define EN_DELAY 200
#define LCD_STROBE {LCD_EN = 1; delay_us(EN_DELAY); LCD_EN = 0; delay_us(EN_DELAY);};

void LCD_Cmd(char prm_out_char);

void LCD_Clear( void);

void LCD_ConfChar(char prmRow, char prmColumn, char prm_out_char);

void LCD_Init();

void LCD_XY_CHAR(char varRow, char prmColumn, char *prmText);


#endif   /* XC_LCD_20x4Lib_H */
