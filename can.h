/* 
 * File:   can.h
 * Author: MATHEO
 *
 * Created on 22 juin 2022, 09:01
 */

#ifndef CAN_H
#define	CAN_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void  init_can(void);
    
int analogtodigit(void);

void affichage_can(int var);
#ifdef	__cplusplus
}
#endif

#endif	/* CAN_H */

