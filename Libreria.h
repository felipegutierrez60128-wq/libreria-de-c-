//
// Created by Felipe on 03/06/2024.
//

#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <string>


/*
Clase Libros, en esta clase obtenemos el nombre del cliente,
usando el método virtual de mostrar.
*/

using namespace std;

class Libreria {
   
protected:
    // Atributos
    string nombre;
public:
    // Constructores
    Libreria();
    Libreria( string nombre);

    // Destructor
    ~Libreria() {}

    // Getters
    string getNombre() const;
    

    // Setters
    void setNombre( string nombre);

    // Métodos
    virtual void mostrarCompradores() const;
    
};

#endif
