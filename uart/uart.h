#include <avr/io.h>
#include <util/delay.h>

void uart_init();

void uart_putc(char value);

void uart_puts(char *s);

int uart_getc();
