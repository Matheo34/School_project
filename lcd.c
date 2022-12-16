#include "lcd.h"
#include <xc.h>
#define _XTAL_FREQ 11059200 // Quartz 11,0592 MHz n?cessaires ?

void delai_ms(int tempo){
    int i;
    for(i = 0;i < tempo;i++)
    {
        __delay_ms(1);
    }
}

void init_aff_lcd(void)
{
 delai_ms(100);
 LCD_FUNC = 0x38; 
 delai_ms(5);
 LCD_FUNC = 0x38; 
 delai_ms(1);
 LCD_FUNC = 0x38; 
 delai_ms(1);
 LCD_FUNC = SET_FUNC_8BIT_2LINE_5x7; 
 delai_ms(1);
 LCD_FUNC = SHIFT_CURSOR_RIGHT; 
 delai_ms(1);
 LCD_FUNC = DISPLAY_ON_CUR_ON_BLINKOFF; 
 delai_ms(1);
 LCD_FUNC = ENTRY_MODE_SET_CI_DNS; 
 delai_ms(1);
 LCD_FUNC = RETURN_HOME; 
 delai_ms(2);
 LCD_FUNC = DISPLAY_CLEAR; 
 delai_ms(2);
}
void LCD_send_data(unsigned char cmd){
while( (LCD_DATA && 0x80) == 0x80);
    LCD_DATA = cmd;
    
}

void LCD_send_cmd(unsigned char cmd){
    while( (LCD_FUNC && 0x80) == 0x80);
    LCD_FUNC = cmd;
}

unsigned char binary_ascii(unsigned char var){
    switch(var){
        case 0:
            var = 0x30;
            break;
        case 1:
            var = 0x31;
            break;
        case 2:
            var = 0x32;
            break;     
        case 3:                 
            var = 0x33;
            break;
        case 4:           
            var = 0x34;
            break;
        case 5:
            var = 0x35;
            break;      
        case 6:
            var = 0x36;
            break;   
        case 7:            
            var = 0x37;
            break;
        case 8:       
            var = 0x38;
            break;           
        case 9:
            var = 0x39;
            break;  
            
        case 12:
        LCD_send_cmd(0x10); /*cursor left*/
            break;
            
        case 13:
        LCD_send_cmd(0x14); /*cursor right*/
            break;
        case 14:
         LCD_send_cmd(0x01); /*display clear*/
         LCD_send_cmd(0x02); /*cursor haut gauche*/
            break;
        case 15:
         LCD_send_cmd(0x06);  
            break;
                             
        default:
            var=0x3F;
            break;           
    }
    return var;       
            
    }