#include "can.h"
#include <pic18f87k22.h>
#include "lcd.h"

void init_can(void){
    ANCON0=0x01; /*A0*/
    ADCON0bits.CHS=0x00; 
    ADCON0bits.ADON=1;
    
    ADCON1bits.VCFG=0x03;
    ADCON1bits.VNCFG=0;
    ADCON1bits.CHSN=0;
    
    ADCON2bits.ACQT=0x03;
    ADCON2bits.ADCS=0x05;
    ADCON2bits.ADFM=0x01;
}

int analogtodigit(void){
    
    int adcValue=0;
    
    ADCON0bits.GO_nDONE = 1;
    
    while(ADCON0bits.GO_nDONE == 1){};
    
    adcValue = (ADRESH << 8) + ADRESL;
    
    return adcValue;
}

void affichage_can(int var){
    unsigned int millier, millier_bis;
    unsigned int  centaine, centaine_bis;
    unsigned int dizaine, dizaine_bis;
    unsigned int  unite;
    
    millier = var / 1000;
    millier_bis = var % 1000;
    
    centaine = millier_bis / 100;
    centaine_bis = millier_bis % 100;
    
    dizaine_bis = centaine_bis % 100;
    dizaine = centaine_bis / 10;
    
    unite = dizaine % 10;
    
    
    LCD_send_data(millier+0x30); //envoi data en ascii
    LCD_send_data(centaine+0x30);
    LCD_send_data(dizaine+0x30);
    LCD_send_data(unite+0x30);
    
    delai_ms(50);
  
            
    }