# Plugin: Entrenador Puertas Lógicas - MentorBit

Esta librería está construida por Digital Codesign para utilizar junto con los kits educacionales "MentorBit" y "Entrenador de Puertas Lógicas". La librería permite la simulación mediante software y MentorBit de componentes de electrónica digital más avanzados como Temporizadores, Contadores, Generadores de Señales digitales, Detectores de Flanco o Flip-Flops.

Puedes encontrar nuestro Entrenador de Puertas Lógicas y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

# Modo de empleo
Cuando tengas la librería instalada, debes incluir la librería al comienzo de tu sketch, antes del setup, con la siguiente línea:

  ``#include <LogicGates.h>``

En función del módulo que quieras utilizar, deberás importarlo de la misma manera que en el ejemplo.

## Atributos de la clase principal
La clase principal de la librería (LogicGates) permite acceso a diferentes valores constantes relativos a los puertos y los GPIOs mediante los cuales se realizaría la conexión entre el MentorBit y el Entrenador de Puertas Lógicas.

| Atributo | Descripción | Valor |
|:--|:--|:--|
| PUERTO_GENERICO_1 | Indicador de uso del Puerto Genérico 1 del Entrenador. | 0x03 |
| PUERTO_GENERICO_2 | Indicador de uso del Puerto Genérico 1 del Entrenador. | 0x04 |
| GPIO_AXX | Identificador de GPIO Analógico, donde XX es el número del GPIO. | PIN_AXX |
| GPIO_DXX | Identificador de GPIO Digital, donde XX es el número del GPIO. | XX |
| MILISEGUNDOS | Indicador de uso de milisegundos para los Módulos. | 0x20 |
| MICROSEGUNDOS | Indicador de uso de microsegundos para los Módulos. | 0x21 |

## Módulos
La librería implementa distintos módulos que separan el funcionamiento de los diferentes elementos que se pueden simular en MentorBit para utilizar con el Entrenador de Puertas Lógicas.

### Temporizador
Este módulo permite medir intervalos de tiempo específicos y generar acciones al finalizar los intervalos. Las funciones disponibles relacionadas con este módulo son:

| Función | Descripción |
|:--|:--|
| LogicGatesTimer() | Constructor del módulo, permite el uso del temporizador configurando posteriormente los parámetros de tiempo. |
| LogicGatesTimer(tiempo, unidad) | Constructor del módulo, permite el uso del temporizador entregando como argumentos los parámetros de configuración del temporizador. |
| iniciar() | Función para iniciar el temporizador. |
| establecer(tiempo, unidad) | Función para configurar un temporizador con los parámetros entregados como argumentos. |
| comprobar() | Función que debe llamarse continuamente para comprobar el estado del temporizador respecto al objetivo configurado, devolviendo True si el objetivo se alcanzó o False en caso contrario. |

### Contador
Este módulo permite realizar cuentas, almacenando un número de eventos o pulsos. Las funciones disponibles relacionadas con este módulo son:

| Función | Descripción |
|:--|:--|
| LogicGatesCounter(GPIO_Entrada) | Constructor del módulo, permite el uso del contador recibiendo como argumento el GPIO donde se recibirán las señales para realizar la cuenta progresiva. |
| comprobar() | Función que debe llamarse continuamente para comprobar el estado de la entradadel contador y actualizar la cuenta del mismo, devolviendo el valor actual de la cuenta almacenada. |
| reiniciar() | Función que reinicia el valor actual de la cuenta a cero. |

### Detector de Flancos
Este módulo permite identificar cambios en el nivel de una señal digital, ya sea cuando pasa de bajo a alto (flanco ascendente) o de alto a bajo (flanco descendente). Las funciones disponibles relacionadas con este módulo son:

