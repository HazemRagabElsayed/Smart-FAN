/*
 * timer.c
 *
 * Created: 9/25/2019 7:22:07 PM
 *  Author: Hazem Ragab Elsayed
 */ 
 

#include "COMMON.h"

void timer_CTC_init_interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=80;
	/* select timer clock */	
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
}


void timer_wave_nonPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,PINB3);
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* toggle OC0 on compare match*/
	SET_BIT(TCCR0,COM00);
}

void timer1_wave_fastPWM(double value,unsigned char motor)
{
	/* set OC1A as output pin */
	SET_BIT(DDRD,PIND5);
    SET_BIT(DDRD,PIND4);
	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
switch (motor)
{
case DC_MOTOR :
OCR1B=value*1000;
ICR1=19999;
/* select timer clock, prescaler 8 */
SET_BIT(TCCR1B,CS11);
/* clear OC1B on compare match, set OC1B at BOTTOM,(non inverting mode)*/
SET_BIT(TCCR1A,COM1B1);
break;
case SERVO_MOTOR:
/* load a value in OCR1A,ICR1 */
OCR1A=value*1000;
ICR1=19999;
/* select timer clock, prescaler 8 */
SET_BIT(TCCR1B,CS11);
/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
SET_BIT(TCCR1A,COM1A1);
break;
default:;

}

	
}

void timer_wave_phasecorrectPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select phase correct PWM mode*/
	SET_BIT(TCCR0,WGM00);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}
