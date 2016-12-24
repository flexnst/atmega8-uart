# My ATmega8 libs

## UART

UART with 9600/8-N-1, for change:

    #define BAUD [1200|4800|9600|19200|38400|57600|115200]L

### Usage:

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
