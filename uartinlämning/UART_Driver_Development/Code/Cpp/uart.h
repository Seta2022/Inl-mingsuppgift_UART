#ifndef __UART_H
#define __UART_H

#include "stm32f4xx.h" // Inkluderar källkoden och referenser för arbete med STM32-Hårdvara
#include <stdio.h> //Inkluderar standard I/O för C

void USART2_Init(void); // Deklaration av funktionen för att initiera UART-kommunikation via USART2
void test_setup(void); //Kallar på och refererar till vår testfunktion ur UART.c, som ansvarar för att stäla in testförhållande i samband med UART.
#endif // Markerar slutet på headerfilen och avslutar header guard sektionen.