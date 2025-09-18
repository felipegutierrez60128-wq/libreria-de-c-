
# Sistema de Venta de Libros📚

Este proyecto en C++ simula una tienda de libros, permitiendo registrar compras y generar tickets con descuentos automáticos.🛠️

## Estructura del Proyecto📂

- **🧩Libreria.h / Libreria.cpp**: Define la clase base `Libreria`.
- **🧾libro.h / Libro.cpp**: Define la clase `Libro` que hereda de `Libreria`.
- **🧾Ticket.h / Ticket.cpp**: Define la clase `Ticket` que hereda de `Libro`.
- **main.cpp**: Contiene la lógica principal del programa.

## Instrucciones de Compilación y Ejecución🎯

1. **Abrir Visual Studio Code**.💻 
2. **Compilar**: 🚀
    - Abrir la terminal integrada.
    - Ejecutar el comando: `g++ -o main main.cpp Libreria.cpp Libro.cpp Ticket.cpp`
3. **Ejecutar**:
    - En la terminal, ejecutar: `./main`
