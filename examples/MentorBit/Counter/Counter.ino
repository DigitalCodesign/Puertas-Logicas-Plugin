#include <LogicGates.h> // Librería para acceder a los diferentes GPIOs del puerto
#include <LogicGatesCounter.h> // Librería para gestionar los contadores
#include <MentorBit.h> // Librería para gestionar elementos básicos del MentorBit

// Creamos las instancias de los diferentes objetos
LogicGates Trainer; // Objeto para acceder a los GPIOs del Puerto Genérico
MentorBit myMentorBit; // Objeto para los elementos básicos del MentorBit
LogicGatesCounter myCounter(Trainer.GPIO_D35); // Instancia para el contador

// Variable de referencia para comprobar cambios en el contador
int ultima_cuenta = 0;

// Bloque de inicialización
void setup() {

  // Establecemos el estado por defecto del GPIO escogido con PWM
  digitalWrite(myMentorBit.LED_ROJO, LOW);

}

// Bucle principal del programa
void loop() {

  // Obtenemos el valor actual del contador
  int cuenta_actual = myCounter.comprobar();
  // Comprobamos que el valor del contador haya cambiado
  if(ultima_cuenta != cuenta_actual) {

    // Configuramos la señal PWM con el valor del contador multiplicado por diez.
    // La multiplicación nos permitirá avanzar por el rango de valores posibles
    // de la PWM (de 0 a 255) con mayor rapidez.
    analogWrite(myMentorBit.LED_ROJO, cuenta_actual * 10);
    // Actualizamos el último valor de referencia del contador
    ultima_cuenta = cuenta_actual;

    // Comprobamos que se han alcanzado las 25 cuentas.
    // 25 * 10 = 250, casi el máximo valor para una PWM
    if(cuenta_actual > 5) {

      // Reiniciamos la cuenta del contador a cero
      myCounter.reiniciar();
      // Reiniciamos el último valor de referencia del contador
      ultima_cuenta = 0;
      // Generamos un tono de aviso
      tone(myMentorBit.ZUMBADOR, 2000, 100);

    }

  }

}