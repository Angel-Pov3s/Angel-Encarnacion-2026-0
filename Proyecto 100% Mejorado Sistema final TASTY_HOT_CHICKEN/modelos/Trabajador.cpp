#include "Trabajador.h"

void Trabajador::setId(int _id) {
    id = _id;
}

int Trabajador::getId() const {
    return id;
}

void Trabajador::setNombre(string n) {
    nombre = n;
}

string Trabajador::getNombre() const {
    return nombre;
}

void Trabajador::setRol(string r) {
    rol = r;
}

string Trabajador::getRol() const {
    return rol;
}