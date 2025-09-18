#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "Libro.h"

using namespace std;
/*Esta es la clase ticket'
 >= En esta clase se genera la fecha de compra
 >= y se muestra el ticket de compra al cliente.
 >= Esta clase hereda de la clase Libro, por lo que
 >= puede acceder a sus métodos y atributos.
*/

class Ticket : public Libro {
private:
   // Atributos
    string fechaCompra;
    double totalPago;

public:
    // Constructor
    Ticket();
    Ticket(string fechaCompra, double totalPago,
         int librosComprados,int numeroDeLibros,
         string generos,string nombre);
    ~Ticket() = default;

   //getter
    string getFechaCompra() { return fechaCompra; }
    double getTotalPago() const;


    // Metodos
    double calcularTotal(int librosComprados);
    void mostrarCompradores() const override;
    void mostrarCompradores(int librosComprados) const;// sobrecarga 
    void generarFechaCompra();
};

#endif 