/*
 * Servomotor.h
 *
 * Created: 28/04/2024 08:40:48 م
 *  Author: Hazem Ragab Elsayed
 */ 


#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

void servomotor_init(char portname,unsigned char pinumber);
void servomotor_rot(signed char degree);


#endif /* SERVOMOTOR_H_ */