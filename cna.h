/* 
 * File:   cna.h
 * Author: MATHEO
 *
 * Created on 22 juin 2022, 09:01
 */

#ifndef CNA_H
#define	CNA_H

#ifdef	__cplusplus
extern "C" {
#endif

void I2C_Init(void);
void I2C_write(int VAL);

#ifdef	__cplusplus
}
#endif

#endif	/* CNA_H */

