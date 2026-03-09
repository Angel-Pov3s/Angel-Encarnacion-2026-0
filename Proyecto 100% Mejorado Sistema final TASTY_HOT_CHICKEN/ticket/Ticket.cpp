#include "Ticket.h"

Ticket::Ticket(Producto* l, int cantidad, double t) {

    lista = l;
    n = cantidad;
    total = t;
}

void Ticket::imprimir() {

    cout << "==============================\n";
    cout << "        TICKET DE VENTA\n";
    cout << "==============================\n";

    for (int i = 0; i < n; i++) {

        cout << lista[i].getNombre()
             << " x" << lista[i].getCantidad()
             << " = S/ " << lista[i].getSubtotal()
             << endl;
    }

    cout << "------------------------------\n";
    cout << "TOTAL: S/ " << total << endl;
}