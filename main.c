//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include <msp430g2553.h>
#include "lab8h.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void)
{

	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	P1DIR = BIT0 | BIT6;										//set LEDs as outputs

	//directional control
	P2DIR |= BIT1;                          // P2.1 is left directional control
	P2DIR |= BIT3;                          //P2.3 is right directional control

	//left motor
	P2DIR |= BIT2;                          // P2.2 is associated with TA1CCR1
	P2SEL |= BIT2;                          // P2.2 is associated with TA1CCTL1
	P2DIR |= BIT0;							//enables left motor
	P2OUT &= ~BIT0;							//disables left motor

	//right motor
	P2DIR |= BIT4;                          // P2.4 is associated with TA1CCR2
	P2SEL |= BIT4;                          // P2.4 is associated with TA1CCTL2
	P2DIR |= BIT5;							//enables right motor
	P2OUT &= ~BIT5;							//disables right motor

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
	TA1CCR0 = 0x0100;						// set signal period

	TA1CCR1 = 0x0050;

	TA1CCR2 = 0x0050;

	while(1)
		{
			readLeft();
			readCenter();
		} // end infinite loop
} // end main


