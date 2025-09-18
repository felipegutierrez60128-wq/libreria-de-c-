//
// Created by Felipe on 05/22/2025.
//

#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include "Libreria.h"
using namespace std;

class Libro : public Libreria {

protected:
    // Atributos
    string generos;
    int librosComprados;
    int numeroDeLibros;
public:
    // Constructores
    Libro();
    Libro(int librosComprados, int numeroDeLibros, string generos, string nombre);
    // Destructor
    virtual ~Libro() = default;

    // Setters
    void setLibrosComprados(int librosComprados);
    void setNumeroDeLibros(int numeroDeLibros);
    void setGenero(string generos);

    // Getters
    int getNumeroDeLibros() const;
    int getLibrosComprados() const;
    string getGenero() const;

    // Métodos
    int comprarLibros(int libroComprado);
    void mostrarCompradores() const override;//polimorfismo
};

#endif 
