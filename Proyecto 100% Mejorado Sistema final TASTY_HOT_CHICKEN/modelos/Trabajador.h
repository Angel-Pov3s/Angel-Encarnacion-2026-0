#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <string>

using namespace std;

class Trabajador {

private:

    int id;
    string nombre;
    string rol;

public:

    void setId(int _id);
    int getId() const;

    void setNombre(string n);
    string getNombre() const;

    void setRol(string r);
    string getRol() const;
};

#endif