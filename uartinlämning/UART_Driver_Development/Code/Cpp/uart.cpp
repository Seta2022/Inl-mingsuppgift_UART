#include "UART.h" //Hämtar vår headerfilen uart.h som innehåller deklarationer och definitioner relaterad till UART-kommunikation.

void USART2_Init(void) { //Deklarerar en funktion för att initiera USART-protkokollet och dess beståndsdelar

// 1. Enablea klocktillgång för uart2

RCC->APB1ENR |= 0x20000; // Sätter bit 17 i registret APB1ENR för att aktivera UART2 genom att använda bitvis I/O-operation.

// 2. Enablea klocktillgång för portA

RCC->AHB1ENR |= 0x01; // Sätter bit 0 i registret AHB1ENR för att aktivera GPIO-port A genom att använda bitvis I/O-operation. 

// 3. Enablea pins relaterade till vald port, för alternativ funktion
GPIOA->MODER &= ~0x00F0; //Rensar bitarna 4-7 i registret MODER för GPIO-port A för att förbereda pins PA2 och PA3 genom att använda bitvis I/O-operation.


GPIOA->MODER |= 0x00A0; /* Sätter bitarna 5 och 7 i registret MODER för GPIO-port A till 1 för att aktivera alternativ funktionalitet
                           på pins PA2 och PA3 genom att använda bitvis I/O-operation.
                         */

// 4. Välja typen av alternativ funktion för de valde pinsen
GPIOA->AFR[0] &= ~0xFF00; // Rensar bitarna 8-15 i det första elementet i register AFR för GPIO-port A för att förbereda pins PA2 och PA3 genom att använda bitvis I/O-operation.
GPIOA->AFR[0] |= 0x7700; // Sätter bitarna 8-11 och 12-15 i det första elementet i registret AFR för GPIO-port A till binärvärdet 0111 genom att använda bitvis I/O-operation.

/* Konstruktion av enhetens kommunikation avslutas */

// Konfiguration utav UART

USART2->BRR = 0x0683; // Sätter registret BRR för USART2 till värdet 0x0683, som motsvarar en baudhastighet på 9600 bps.
USART2->CR1 = 0x000C; // Sätter registret CR1 för USART2 till värdet ox000C, vilket konfigurerar överföringen för 8 bitar data, 1 stoppbit och ingen paritet.
USART2->CR2 = 0x000; // Sätter registret CR2 för USART2 till 0, vilket nollställer dess innehåll.
USART2->CR3 = 0x000; // Sätter registret CR3 för USART2 till 0, vilket nollställer dess innehåll.
USART2->CR1 |= 0x2000; // Sätter bit 13 i registret CR1 för USART2 till 1 genom att använda bitvis I/O-operation, vilket aktiverar UART-kommunikationen.

}

// UART Write
int USART2_write(int ch){ //Deklarerar skrivfunktionen (Överföringen av data till terminalen)

  while(!(USART2->SR & 0x0080)){} //Skapar en loop som fortsätter tills USART2:s SR register signalerar att överföringen är klar för att ta emot nästa tecken(byte).
  USART2->DR = (ch & 0xFF); //Tilldelar de lägsta 8 bitarna av argumentet ch till registret DR för USART2, vilket sätter igång överföring av det tecknet(bytet).

  return ch; // Returnerar värdet av argumentet ch.

}

// UART Read
int USART2_read(void){ //Deklarerar läsfunktionen (mottagning av information)

  while(!(USART2->SR & 0x0020)){} // while loop som fortsätter tills bit 5 (RXNE) i registret SR för USART2 är satt, vilket indikerar att det finns mer data att hämta.
  return USART2->DR; // Returnerar värdet(läser ut datan) i registret DR för USART2, vilket innehåller mottagen data.
}
