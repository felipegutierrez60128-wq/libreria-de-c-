//
// Created by felipe on 06/5/2025.
// Team Felipe, Daniel, Emiliano 
//
#include "Libro.h"
#include "Libreria.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Libro libro; // Objeto de la clase Libreria para usar sus métodos
//constructores
//*---------------------------------------------------------------------------------------------------------*
Libro ::Libro(){numeroDeLibros = 100; generos="";librosComprados = 0; } //constructor por defecto

Libro::Libro(int librosComprados,int numeroDeLibros, string generos, string nombre ):
::Libreria( nombre){ //Cosntructor con parámetros
    this->numeroDeLibros = numeroDeLibros;
    this->librosComprados = librosComprados;
    this->generos = generos;
}
/*---------------------------------------------------------------------------------------------------------*/

//setters
/*---------------------------------------------------------------------------------------------------------*/

void Libro::setGenero(string generos)
{
    
    this->generos = generos; 
}

void Libro::setNumeroDeLibros(int numeroDeLibros){ 
    if (numeroDeLibros < 0)
    {
        cout<<"Ya no quedan libros por vender"<<endl;
        numeroDeLibros += 100; //Reabastecimiento de libros en caso de que se acaben
        cout<<"Se han reabastecido "<<numeroDeLibros<<" libros"<<endl;
    }else{
        numeroDeLibros = numeroDeLibros - librosComprados; 
    }
    this->numeroDeLibros = numeroDeLibros;
}

void Libro::setLibrosComprados(int librosComprados) 
{
    if (librosComprados < 0)
    {
        cout<<"No se han comprado libros"<<endl;
    }
    this->librosComprados = librosComprados;
}
/*---------------------------------------------------------------------------------------------------------*/

//getters
/*---------------------------------------------------------------------------------------------------------*/
int Libro::getNumeroDeLibros()const 
{
    return numeroDeLibros;
}
int Libro::getLibrosComprados()const
{
    
    return librosComprados;
}
string Libro::getGenero()const 
{
    return generos;
}
/*---------------------------------------------------------------------------------------------------------*/


// Métodos de la clase Libro
/*---------------------------------------------------------------------------------------------------------*/
/*En este metodo se registran los libros comprados 
y se actualiza el número de libros disponibles.
Si no hay suficientes libros, se muestra un mensaje de error.
*/ 
int Libro::comprarLibros(int libroComprado)  
{
    if (libroComprado > numeroDeLibros)
    {
        cout<<"No hay suficientes libros disponibles"<<endl;
        return 0;
    }
    librosComprados = libroComprado; 
    
    numeroDeLibros -= librosComprados; 
    return librosComprados;
}

//Método para mostrar y guardar el genero de libro que se ha comprado
void Libro::mostrarCompradores() const 
{
    Libreria::mostrarCompradores(); // Llamada al método de la clase base Libreria
    cout<<"|Género de libros: "<< left << setw(21)<<generos<<"|"<<endl;
    cout << "|Libros comprados: " << left << setw(21) << librosComprados << "|\n";
   
}