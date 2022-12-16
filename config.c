#include <xc.h>

/* Configuration du PIC:
    Oscillateur: HS (11.0592MHz)
    Watchdog Timer: d?sactiv?
    Protection du code: d?sactiv? */
#pragma config CONFIG1L = 0x1D
#pragma config CONFIG1H = 0x03 //HS_OSC
#pragma config CONFIG2L = 0x61 //BOR et PWRT Disable
#pragma config CONFIG2H = 0x00 //WDT off
#pragma config CONFIG3L = 0x01 //0x01:Bus D:8bit A:20bit
#pragma config CONFIG3H = 0x8B //MCLR
#pragma config CONFIG4L = 0x81 //0x81=debug_off 0x01=DEBUG_ON
#pragma config CONFIG5L = 0xFF //No CODE PROTECT
#pragma config CONFIG5H = 0xC0 //No CP EEPROM + code
#pragma config CONFIG6L = 0xFF //No write protect...
#pragma config CONFIG6H = 0xE0 //No write protect config...
#pragma config CONFIG7L = 0xFF //No table read protection
#pragma config CONFIG7H = 0x40 //No table read protection



