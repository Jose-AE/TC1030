# Serpientes y Escaleras en C++

Este es un simple juego de Serpientes y Escaleras implementado en C++. El juego utiliza conceptos de programación orientada a objetos y cuenta con una interfaz de consola.

## Instrucciones de compilación

Para compilar el programa, sigue los siguientes pasos:

1. Asegúrate de tener un compilador de C++ instalado en tu sistema.
2. Descarga todos los archivos fuente del programa en la misma carpeta.
3. Abre una terminal o línea de comandos en la carpeta donde se encuentran los archivos fuente.
4. Ejecuta el siguiente comando para compilar los archivos:

   ```
   g++ snake.cpp -o snake
   ```

   Este comando compilará el archivo "snake.cpp" y generará un archivo ejecutable llamado "snake".

## Instrucciones de ejecución

Una vez que hayas compilado el programa, puedes ejecutarlo siguiendo estos pasos:

1. Abre una terminal o línea de comandos en la carpeta donde se encuentra el archivo ejecutable "snake".
2. Ejecuta el siguiente comando para iniciar el juego:

   ```
   ./snake
   ```

3. Sigue las instrucciones que aparecen en la consola para jugar el juego. Utiliza la tecla "C" para continuar al siguiente turno o la tecla "E" para terminar el juego.

## Conceptos de programación orientada a objetos utilizados

En este programa de Serpientes y Escaleras en C++, se utilizaron los siguientes conceptos de programación orientada a objetos:

- Clases: Se definieron varias clases, como `Player`, `Board` y `Dice`, para representar diferentes entidades del juego y encapsular su comportamiento y propiedades.
- Objetos: Se crearon instancias de las clases mencionadas anteriormente, como `GameDice`, `GameBoard` y `players`, para utilizar sus funcionalidades y mantener el estado del juego.
- Encapsulación: Se utilizaron modificadores de acceso (`public` y `private`) para controlar el acceso a los miembros de clase y proteger los datos internos.

## Justificación de las decisiones de diseño

- Separación de responsabilidades: Se separaron las responsabilidades del juego en diferentes clases, como `Player`, `Board` y `Dice`. Esto permite un diseño más modular y facilita la modificación y ampliación del juego en el futuro.
- Uso de arreglos y bucles: Se utilizó un arreglo de cadenas para representar las baldosas del tablero y un bucle para imprimir el tablero en la consola. Esto proporciona una forma eficiente y escalable de manejar el tablero del juego.
- Generación aleatoria de elementos del juego: Se utilizó una función de generación de números aleatorios para colocar aleatoriamente serpientes y escaleras en el tablero. Esto agrega variabilidad y emoción al juego.
- Interfaz de consola simple: El juego utiliza una interfaz de consola básica para mostrar el estado del tablero y las acciones del jugador. Esto permite una
