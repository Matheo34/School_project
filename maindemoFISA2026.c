#include "FISA26Biblio.h"
#include <pic18f87k22.h>


void main(void) { 
    
    Init();
 
while (1) {   
    
//        LATDbits.LD0=1;  
    
    T_Sens() ; 
    T_Vitesse() ; 
    T_Recopie() ; 
    T_Chenillard() ;
} 
    return;
}

