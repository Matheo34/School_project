#include <pic18f87k22.h>

#include "EUSART.h"

void init_EUSART(void){
    //EUSART 2
    SPBRG2=17;        //X=((11000000/9600)/64)-1=16,9 donc 17
                      //Baud Rate=11000000/(64*(l7+1))=9548,6
                      //Error= (9548-9600)/9600= -0,5%
    
    BAUDCON2bits.BRG16 = 0;
    TXSTA2bits.SYNC=0;
    RCSTA2bits.SPEN=1; //Serial port activated
    
    TRISGbits.TRISG1=0; //EUSART 2 TX
    TRISGbits.TRISG2=1; //EUSART 2 RX
    
    TXSTA2bits.TXEN=1; //Transmit enable bit
    
    
    RCSTA2bits.CREN=1; //Continous receive enable bit   
    
    
    //EUSART 1
    SPBRG1=17;        //X=((11000000/9600)/64)-1=16,9 donc 17
                      //Baud Rate=11000000/(64*(l7+1))=9548,6
                      //Error= (9548-9600)/9600= -0,5%
    
    BAUDCON1bits.BRG16 = 0;
    TXSTA1bits.SYNC=0;
    RCSTA1bits.SPEN=1; //Serial port activated
    
    TRISCbits.TRISC6=0; //EUSART 2 TX
    TRISCbits.TRISC7=1; //EUSART 2 RX
    
    TXSTA1bits.TXEN=1; //Transmit enable bit
    
    
    RCSTA1bits.CREN=1; //Continous receive enable bit   
    
    
}

void send_EUSART2(unsigned char TXdata){
   while (TX2IF == 0);	/* Wait for transmit interrupt flag*/
   TXREG2 = TXdata;  	/* Write char data to transmit register */    
}

void send_EUSART1(unsigned char TXdata){
   while (TX1IF == 0);	/* Wait for transmit interrupt flag*/
   TXREG1 = TXdata;  	/* Write char data to transmit register */    
}

unsigned char receive_EUSART(){
    while(RC2IF==0);      /*wait for receive interrupt flag*/
    return(RCREG2);       /*received in RCREG register and return to main program */

}

