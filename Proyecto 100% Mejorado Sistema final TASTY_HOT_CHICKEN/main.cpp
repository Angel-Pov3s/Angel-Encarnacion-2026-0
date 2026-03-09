#include <iostream>

// Sistema central
#include "SistemaPedidos.h"

// Utilidades generales
#include "Utilidades.h"

// Validaciones
#include "Validador.h"

// Persistencia
#include "GestorPersistencia.h"

// Modelos
#include "Cliente.h"
#include "Producto.h"
#include "Pedido.h"

// Orden
#include "Orden.cpp"

// Ticket
#include "Ticket.h"

// Interfaces
#include "Iimprimible.h"

using namespace std;

int main()
{
    cout << "===================================" << endl;
    cout << "   SISTEMA PROFESIONAL DE PEDIDOS  " << endl;
    cout << "===================================" << endl;

    try
    {
        SistemaPedidos sistema;

        sistema.inicializarSistema();
        sistema.ejecutar();
    }
    catch (const exception& e)
    {
        cerr << "Error del sistema: " << e.what() << endl;
    }

    cout << "Sistema finalizado correctamente." << endl;

    return 0;
}