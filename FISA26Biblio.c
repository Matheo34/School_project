#include "FISA26Biblio.h"
#include <stdio.h>
#include <xc.h>
#define _XTAL_FREQ 11059200 // Quartz 11,0592 MHz nécessaires à __delay_ms()
void Init()
{
                    // Obligatoire : Désactivation du bus externe ? Voir annexe 1
    MEMCON = 0xA0;  //ebdis=1 bus désactivé (sauf en cas d'accès externe)
                   
    ANCON0=0x00;    // Obligatoire : Désactivation des fonctions analogiques
    ANCON1=0x00;
    ANCON2=0x00;
    /* Définitions des E/S */
    TRISG = 0x18;   //PORT EN ENTREE DES BOUTON RG4, RG5
    TRISD = 0x00;   //PORT EN SORTIE DE TOUTES LEDS
    TRISH = 0xF0;   //PORT EN ENTREE DES SWITCHS RH4, RH5, RH6, RH7
    
    //LATD = 0x01;
}
/* Definition des variables globales */
int sens=0;
int rapidite = 4000/8;


void Tempo (int val)
{
int i;
    for(i = 0;i<val;i++)
    {
        __delay_ms(1);
    }
}

void T_Sens(void)   // Tâche dédiée à la gestion du sens de chenillard
{
    unsigned RG3;
    RG3 =PORTGbits.RG3;
    
    if(RG3 == 0)
    {
        sens=!sens;
        printf("%d",sens);
    }


}
void T_Vitesse(void) // Tâche dédiée à la gestion de la vitesse
{
    if(PORTGbits.RG4 == 0)
    {
        rapidite = rapidite/2;
    }

    if(rapidite < 62)
    {
        rapidite = 4000/8;
    }
}

void T_Recopie(void)// Tâche qui gère la recopie des Switches sur les LED
{
   
    unsigned RG3, RG4;
    RG3 = PORTGbits.RG3;
    RG4 = PORTGbits.RG4;

                unsigned RH4 = PORTHbits.RH4;
                unsigned RH5 = PORTHbits.RH5;
                unsigned RH6 = PORTHbits.RH6;
                unsigned RH7 = PORTHbits.RH7;
                
                
                if(RG3 == 0 && RG4 == 0)
                { 
                    LATD = (RH4 * 0x80) + (RH5 * 0x40) + (RH6 * 0x20) + (RH7 * 0x10);
                    
                    
                 }
}
    

void T_Chenillard(void)// Chenillard
{ 
   
    Tempo(rapidite);
    if(sens == 0)
    {
        if(PORTDbits.RD7){
            LATD = PORTD << 1;
            LATDbits.LATD0 = 1;
        }
        else{
            LATD = PORTD<<1;
        }
    }     
    else
    {
        if(PORTDbits.RD0){
            LATD=PORTD>>1;
            LATDbits.LATD7=1;
        }
        else{
            LATD=PORTD>>1;
        }
    }
    
    
}
