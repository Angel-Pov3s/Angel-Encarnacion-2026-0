#ifndef GESTORPERSISTENCIA_H
#define GESTORPERSISTENCIA_H

#include <string>

class Orden;  // Forward declaration

class GestorPersistencia {

public:

    // Guarda el ticket de una orden en el archivo de pedidos
    static void guardarTicket(const Orden& o, const std::string& rutaArchivo = "pedidos.txt");

};

#endif