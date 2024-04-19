//Lisbeth Ivelisse Arévalo Girón

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#include "UART.h"

int main(void)
{
	// Seleccionar PB2,PB3 y PB4 como salida
	DDRB |= (1<<4)|(1<<3)|(1<<2);	
	
	//Se inicia la función UART
	UART_init();					
	
	UART_escribir("Bienvenido al sistema de LEDS\n\r");
	UART_escribir("LED AMARILLO: Ingrese 1 para encenderlo y 2 para apagarlo\n\r");
	UART_escribir("LED AZUL:     Ingrese 3 para encenderlo y 4 para apagarlo\n\r");
	UART_escribir("LED VERDE:    Ingrese 5 para encenderlo y 6 para apagarlo\n\r");
	uint8_t dato=0;
	
	
	while (1)
	{
		dato = UART_read();			// Se leerán los datos de RX
		
		if(dato != 0)
		{
			switch(dato)
			{
				case '1':
				UART_escribir("LED AMARILLO encendido\n\r");
				PORTB|= (1<<2);
				break;
				
				case '2':
				UART_escribir("LED AMARILLO apagado\n\r");
				PORTB &= ~(1<<2);
				break;
				
				case '3':
				UART_escribir("LED AZUL encendido\n\r");
				PORTB|= (1<<3);
				break;
				
				case '4':
				UART_escribir("LED AZUL apagado\n\r");
				PORTB &= ~(1<<3);
				break;
				
				case '5':
				UART_escribir("LED VERDE encendido\n\r");
				PORTB|= (1<<4);
				break;
				
				case '6':
				UART_escribir("LED VERDE apagado\n\r");
				PORTB &= ~(1<<4);
				break;
			}
		}
	}
}