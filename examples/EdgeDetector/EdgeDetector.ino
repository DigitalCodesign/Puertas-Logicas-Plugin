#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesEdges.h> // Librería para gestionar los detectores de flancos

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
LogicGatesEdges Detector(Trainer.GPIO_D35); // Objeto para el Detector de flancos

// Bloque de inicialización
void setup() {

  // Configuramos el modo de funcionamiento de un GPIO del Puerto Genérico
  pinMode(Trainer.GPIO_D36, OUTPUT);
  // Establecemos el estado por defecto de dicho GPIO
  digitalWrite(Trainer.GPIO_D36, LOW);

}

// Bucle principal del programa
void loop() {

  // Comprobamos que se detecte un flanco de subida
  if(Detector.comprobarFlancoSubida()) {

    // Activamos el GPIO escogido del Puerto Genérico
    digitalWrite(Trainer.GPIO_D36, HIGH);
    // Esperamos un poco antes de continuar, así evitamos oscilaciones
    delay(100);

  }

  // Comprobamos que se detecte un flanco de bajada
  if(Detector.comprobarFlancoBajada()) {

    // Desactivamos el GPIO escogido del Puerto Genérico
    digitalWrite(Trainer.GPIO_D36, LOW);
    // Esperamos un poco antes de continuar, así evitamos oscilaciones
    delay(100);

  }

}
