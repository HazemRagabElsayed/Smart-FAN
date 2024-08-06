
#ifndef COMMON_HEADER
#define COMMON_HEADER



/*libraries includes start */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
/*libraries includes end */


/* user includes start */

#include "std_macros.h"
#include "timer.h"
#include "USART.h"
#include "Servomotor.h"
#include "DIO.h"
#include "Motor.h"

/* user includes end */

/*macro declerations Start*/

#define F_CPU 8000000UL

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

#define DC_MOTOR_OFF '0'
#define DC_MOTOR_ON  '1'

#define ROTATE_OFF '2'
#define ROTATE_ON  '3'


#define MAXPOSDEGREE 90
#define MAXNEGDEGREE -90

#define SERVO_MOTOR 'S'
#define DC_MOTOR 'D'

#define SPEED1 '4'
#define SPEED2 '5'
#define SPEED3 '6'
#define SPEED4 '7'

#define MOTOR_SPEED1 ('4' - '0')
#define MOTOR_SPEED2 ('5' - '0')
#define MOTOR_SPEED3 ('6' - '0')
#define MOTOR_SPEED4 ('7' - '0')

/*macro declerations End*/



#endif