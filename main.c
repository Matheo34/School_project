#include "clavier.h"
#include "lcd.h"
#include "user.h"
#include <xc.h>
#include "interruption.h"
#include "can.h"
#include "cna.h"

void main(void) {
 init();
 init_aff_lcd();
 LCD_send_data('O');
 LCD_send_data('K');
 init_can();
 I2C_Init();
 int value;
 
 
 while(1){

     
 value=analogtodigit();
 I2C_write(value);
 affichage_can(value);
 LCD_clear();
 
 }

 
}

