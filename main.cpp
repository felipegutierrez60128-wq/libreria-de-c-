//Felipe Gutierrez Herrera
//A01662377
//Hecho el 28/11/2024
#include <iostream>
#include <vector>
#include <string>
#include "Libro.h"
#include "Libreria.h"
#include "Ticket.h"
using namespace std;

int main()
{
    int menu = 0;
    string opcion = "";

    // Libros por género (puedes usar uno por género para controlar el stock)
    Libro lTerror(0, 1000, "Terror","");
    Libro lSuspenso(0, 1000, "Suspenso","");
    Libro lCiencia(0, 1000, "Ciencia Ficcion","");
    Libro lRomance(0, 1000, "Romance","");


    vector<Ticket> tickets;

    while (menu != -1)
    {
        cout << "\n----------------------------------------------------" << endl;
        cout << "|         Bienvenido a la tienda de libros         |\n|--------------------------------------------------|\n|                  [El milagro]                    |\n|--------------------------------------------------|\n| ¿Que tipo de libros deseas comprar?              |\n||||||||||||||||||||||||||||||||||||||||||||||||||||\n|--------------------------------------------------|\n|   *1.Libros de terror ( * ~ *)                   |\n|--------------------------------------------------|\n|   *2.Libros de suspenso (* 0 * )                 |\n|--------------------------------------------------|\n|   *3.Libros de ciencia ficcion (o~~o)            |\n|--------------------------------------------------|\n|   *4.Libros de Romance (^ v ^)                   |\n|--------------------------------------------------|\n|   * -1.salir                                     |\n|--------------------------------------------------|" << endl;
        cin >> menu;

        if (menu >= 1 && menu <= 4)
        {
            do {
                Libreria libreria;
                /* Pedir el nombre del cliente
                Usamos un objeto de la clase 
                Tienda para obtener el nombre del cliente*/
                string nombreCliente;
                cout << "\nIngrese su nombre: ";
                cin >> nombreCliente;
                libreria.setNombre(nombreCliente);
                

                int librosComprados = 0;
                cout << "¿Cuántos libros desea comprar? ";
                cin >> librosComprados;

                string genero;

                /*usamos el puntero libre para 
                apuntar al libro correspondiente según
                el género seleccionado por el usuario.
                Esto nos permite evitar la repetición de código.
                Asi mismo con este puntero podemos acceder a los 
                métodos de la clase Libro
                */
                Libro* libroPtr = nullptr; // Puntero para apuntar al libro correspondiente inicialmente a nullptr que no apunta a nada

                // Asignar el género y el puntero al libro correspondiente
                if (menu == 1) {
                     genero = "Terror"; 
                     libroPtr = &lTerror; }
                else if (menu == 2) {
                     genero = "Suspenso"; 
                     libroPtr = &lSuspenso; }
                else if (menu == 3) { 
                    genero = "Ciencia Ficcion";
                     libroPtr = &lCiencia; }
                else if (menu == 4) { 
                    genero = "Romance"; 
                    libroPtr = &lRomance; }

                // Validar stock y guarda los libros comprados
                    libroPtr->comprarLibros(librosComprados);
                    
                   
                    // Crear y guardar el ticket
                    Ticket ticket(" ",0.0,librosComprados, libroPtr->getNumeroDeLibros(), genero, libreria.getNombre());
                    //genera y guarda en el ticket la hora en la que se compro el libro
                    ticket.generarFechaCompra();

                    /*se guarda en un vector a todos los clientes para
                    que este pueda comprar n veces libros de cada tipo.
                    */
                    tickets.push_back(ticket);

                
            

                cout << "\n¿Deseas registrar otro cliente para este género? (s/n): ";
                cin >> opcion;
            } while (opcion == "s");
        }
        else if (menu == -1){break;}else{cout << "Opción no válida." << endl;break;}
    }

    // Mostrar todos los tickets generados
    cout << "\n-----------------------------------------" << endl;
    if (tickets.empty()) {
        cout << "No se han generado tickets." << endl;
        cout << "\n-----------------------------------------" << endl;
        return 0;
    }
    else{
        for (Ticket tik : tickets) {
            if (tik.getLibrosComprados() >= 12) {
                tik.mostrarCompradores(tik.getLibrosComprados());
            }
         else{
            cout << "\n----- RESUMEN DE TICKETS GENERADOS -----\n";
                tik.mostrarCompradores();
        }
        }
    }

    return 0;
}
