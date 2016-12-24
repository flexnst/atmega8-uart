// AVR Atmega8 UART Lib

#ifndef	_UART_H
#define _UART_H
#include <avr/io.h>
#include <util/delay.h>
#endif

void uart_init();

void uart_putc(char value);

void uart_puts(char *s);

int uart_getc();
