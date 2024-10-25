#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesEdges.h> // Librería para gestionar los detectores de flancos
#include <MentorBit.h> // Librería para gestionar elementos básicos del MentorBit

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
MentorBit myMentorBit; // Objeto para los elementos básicos del MentorBit
LogicGatesEdges Detector(Trainer.GPIO_D35); // Objeto para el Detector de flancos

// Bloque de inicialización
void setup() {

  // Establecemos el LED Rojo del MentorBit por defecto apagado
  digitalWrite(myMentorBit.LED_ROJO, LOW);
  // Establecemos el LED Verde del MentorBit por defecto apagado
  digitalWrite(myMentorBit.LED_VERDE, LOW);

}

// Bucle principal del programa
void loop() {

  // Comprobamos que se detecte un flanco de subida
  if(Detector.comprobarFlancoSubida()) {

    // Activamos el LED Rojo del MentorBit
    digitalWrite(myMentorBit.LED_ROJO, HIGH);
    // Esperamos un poco antes de continuar, así evitamos oscilaciones
    delay(100);
    // Desactivamos el LED Rojo del MentorBit
    digitalWrite(myMentorBit.LED_ROJO, LOW);

  }

  // Comprobamos que se detecte un flanco de bajada
  if(Detector.comprobarFlancoBajada()) {

    // Activamos el LED Verde del MentorBit
    digitalWrite(myMentorBit.LED_VERDE, HIGH);
    // Esperamos un poco antes de continuar, así evitamos oscilaciones
    delay(100);
    // Desactivamos el LED Verde del MentorBit
    digitalWrite(myMentorBit.LED_VERDE, LOW);

  }

}