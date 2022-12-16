#include <pic18f87k22.h>

#include "clavier.h"
#include "lcd.h"
#include "interruption.h"

void init_interrupt(void){
    /*Interrupt RB0*/
    RCONbits.IPEN=1; /*Plusieurs types d'interrupt (haut et bas)*/
    INTCONbits.GIE=1; /* Enables all high-priority interrupts */
    INTCONbits.PEIE=1; /*Enables all low-priority peripheral interrupts */
    INTCON2bits.INTEDG0 = 1; /*Front montant*/
   
    INTCONbits.INT0IE =1;
    INTCONbits.INT0IF =0;
}

void interrupt isr_clav(){
    if((INTCONbits.INT0IF)&&(INTCONbits.INT0IE) ==1){
        unsigned char result;
        
            result = get_clav();
            
            LCD_send_data(result);
            
            INTCONbits.INT0IF = 0;
    }
}