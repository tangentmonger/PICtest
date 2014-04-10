// Example code using the difference between the watchdog timer and timer1 as a source of random numbers. Note - this is not crypto-grade random and may or may not work well on any given chip.

#include <htc.h> 
// that's /usr/hitech/picc/9.83/include/htc.h
// which will include pic.h
// which has macros and also chip_select.h
// which selects e.g. pic16f690.h depending on contents of makefile

__CONFIG(FOSC_INTRCIO & WDTE_ON & PWRTE_ON & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_ON & IESO_OFF & FCMEN_ON);
//oscillator selection
//watchdog on
//power up timer enabled
//Master clear reset line pin Function on
//code protection off
//data code protection off
//brownout reset on
//internal external switchover bit off
//failsafe clock monitor on



void main(void)
{
    //how did we get here? hardware or watchdog reset?
    if(STATUSbits.nTO == 0b1){
        //hardware reset, not watchdog timeout
        //so, set everything up
        //Set PORTC to all outputs
        TRISC = 0x00;

        //clear LEDs
        PORTC = 0x01;

        //make sure timer was zeroed (it probably was already)
        TMR1L = 0x0;
        
        //start timer
        T1CONbits.TMR1ON = 0b1;

    //looks pretty random... apparently SMD components are more likely to synch up :(

        while(1){}; //spin and leave it to reset 

    }
    else
    {
        //reset by watchdog

        //Set PORTC to all outputs
        TRISC = 0x00;

        //Display the count on the PORTC pins
        PORTC = TMR1L; //lsb of timer
        
        //clear timer
        TMR1L = 0x0;

        //start timer
        T1CONbits.TMR1ON = 0b1;


        while(1){}; //spin and leave it to reset 
    }
}

