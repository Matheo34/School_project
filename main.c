#include "clavier.h"
#include "lcd.h"
#include "user.h"
#include <xc.h>
#include "interruption.h"

void main(void) {
 init();
 init_aff_lcd();
 init_interrupt();
 
 while(1){
// unsigned char mat;
// 
//write_eeprom(0x05, 0xF4);
//        
//mat = read_eeprom(0x05);
//         
//LCD_send_data( mat );
 }

 
}
