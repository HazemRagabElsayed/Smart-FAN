/*
 * Servomotor.c
 *
 * Created: 28/04/2024 08:40:30 م
 *  Author: Hazem Ragab Elsayed
 */ 

#include "COMMON.h"

void servomotor_init(char portname,unsigned char pinumber)
{
	DIO_vsetPINDir(portname,pinumber,1);
}
void servomotor_rot(signed char degree)
{
		timer1_wave_fastPWM(1 + ((float)degree/90) * 0.5,SERVO_MOTOR);
}
