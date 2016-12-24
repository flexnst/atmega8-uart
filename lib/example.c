#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main(void){

	char c;
	uart_init();
	uart_puts("ATmega8");

	while(1)
	{
		c = uart_getc();
		uart_putc(c);
	}
	return 0;
}
