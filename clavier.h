/* 
 * File:   clavier.h
 * Author: MATHEO
 *
 * Created on 2 juin 2022, 12:05
 */

#ifndef CLAVIER_H
#define	CLAVIER_H

#ifdef	__cplusplus
extern "C" {
#endif

far unsigned char Clavier  @0x180000; 

unsigned char get_clav(void);


#ifdef	__cplusplus
}
#endif

#endif	/* CLAVIER_H */

