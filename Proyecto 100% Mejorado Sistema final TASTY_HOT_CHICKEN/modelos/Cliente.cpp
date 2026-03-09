#include "Cliente.h"

void Cliente::setNombre(string n) {
    nombre = n;
}

string Cliente::getNombre() const {
    return nombre;
}

void Cliente::setTipoDocumento(string t) {
    tipoDocumento = t;
}

string Cliente::getTipoDocumento() const {
    return tipoDocumento;
}

void Cliente::setRuc(string r) {
    ruc = r;
}

string Cliente::getRuc() const {
    return ruc;
}