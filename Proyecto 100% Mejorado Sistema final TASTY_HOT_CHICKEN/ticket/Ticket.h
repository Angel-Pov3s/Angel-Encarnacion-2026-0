#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <iomanip>

#include "../modelos/Producto.h"
#include "../interfaces/IImprimible.h"

using namespace std;

class Ticket : public IImprimible {

private:

    Producto* lista;
    int n;
    double total;

public:

    Ticket(Producto* l, int cantidad, double t);

    void imprimir() override;

};

#endif