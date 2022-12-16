#include "clavier.h"
#include "lcd.h"

unsigned char get_clav(void){
    
    unsigned char data;
    unsigned char result;
    unsigned char valeur_i;
    
    data = 0x00;
    result = 0x00 ;
    
    data = Clavier;
    
    valeur_i = ((data) & (0x0F));
    
    result = binary_ascii(valeur_i);
    
    return result;
    
}
