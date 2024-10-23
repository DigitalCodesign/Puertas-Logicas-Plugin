#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesCounter.h> // Librería para gestionar los contadores

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
LogicGatesCounter myCounter(Trainer.GPIO_D35); // Instancia para el contador

// Bloque de inicialización
void setup() {

  // Configuramos el modo de funcionamiento de un GPIO con PWM del Puerto Genérico
  pinMode(Trainer.GPIO_D3, OUTPUT);
  // Establecemos el estado por defecto del GPIO escogido con PWM
  digitalWrite(Trainer.GPIO_D3, LOW);

}

// Bucle principal del programa
void loop() {

  // Configuramos la señal PWM con el valor del contador multiplicado por diez.
  // La multiplicación nos permitirá avanzar por el rango de valores posibles
  // de la PWM (de 0 a 255) con mayor rapidez.
  analogWrite(Trainer.GPIO_D3, myCounter.comprobar() * 10);

  // Comprobamos que se han alcanzado las 25 cuentas.
  // 25 * 10 = 250, casi el máximo valor para una PWM
  if(myCounter.comprobar() > 25) {

    // Reiniciamos la cuenta del contador a cero
    myCounter.reiniciar();

  }

}
