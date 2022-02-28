/*
 * File:   DHT11Lib.c
 * Author: Darwin Latorre
 *
 * Created on February 25, 2022, 11:53 PM
 */

#include "DHT11Lib.h"

void DHT11_Init(void)
{
    DHT11_PIN_DIR = 0; // Set pin as output
    DHT11_PIN_LAT = 0; // Pull bus to low state
    delay_ms(20);
    DHT11_PIN_LAT = 1;
    delay_us(30);
    DHT11_PIN_DIR = 1;  // Set pin as input
}

void DHT11_Response(void)
{
    while(DHT11_PIN_PORT == 1);
    while(DHT11_PIN_PORT == 0);
    while(DHT11_PIN_PORT == 1);
}

int DHT11_Read_Bytes(void)
{
    int varIndice, varData = 0;
    for(varIndice=0; varIndice<8; varIndice++){
        while((DHT11_PIN_PORT) == 0);
        __delay_us(30);
        if((DHT11_PIN_PORT) == 1){
            varData = ((varData<<1) | 1);
        }else{
            varData = (varData<<1);
        }
        while((DHT11_PIN_PORT) == 1);
    }
    return varData;
}

short DHT11_Read_Data(int *tem, int *hum)
{
    int temp = 0;
    int info[5];
    DHT11_Init();
    DHT11_Response();
    
    info[0] = DHT11_Read_Bytes();   // Humedad entero
    info[1] = DHT11_Read_Bytes();   // Humedad decimal
    info[2] = DHT11_Read_Bytes();   // Temp entero
    info[3] = DHT11_Read_Bytes();   // Temp decimal
    info[4] = DHT11_Read_Bytes();   // Paridad
    
    //*hum = (float)((DHT11_Join_Data(info[0], info[1])) / 10.0f);
    *hum = info[0];
    //*tem = (float)((DHT11_Join_Data(info[2], info[3])) / 10.0f);
    *tem = info[2];
    temp = info[0] + info[1] + info[2] + info[3];
    
    if(temp == info[4]){
        return 1;
    }else{
        return 0;
   }
}

//unsigned DHT11_Join_Data(unsigned h, unsigned l)
//{
//    unsigned pow = 10;
//    while(l >= pow)
//        pow *= 10;
//    return h * pow + l;        
//}