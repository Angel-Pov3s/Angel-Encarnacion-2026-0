#ifndef ORDEN_H
#define ORDEN_H

#include <iostream>
#include <vector>

#include "../modelos/Cliente.h"
#include "../modelos/Producto.h"
#include "../modelos/Trabajador.h"

using namespace std;

enum class EstadoPedido
{
    PENDIENTE,
    EN_PREPARACION,
    ENTREGADO
};

class Orden {

private:

    Cliente* cliente;
    Trabajador* atendidoPor;
    vector<Producto> items;
    EstadoPedido estado;

public:

    Orden(Cliente* c, Trabajador* t);

    void agregarProducto(const Producto& p);

    double calcularTotal() const;

    void imprimir();

};

ostream& operator<<(ostream& os, const Orden& o);

#endif