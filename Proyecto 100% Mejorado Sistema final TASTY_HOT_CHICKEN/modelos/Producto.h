#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

class Producto {

private:

    string nombre;
    double precio;
    int cantidad;
    double subtotal;

public:

    void setNombre(string n);
    string getNombre() const;

    void setPrecio(double p);
    double getPrecio() const;

    void setCantidad(int c);
    int getCantidad() const;

    void setSubtotal(double s);
    double getSubtotal() const;
};

#endif