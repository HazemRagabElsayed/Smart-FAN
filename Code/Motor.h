/*
 * Motor.h
 *
 * Created: 03/08/2024 11:53:36 م
 *  Author: Hazem Ragab Elsayed
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_


/*software Interfaces Start*/

void motor_init(char portname,unsigned char pinnumber1);
void motor_ON(char portname,unsigned char pinnumber1,unsigned char speed);
void motor_OFF();

/*software Interfaces End*/

#endif /* MOTOR_H_ */