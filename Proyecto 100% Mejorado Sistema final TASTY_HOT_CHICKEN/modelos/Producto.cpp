#include "Producto.h"

void Producto::setNombre(string n) {
    nombre = n;
}

string Producto::getNombre() const {
    return nombre;
}

void Producto::setPrecio(double p) {
    precio = p;
}

double Producto::getPrecio() const {
    return precio;
}

void Producto::setCantidad(int c) {
    cantidad = c;
}

int Producto::getCantidad() const {
    return cantidad;
}

void Producto::setSubtotal(double s) {
    subtotal = s;
}

double Producto::getSubtotal() const {
    return subtotal;
}