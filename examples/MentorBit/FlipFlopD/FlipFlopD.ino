#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesSignal.h> // Librería para gestionar las señales
#include <LogicGatesFlipFlopD.h> // Librería para gestionar los flip flops tipo D
#include <MentorBit.h> // Librería para gestionar elementos básicos del MentorBit

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
MentorBit myMentorBit; // Objeto para los elementos básicos del MentorBit
LogicGatesSignal Signal_clk(Trainer.GPIO_D38, 5); // Primera señal de 5 Hz
LogicGatesFlipFlopD FlipFlopD( // Objeto para el Flip Flop tipo D
  Trainer.GPIO_D35, // GPIO del Puerto Genérico escogido para la entrada D
  myMentorBit.LED_VERDE, // LED Verde escogido para la salida Q
  myMentorBit.LED_ROJO, // LED Rojo escogido para la salida Q negada
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
  FlipFlopD.actualizar();

}