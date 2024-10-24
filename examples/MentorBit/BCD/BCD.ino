#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesBCD.h> // Librería para gestionar el BCD
#include <MentorBitDisplay.h> // Librería para gestionar el Display 7 Segmentos del MentorBit

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
MentorBitDisplay myDisplay; // Objeto para el Display 7 Segmentos del MentorBit
LogicGatesBCD myBCD( // Objeto para el BCD
  Trainer.GPIO_D35, // GPIO del Puerto Genérico escogido para el primer bit de entrada
  Trainer.GPIO_D36, // GPIO del Puerto Genérico escogido para el segundo bit de entrada
  Trainer.GPIO_D37, // GPIO del Puerto Genérico escogido para el tercer bit de entrada
  Trainer.GPIO_D38 // GPIO del Puerto Genérico escogido para el cuarta bit de entrada
);

// Bloque de inicialización
void setup() {

  // Inicializamos el Display 7 Segmentos del MentorBit
  myDisplay.inicializarDisplay();

}

// Bucle principal del programa
void loop() {

  // Mostramos por el Display la lectura del BCD
  myDisplay.imprimir(myBCD.leerEntradas());
  // Esperamos un poco antes de continuar
  delay(250);

}
