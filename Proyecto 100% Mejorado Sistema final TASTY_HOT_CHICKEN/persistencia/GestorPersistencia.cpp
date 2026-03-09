#include "GestorPersistencia.h"

#include <fstream>
#include <iostream>

#include "../orden/Orden.h"

using namespace std;

void GestorPersistencia::guardarTicket(const Orden& o, const string& rutaArchivo) {

    ofstream archivo(rutaArchivo, ios::app);

    if (archivo.is_open()) {

        // Usa la sobrecarga del operador << definida para Orden
        archivo << o;
        archivo << "\n\n";

        archivo.close();

        cout << ">>> Pedido guardado en archivo.\n";

    } else {

        cerr << ">>> Error: No se pudo abrir el archivo de pedidos.\n";
    }
}