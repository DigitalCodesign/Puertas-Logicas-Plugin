#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesSignal.h> // Librería para gestionar las señales
#include <LogicGatesFlipFlopT.h> // Librería para gestionar los flip flops tipo T

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
LogicGatesSignal Signal_clk(Trainer.GPIO_D3, 5); // Primera señal de 5 Hz
LogicGatesFlipFlopT FlipFlopT( // Objeto para el Flip Flop tipo T
  Trainer.GPIO_D35, // GPIO del Puerto Genérico escogido para la entrada T
  Trainer.GPIO_D36, // GPIO del Puerto Genérico escogido para la salida Q
  Trainer.GPIO_D37, // GPIO del Puerto Genérico escogido para la salida Q negada
  Trainer.GPIO_D38 // GPIO del Puerto Genérico escogido para la entrada CLK
);

// Bloque de inicialización
void setup() {

  // Habilitamos la generación de la señal que usaremos como CLK
  Signal_clk.iniciar();

}

// Bucle principal del programa
void loop() {

  // Actualizamos la señal generada
  Signal_clk.actualizar();
  // Actualizamos el estado del Flip Flop
  FlipFlopT.actualizar();

}
