#include "led.h" // Led Header filen Hämtar definitioner och deklarationer för LED funktioner och typer.

/*
Nedanför raderna 7-9 deklarerar tre variabler av typen "LedState_Type", som används för att hålla koll på tillståndet
för tre olika LED-lampor. Lamporna representeras av "led1_state, led2_state, led3_state"
*/ 

LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;
/*
Led-objekt med namnet led1, med attribut color "RED och state "ON".
Detta innebär att "led1" är en röd LED-lampa som är påslagen.
*/
Led led1(RED,ON);
/* 
Här börjar main funktionen, som anropar "USART2_Init()", som initialiserar kommunikationen via USART2-porten.
*/
int main(void){ //huvudfunktion konstruerar och hanterar LED-lamporna
  USART2_Init();
/*
Led-objekt med namnet led2, med attribut color "BLUE och state "ON".
Detta innebär att "led1" är en Blå LED-lampa som är påslagen.
*/
  Led led2(BLUE,ON);
/*Denna rad skapar en pekaren av "led*" med namnet "led3" och tilldelar den en nyallokerad LED-objekt. 
Led-objektet initieras med färgen "YELLOW" och state "ON".
Detta innebär att "led3" är en Gul LED-lampa som är påslagen.
*/
  Led *led3 = new Led(YELLOW,ON);
 // Tilldela led1_state variabeln tillståndet för led1-lampan genom att anropa getState()-metoden på "led1"
  led1_state = led1.getState();
// Ändra tillståndet för led1-lampan till "OFF" genom att anropa setState()-metoden på led1 med argumentet "OFF"
  led1.setState(OFF);
// Frigör minnet som allokerades för "led3" pekaren genom att använda delete-operatorn. Detta förstör led3-objektet och gör minnet tillgängligt för nåt annat.
  delete led3;
// En oändlig while loop som håller programmet körande. Används för att förhindra att programmet avslutas direkt efter att koden ovanför har exekverats. 
  while(1){}

}
