#include <msp430g2553.h>
#include "lab8h.h"

void readLeft()
{
	//configure p1.3 to read left IR
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = INCH_3 | ADC10DIV_3 ;						// Channel 3, ADC10CLK/4
	ADC10AE0 = BIT3;		 								// Make P1.3 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	if (ADC10MEM > 0x0180)
	{
		P1OUT |= BIT0;
		pause();
		bigRightTurn();
		readLeft();
	}
	else if (ADC10MEM > 0x0100)
	{
		P1OUT |= BIT0;
		pause();
		bigRightTurn();
		readLeft();
	}
	else
	{
		P1OUT &= ~BIT0;
		moveForward();
	}
}

void readCenter()
{
	// Configure P1.4 to read center IR
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT4;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	if (ADC10MEM > 0x012A)
	{
		P1OUT |= BIT0 | BIT6;
		pause();
		bigLeftTurn();
		readCenter();
	}
	else
		{
		P1OUT &= ~BIT0 & ~BIT6;
		moveForward();
		}
}

void readRight()
{
	//configure p1.5 to read right IR
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = INCH_5 | ADC10DIV_3 ;						// Channel 5, ADC10CLK/4
	ADC10AE0 = BIT5;		 								// Make P1.5 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	if (ADC10MEM > 0x01D5)
	{
		P1OUT |= BIT6;
		pause();
		bigLeftTurn();
		readRight();
	}
	else
		{
		P1OUT &= ~BIT6;
		moveForward();
		}
}

void moveForward(void)
{
	//left motor
	P2OUT |= BIT0;						//enable left motor
	P2OUT |= BIT1;                     //move left wheel forward
	TA1CCTL1 = OUTMOD_7;

	//right motor
	P2OUT |= BIT5;						//enable right motor
	P2OUT &= ~BIT3;                     //move right wheel forward
	TA1CCTL2 = OUTMOD_3;

	int i,k;
	for(i = 0; i < 2500; i++)
	{
		for(k = 0; k < 10; k++);
	}
}


void bigLeftTurn(void)
{
	//left motor
	P2OUT |= BIT0;						//enable left motor
	P2OUT &= ~BIT1;                     //move left wheel backwards
	TA1CCTL1 = OUTMOD_3;

	//right motor
	P2OUT |= BIT5;						//enable right motor
	P2OUT &= ~BIT3;                     //move right wheel forward
	TA1CCTL2 = OUTMOD_3;

	int i,k;
	for(i = 0; i < 6150; i++)
	{
		for(k = 0; k < 10; k++);
	}
}



void bigRightTurn(void)
{
	//left motor
	P2OUT |= BIT0;						//enable left motor
	P2OUT |= BIT1;                     //move left wheel forward
	TA1CCTL1 = OUTMOD_7;

	//right motor
	P2OUT |= BIT5;						//enable right motor
	P2OUT |= BIT3;                     //move right wheel backwards
	TA1CCTL2 = OUTMOD_7;

	int i,k;
	for(i = 0; i < 6000; i++)
	{
		for(k = 0; k < 10; k++);
	}
}

void pause(void)
{
	//disable both motors
	P2OUT &= ~BIT0;
	P2OUT &= ~BIT5;

	int i,k;
	for(i = 0; i < 2000; i++)
	{
		for(k = 0; k < 100; k++);
	}
}
