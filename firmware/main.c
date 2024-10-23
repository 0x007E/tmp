
#define F_CPU 12000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "adc/adc.h"
#include "uart/uart.h"

int main(void)
{
    adc_init();
    adc_channel(0);
	
	uart_init();
    
    while (1) 
    {
        unsigned int adc = adc_read();
        
        unsigned int voltage = ((adc * 5000UL)>>10);  // >> 10 -> /1024
        unsigned char temp = (10 * adc - 2040UL) / 41UL;
        
		printf("Voltage: %4u, Temperature: %3u\r", voltage, temp);
		
        _delay_ms(500);
    }
}

