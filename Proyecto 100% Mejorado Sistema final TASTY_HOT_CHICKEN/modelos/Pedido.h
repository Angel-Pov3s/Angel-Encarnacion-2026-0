#ifndef PEDIDO_H
#define PEDIDO_H

#include "Producto.h"


enum class EstadoPedido
{
    PENDIENTE,
    EN_PREPARACION,
    ENTREGADO
};

class Pedido {

private:

    Producto productos[100];
    int cantidadProductos;
    double total;
    EstadoPedido estado;

public:

    void setCantidadProductos(int c);
    int getCantidadProductos() const;

    void setTotal(double t);
    double getTotal() const;

    void setEstado(EstadoPedido e);
    EstadoPedido getEstado() const;

    Producto& getProducto(int index);
};

#endif