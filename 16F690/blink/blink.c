//Flashes the LEDs on a PICkit2 demo board.

#include <htc.h> 
// that's /usr/hitech/picc/9.83/include/htc.h
// which will include pic.h
// which has macros and also chip_select.h
// which selects e.g. pic16f690.h depending on contents of makefile

__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_ON & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_ON & IESO_OFF & FCMEN_ON);
//oscillator selection
//watchdog off
//power up timer enabled
//Master clear reset line pin Function off (i.e. no reset switch)
//code protection off
//data code protection off
//brownout reset on
//internal external switchover bit off
//failsafe clock monitor on


//Setup variables
unsigned char ucharCount = 0;
unsigned int uintDelayCount = 0;

void main(void)
{
    //Set PORTC to all outputs
    TRISC = 0x00;

    //Set PORTA to all outputs
    TRISA = 0x00;

//"Another example of potential disaster is that PORTA, pin 4 exhibits unusual behavior when used as an output. This is because the pin has an open drain output rather then the usual bipolar stage of the rest of the output pins. This means it can pull to ground when set to 0, but it will simply float when set to a 1, instead of going high. To make this pin act in the expected manner, add a pull-up resistor between the pin and 5 volts. The value of the resistor may be between 1K and 33K, depending on the drive necessary for the connected input. This pin acts as any other pin when used as an input."

    ucharCount = 0;
    uintDelayCount = 0;

    //Loop forever
    while ( 1 )
    {
        //Delay Loop
        while ( uintDelayCount < 10000 )
        {
            //Increment the loop counter
            uintDelayCount++;
        }

        //Reset delay loop counter
        uintDelayCount = 0;

        //Increment the count
        ucharCount++;

        //Display the count on the PORTC pins
        PORTC = ucharCount;
        PORTA = ucharCount;

    }

}

