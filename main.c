#include "clavier.h"
#include "lcd.h"
#include "user.h"
#include <xc.h>
#include "interruption.h"
#include "EUSART.h"

void main(void) {
    delai_ms(100);
 init();
init_interrupt();
init_aff_lcd();
 init_EUSART();
 
 unsigned char clav;
 while(1){
 }

 
}
