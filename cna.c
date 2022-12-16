#include "cna.h"
#include <xc.h>
void I2C_Init(void)
{
SSP1STAT = 0x00;
SSP1CON1 = 0x00;
SSP1CON1bits.SSPEN = 1; // Enables the serial port and configures the SDAx and SCLx pins as the serial portpins
SSP1CON1bits.SSPM = 0x08; // 1000 = I2C Master mode
SSP1CON2 = 0x00;
SSP1ADD = 0x1A; // Baud rate pour I2C à 100kHz
}

void I2C_write(int VAL){
    
    int jul;
    jul=(VAL>>4);
    SSP1CON2bits.SEN = 1; // Envoi du bit de start
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = 0x90; // adresse du convertisseur dig/ana
    while (SSP1CON2bits.ACKSTAT == 1) {}; // tant que acquittement du convertisseur non re?u
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = 0x40; // bits de contr?le
    while (SSP1CON2bits.ACKSTAT == 1) {}; // tant que acquittement du convertisseur non re?u
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = jul; // bits de donn?es 0 ? 255
    while (SSP1CON2bits.ACKSTAT == 1) {}; // tant que acquittement du convertisseur non re?u
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1CON2bits.PEN = 1; // Envoi du bit de stop
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
}