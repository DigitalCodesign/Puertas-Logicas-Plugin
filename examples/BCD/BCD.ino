#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesBCD.h> // Librería para gestionar el BCD

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
LogicGatesBCD myBCD( // Objeto para el BCD
  Trainer.GPIO_D35, // GPIO del Puerto Genérico escogido para el primer bit de entrada
  Trainer.GPIO_D36, // GPIO del Puerto Genérico escogido para el segundo bit de entrada
  Trainer.GPIO_D37, // GPIO del Puerto Genérico escogido para el tercer bit de entrada
  Trainer.GPIO_D38 // GPIO del Puerto Genérico escogido para el cuarto bit de entrada
);

// Bloque de inicialización
void setup() {

  // Inicializamos el monitor serial
  Serial.begin(9600);

}

// Bucle principal del programa
void loop() {

  // Mostramos por el monitor serial la lectura de los bits de entrada (en BINario)
  Serial.println(myBCD.leerEntradas(), BIN);
  // Esperamos un poco antes de continuar
  delay(100);

}
