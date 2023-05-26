#include "LED.h" //Denna rad inkluderar en extern header fil som innehåller deklarationerna för LED-Beteckningar och funktioner som används i koden.


/*Detta är konstruktorn för LED-lamporna. Den tar emot två parametrar: "_color", 
som representerar färgen för LED-lampan och "_state", som repsrenterar dess status.
*/
Led::Led(LedColor_Type _color, LedState_Type _state)
{
// Dessa två rader tilldelar värdena av "_color" och "_state" till medlemsvariablerna "color" och "state" för den aktuella instansen av LED-lampan.
  this->color = _color;
  this->state = _state;


  /*
  Denna rad aktiverar klockan för LED-porten (GPIOB). Genom att ändra värdet på registret "AHB1ENR" med hjälp av bitvis
  ELLER-operator "|=" aktiveras klocksignalen för GPION-porten.
  */
  RCC->AHB1ENR |= LED_PORT_CLOCK;

  // Här är en switch som väljer kod baserat på värdet av "_color". Den används också för att konfigurera LED-pinsen baserat på "_color".
  switch(_color){

    case RED: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_RED_MODE_BIT; // Denna rad sätter läget för LED-portens (GPIOB) pin till output genom att ändra värdet på registret "MODER" med hjälp av bitvis ELLER-operator "|=".
      
      /* 
      Nedanför raderna kontrollerar LED_lampans "state". När statusen är satt till "ON", aktiveras motsvarande pin
      i LED-porten (GPIOB) genom att ändra värdet på registret "ODR" med hjälp av bitvis ELLER-operator "|=".
      Om statusen inte är "ON" nollställs motsvarande pin genom att ändra värdet på registret "ODR" med bitvis OCH-operator "&=" 
      tillsammans med komplementoperatorn "~".

      */

      if(this->state == ON){
        //Slår på LED
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Slår av LED
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        //Slår på LED
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Slår av LED
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        //Slår på LED
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Slår av LED
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        //Slår på LED
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Slår av LED
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;

  }


}
/*
Här ändras statusen för LED-lampan. Den tar emot parameter "_state" som representerar den ny statusen för LED-lampan.
Funktionen uppdaterar sedan medlemsvariabeln "state" för den aktuella instansen av LED-lampan och Konfigurerar LED-porten och 
dess pin baserat på den angivna statusen, på samma sätt som i konstruktorn. 
*/
void Led::setState(LedState_Type _state){

  //Sätter statusen för LED:n
  this->state = _state;

  //Kontrollerar färgen på LED för att veta vilken LED som ska användas.
  switch(this->color){

      //om LED Röd
    case RED:
      //sätter pin till outputläge
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinens ouput till aktiv
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW:
      //sätter pin till outputläge
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinens output till aktiv
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Definerar pinens output till inaktiv
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinens output till aktiv
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Definerar pinens output till inaktiv
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinens output till aktiv
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Definerar pinens output till inaktiv
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}
/*
Detta är en funktion som returnerar statusen för LED-lampan. Den söker efter vilken färg på LED-lampan som efterfrågas och skickar 
tillbaka sedan motsvarande status för den färgen, genom använda den aktuella instansens medlemsvaribler.
*/
LedState_Type Led::getState(void)const{

  //Kontrollera färgen på den efterfrågade LED-lampan, men gör ingen i varje fall.
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             //Returnerar statusen för den valda LED-lampan.
             return this->state;
}