| Función | Descripción |
|:--|:--|
| LogicGatesEdges(GPIO_Entrada) | Constructor del módulo, permite el uso del detector de flancos recibiendo como argumento el GPIO donde se obtendrán las lecturas en busca de flancos. |
| comprobarFlancoSubida() | Función que detecta un cambio de estado bajo a alto, devolviendo True si ocurre ese cambio o False en caso contrario. |
| comprobarFlancoBajada() | Función que detecta un cambio de estado alto a bajo, devolviendo True si ocurre ese cambio o False en caso contrario. |

### Generador de Señal.
Este módulo permite producir transiciones controladas entre niveles lógicos alto y bajo a intervalos específicos. Las funciones disponibles relacionadas con este módulo son:

| Función | Descripción |
|:--|:--|
| LogicGatesSignal(GPIO_Salida, frecuencia) | Constructor del módulo, permite el uso del generador de señales recibiendo como argumento el GPIO donde se generará la señal a la frecuencia indicada, recibida también como argumento. |
| iniciar() | Función para habilitar la generación de la señal creada. |
| detener() | Función para deshabilitar la generación de la señal creada. |
| editarFrecuencia(frecuencia) | Función para modificar la frecuencia de oscilación de la señal creada. |
| actualizar() | Función que debe llamarse continuamente para actualizar el estado de la señal y realizar las oscilaciones correspondientes en los momentos adecuados. |

### Flip-Flops
Este módulo permite simular un circuito secuencial biestable que puede almacenar un solo bit de información. Tiene dos estados estables y cambia entre ellos en respuesta a señales de entrada, como pulsos de reloj o disparadores. Permite la simulación de Flip-Flops de tipo D, T, SR y JK. Las funciones disponibles relacionadas con este módulo son:

| Función | Descripción |
|:--|:--|
| LogicGatesFlipFlopD(GPIO_D, GPIO_Q, GPIO_Qn, GPIO_CLK) | Constructor del módulo para Flip-Flops tipo D, recibiendo como argumentos los diferentes GPIOs para configurar las entradas y las salidas del Flip-Flop tipo D. |
| LogicGatesFlipFlopT(GPIO_T, GPIO_Q, GPIO_Qn, GPIO_CLK) | Constructor del módulo para Flip-Flops tipo T, recibiendo como argumentos los diferentes GPIOs para configurar las entradas y las salidas del Flip-Flop tipo T. |
| LogicGatesFlipFlopSR(GPIO_S, GPIO_R, GPIO_Q, GPIO_Qn, GPIO_CLK) | Constructor del módulo para Flip-Flops tipo SR, recibiendo como argumentos los diferentes GPIOs para configurar las entradas y las salidas del Flip-Flop tipo SR. |
| LogicGatesFlipFlopJK(GPIO_J, GPIO_K, GPIO_Q, GPIO_Qn, GPIO_CLK) | Constructor del módulo para Flip-Flops tipo JK, recibiendo como argumentos los diferentes GPIOs para configurar las entradas y las salidas del Flip-Flop tipo JK. |
| actualizar() | Función que debe llamarse continuamente para actualizar el estado de las salidas del Flip-Flop como corresponda según su tipo tras comprobar las entradas del mismo. |
| setear() | Función para establecer un Set en las salidas del Flip-FLop. |
| resetear() | Función para establecer un Reset en las salidas del Flip-Flop. |
| obtenerQ() | Función que devuelve el estado de la salida del Flip-Flop. |
| obtenerQnegada() | Función que devuelve el estado de la salida negada del Flip-Flop. |

### Binary Coded Decimal (BCD)
Este módulo permite simular un BCD, o circuito conversor de números binarios en su equivalente decimal. Las funciones disponibles relacionadas con este módulo son:

| Función | Descripción |
|:--|:--|
| LogicGatesBCD(GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3, GPIO_BIT_4) | Constructor del módulo, permite el uso del BCD indicando como argumento los GPIOs donde se leerán los cuatro bits que representan un número en binario. |
| leerEntradas() | Función que obtiene la lectura de los cuatro bits de entrada al BCD. |
