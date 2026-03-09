#include "Pedido.h"

void Pedido::setCantidadProductos(int c) {
    cantidadProductos = c;
}

int Pedido::getCantidadProductos() const {
    return cantidadProductos;
}

void Pedido::setTotal(double t) {
    total = t;
}

double Pedido::getTotal() const {
    return total;
}

void Pedido::setEstado(EstadoPedido e) {
    estado = e;
}

EstadoPedido Pedido::getEstado() const {
    return estado;
}

Producto& Pedido::getProducto(int index) {
    return productos[index];
}