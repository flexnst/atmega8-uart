#include <avr/io.h>
#include <util/delay.h>

// Рабочая частота контроллера
#define F_CPU 1000000

// Скорость обмена данными
#define BAUD 9600L

//Согластно заданной скорости подсчитываем значение для регистра UBRR
#define UBRRL_value (F_CPU/(BAUD*16))-1

void uart_init() {
	UBRRL = UBRRL_value;       //Младшие 8 бит UBRRL_value
	UBRRH = UBRRL_value>>8;    //Старшие 8 бит UBRRL_value
	UCSRB |= (1<<TXEN) | (1<<RXEN );         //Бит разрешения передачи
	UCSRC |=(1<< URSEL)|(1<< UCSZ0)|(1<< UCSZ1); //Устанавливем формат 8 бит данных
}

void uart_putc(char value) {
	while(!( UCSRA & (1 << UDRE)));   // Ожидаем когда очистится буфер передачи
	UDR = value; // Помещаем данные в буфер, начинаем передачу
}

void uart_puts(char *s){
	while (*s)
		uart_putc(*s++);
}

int uart_getc(){
  while((UCSRA &(1<<RXC)) == 0);
  return UDR;
}

