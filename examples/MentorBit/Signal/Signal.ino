#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesSignal.h> // Librería para gestionar las señales
#include <MentorBit.h> // Librería para gestionar elementos básicos del MentorBit

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
MentorBit myMentorBit; // Objeto para los elementos básicos del MentorBit
LogicGatesSignal Signal_1(myMentorBit.LED_ROJO, 10); // Primera señal de 10 Hz
LogicGatesSignal Signal_2(myMentorBit.LED_AZUL, 5); // Segunda señal de 5 Hz

// Bloque de inicialización
void setup() {

  // Iniciamos la generación de ambas señales
  Signal_1.iniciar();
  Signal_2.iniciar();

}

// Bucle principal del programa
void loop() {

  // Actualizamos el estado de ambas señales
  Signal_1.actualizar();
  Signal_2.actualizar();

}
