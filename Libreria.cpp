//
// Created by felipe on 11/22/2024.
//
#include <iostream>
#include <iomanip>
#include <string>

#include "Libreria.h"

using namespace std;
Libreria libreria;

// Constructor por defecto
Libreria::Libreria() {
    nombre = "";
}

// Constructor con parámetros
Libreria::Libreria( string nombre) {
    this->nombre = nombre;
}

// Setters
void Libreria::setNombre(string nombre) {
    this->nombre = nombre;
}

// Getters
string Libreria::getNombre() const {
    return nombre;
}



// Mostrar información del comprador
void Libreria::mostrarCompradores() const {
    cout << "|_______________________________________|\n";
    cout << "|                Comprador              |\n";
    cout << "|Comprador: " << left << setw(28) << nombre << "|\n";
    cout << "|_______________________________________|\n";
}



