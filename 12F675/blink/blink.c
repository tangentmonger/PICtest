// Connect up: RA5 - LED - resistor - GND 
// Connect scope to see LED blinking. 

// If it stops working, likely to be an OSCCAL problem. See makefile for fix

#include <htc.h> 
// that's /usr/hitech/picc/9.83/include/htc.h
// which will include pic.h
// which has macros and also chip_select.h
// which selects e.g. pic16f690.h depending on contents of makefile

__CONFIG(FOSC_INTRCCLK & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_OFF);
//oscillator selection: clock out on 4, IO on 5
//watchdog off
//power up timer enabled
//Master clear reset line pin Function on ...off (i.e. no reset switch)
//code protection off
//data code protection off
//brownout reset off

unsigned int uintDelayCount = 0;

void main(void)
{

    //digital IO
     ANSEL = 0x00;

    //no A/D
    ADCON0 = 0x00;

    //no comparator
    CMCON = 0x07;

    //no voltage reference
    VRCON = 0x00;

    //switch timer 1 to not use GP5 as an external clock
    T1CONbits.TMR1CS = 0x0;

    //Use TRISIO to set GPIO to all outputs except gp3 because it's input only
    TRISIO = 0x08;

    //Loop forever
    while ( 1 )
    {
        uintDelayCount = 0;
        while ( uintDelayCount < 255 )
        {
            uintDelayCount++;
        }

        GPIO = 0x27;
        
        uintDelayCount = 0;
        while ( uintDelayCount < 255 )
        {
            uintDelayCount++;
        }

        GPIO = 0x00;
    }
}

