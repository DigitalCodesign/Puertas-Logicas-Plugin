#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesTimer.h> // Librería para gestionar los temporizadores
#include <MentorBit.h> // Librería para gestionar elementos básicos del MentorBit

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
MentorBit myMentorBit; // Objeto para los elementos básicos del MentorBit
LogicGatesTimer myTimer1(1500, Trainer.MILISEGUNDOS); // Primer temporizador
LogicGatesTimer myTimer2(500, Trainer.MILISEGUNDOS); // Segundo temporizador

// Variables para controlar el flujo del programa
bool timer_1_running = false; // Indica que se debe vigilar el primer temporizador
bool timer_2_running = false; // Indica que se debe vigilar el segundo temporizador

// Bloque de inicialización
void setup() {

  // Configuramos el LED Rojo con el estado por defecto
  digitalWrite(myMentorBit.LED_ROJO, LOW);

  // Iniciamos el temporizador 1
  myTimer1.iniciar();
  // Habilitamos la vigilancia del primer temporizador
  timer_1_running = true;

}

// Bucle principal del programa
void loop() {

  // Comprobamos que vigilando el primer temporizador éste alcance su objetivo
  if((myTimer1.comprobar() == true) && (timer_1_running == true)) {

    // Activamos el LED Rojo
    digitalWrite(myMentorBit.LED_ROJO, HIGH);
    // Iniciamos el segundo temporizador
    myTimer2.iniciar();
    // Deshabilitamos el primer temporizador
    timer_1_running = false;
    // Habilitamos el segundo temporizador
    timer_2_running = true;

  }

  // Comprobamos que vigilando el segundo temporizador éste alcance su objetivo
  if((myTimer2.comprobar() == true) && (timer_2_running == true)) {

    // Desactivamos el LED Rojo
    digitalWrite(myMentorBit.LED_ROJO, LOW);
    // Iniciamos el primer temporizador
    myTimer1.iniciar();
    // Habilitamos el primer temporizador
    timer_1_running = true;
    // Deshabilitamos el segundo temporizador
    timer_2_running = false;

  }

}
