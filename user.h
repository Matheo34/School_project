/* 
 * File:   user.h
 * Author: MATHEO
 *
 * Created on 2 juin 2022, 12:04
 */

#ifndef USER_H
#define	USER_H

#ifdef	__cplusplus
extern "C" {
#endif

    void init(void);
    int write_eeprom(int address, int data_wr);
    int read_eeprom(int address);
    
#ifdef	__cplusplus
}
#endif

#endif	/* USER_H */

