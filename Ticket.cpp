#include "Libro.h"
#include "Ticket.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;
Ticket ticket;

// Constructor por defecto
Ticket::Ticket(){
    fechaCompra = "";
    totalPago = 0.0;
    generarFechaCompra();
    
}
//constrcutor
Ticket::Ticket(string fechaCompra, double totalPago, int librosComprados, int numeroDeLibros, string generos, string nombre) 
    : Libro(librosComprados, numeroDeLibros, generos, nombre){
    this->fechaCompra = fechaCompra;
    this->totalPago = totalPago;
    generarFechaCompra();
    }

double Ticket::getTotalPago() const {
    return totalPago;
}

// Método para generar la fecha de compra
void Ticket::generarFechaCompra() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    fechaCompra = string(buffer);
}

// Método para calcular el total a pagar
double Ticket::calcularTotal(int librosComprados) {
    const double PRECIO_LIBRO = 200.0;
    totalPago = librosComprados * PRECIO_LIBRO;
    return totalPago;
}

// Método para mostrar los compradores y la fecha de compra
void Ticket::mostrarCompradores() const {
    cout << "\n=========================================" << endl;
    cout << "|           TICKET DE COMPRA            |" << endl;
    cout << "|---------------------------------------|" << endl;
    Libro::mostrarCompradores();
    cout << "|Total a pagar: $" << left << setw(23) << ticket.calcularTotal(librosComprados) << "|\n";
    cout << "|---------------------------------------|" << endl;
    cout << "| Fecha: " << left << setw(31) << fechaCompra << "|" << endl;;
    cout << "========================================="<<endl;

}

// Método para mostrar los compradores con filtro
void Ticket::mostrarCompradores(int librosComprados) const {
    Libreria::mostrarCompradores(); // Llamada al método de la clase base Libreria
    if (librosComprados >= 12 ) {
       int  total = ticket.calcularTotal(librosComprados) -ticket.calcularTotal(librosComprados)* 0.1; 
       cout<<"|SE HA APLICADO UN DESCUENTO DEL 10%    |\n|---------------------------------------|"<<endl;
        cout << "|Total a pagar con descuento: $" << left << setw(9) << total << "|\n";
        cout << "|---------------------------------------|" << endl;
    }
} 