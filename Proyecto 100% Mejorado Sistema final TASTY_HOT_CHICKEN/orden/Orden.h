#ifndef ORDEN_H
#define ORDEN_H

#include <vector>
#include <iostream>

#include "../interfaces/Iimprimible.h"

#include "../modelos/Producto.h"
#include "../modelos/Cliente.h"
#include "../modelos/Trabajador.h"

using namespace std;

enum class EstadoPedido
{
    PENDIENTE,
    EN_PREPARACION,
    ENTREGADO
};

class Orden : public IImprimible
{

private:

    vector<Producto> items;
    EstadoPedido estado;

    Cliente* cliente;
    Trabajador* atendidoPor;

public:

    Orden(Cliente* c, Trabajador* t);

    void agregarProducto(const Producto& p);

    double calcularTotal() const;

    void imprimir() override;

};

ostream& operator<<(ostream& os, const Orden& o);

#endif