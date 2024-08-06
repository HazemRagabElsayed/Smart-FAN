/*
 * servo_motor.c
 *
 * Created: 10/23/2019 1:46:05 PM
 *  Author: Hazem Ragab Elsayed
 */ 



#include "COMMON.h"

volatile char dcmotor = DC_MOTOR_OFF;
volatile char rotate = ROTATE_OFF;
volatile char choice;

void main(void)
{
	signed char degree = 0;
	motor_init('C',PINC0);
	servomotor_init('D',5);
	UART_vInit(9600);
    UART_RECEIVE_INTERRUPT_ENABLE();
degree = MAXNEGDEGREE;
	
	while(1)
	{
		for(; degree < MAXPOSDEGREE && DC_MOTOR_ON == dcmotor && ROTATE_ON == rotate;degree++)
		{
			servomotor_rot(degree);
			_delay_ms(20);
		} 
		for(; degree > MAXNEGDEGREE && DC_MOTOR_ON == dcmotor && ROTATE_ON == rotate;degree--)
		{
			servomotor_rot(degree);
			_delay_ms(20);
		}
	}
}

ISR(USART_RXC_vect)
{
	choice = UART_u8ReceiveData();
	if(ROTATE_ON == choice)
	{
		rotate = ROTATE_ON;
	}
	else if(ROTATE_OFF == choice)
	{
		rotate = ROTATE_OFF;
	}
	else if(DC_MOTOR_ON == choice)
	{
		motor_ON('D',PINC4,MOTOR_SPEED1);
		dcmotor = DC_MOTOR_ON;
	}
	else if(DC_MOTOR_OFF == choice)
	{
		motor_OFF('C',PINC0);
		dcmotor = DC_MOTOR_OFF;
	}
    else if(SPEED1 == choice)
	{
		motor_ON('D',PINC4,MOTOR_SPEED1);
		dcmotor = DC_MOTOR_ON;
	}
	else if(SPEED2 == choice)
	{
		motor_ON('D',PINC4,MOTOR_SPEED2);
		dcmotor = DC_MOTOR_ON;
	}
    else if(SPEED3 == choice)
	{
		motor_ON('D',PINC4,MOTOR_SPEED3);
		dcmotor = DC_MOTOR_ON;
	}
    else if(SPEED4 == choice)
	{
		motor_ON('D',PINC4,MOTOR_SPEED4);
		dcmotor = DC_MOTOR_ON;
	}
	
}

