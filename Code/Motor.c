/*
 * Motor.c
 *
 * Created: 03/08/2024 11:53:15 م
 *  Author: Hazem RagaB Elsayed
 */ 


#include "COMMON.h"

void motor_init(char portname,unsigned char pinnumber1)
{
	DIO_vsetPINDir(portname,pinnumber1,OUTPUT);
}
void motor_ON(char portname,unsigned char pinnumber1,unsigned char speed)
{
    timer1_wave_fastPWM(speed * 1.95,DC_MOTOR);
}
void motor_OFF()
{
    timer1_wave_fastPWM(0,DC_MOTOR);
	DIO_write('D',4,LOW);
}
