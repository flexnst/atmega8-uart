# ATmega8 UART

UART with 9600/8-N-1

## Example

```
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

#define BAUD [1200|4800|9600|19200|38400|57600|115200]L

int main(void){
    uart_init();
    uart_puts("ATmega8");
    uart_putc('O');
    uart_putc('K');
    
    // Echo
    char c;
    while(1){
        c = uart_getc();
        uart_putc(c);
    }
}
```
