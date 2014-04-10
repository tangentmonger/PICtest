// Example of using the difference between the watchdog timer and timer1 as a source of randomness. Note: this is NOT crypto-grade random and may or may not work well on any individual chip.

// Connect up: RA{0,1,2} to RC{0,1,2}
// If it stops working, likely to be an OSCCAL problem. See makefile for fix

#include <htc.h> 

// /usr/hitech/picc/9.83/include/pic16f690.h
__CONFIG(FOSC_INTRCCLK & WDTE_ON & PWRTE_OFF & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_OFF);

//oscillator selection: clock out on 4, IO on 5
//watchdog on
//power up timer enabled
//Master clear reset line pin Function on ...off (i.e. no reset switch)
//code protection off
//data code protection off
//brownout reset off


void main(void)
{
    //switch timer 1 to not use GP5 as an external clock
    //T1CONbits.TMR1CS = 0x0;

    //Use TRISIO to set GPIO to all outputs except gp3 because it's input only
    TRISIO = 0x08;

    //Loop forever
    if(STATUSbits.nTO == 0b1){
        //hardware reset
        GPIO = 0x01;
        TMR1L = 0x0;
        //start timer
        T1CONbits.TMR1ON = 0b1;
        while(1){}
    }
    else
    {
        //watchdog reset
        
        GPIO = TMR1L;
        TMR1L= 0x0;
        T1CONbits.TMR1ON = 0b1;
        while(1){}
    }

}



