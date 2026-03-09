#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

class Cliente {

private:

    string nombre;
    string tipoDocumento;
    string ruc;

public:

    void setNombre(string n);
    string getNombre() const;

    void setTipoDocumento(string t);
    string getTipoDocumento() const;

    void setRuc(string r);
    string getRuc() const;
};

#endif