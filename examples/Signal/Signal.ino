#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesSignal.h> // Librería para gestionar las señales

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
LogicGatesSignal Signal_1(Trainer.GPIO_D35, 10); // Primera señal de 10 Hz
LogicGatesSignal Signal_2(Trainer.GPIO_D36, 5); // Segunda señal de 5 Hz

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
