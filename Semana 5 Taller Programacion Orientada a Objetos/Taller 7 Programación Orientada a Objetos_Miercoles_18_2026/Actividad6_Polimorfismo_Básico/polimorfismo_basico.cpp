#include <iostream>
#include <string>

using namespace std;

// CLASE BASE: Persona
class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(const string& nombre, int edad) {
        this->nombre = nombre;
        setEdad(edad);
    }

    // Getters
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    // Setter con validación
    void setEdad(int edad) {
        if (edad >= 0)
            this->edad = edad;
        else
            this->edad = 0;
    }

    void mostrar() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }

    //Modificar Persona:
    virtual void rol() const {
        cout << "Soy una persona" << endl;
    }

    // Destructor virtual (buena práctica en polimorfismo)
    virtual ~Persona() {}
};

// CLASE DERIVADA: Estudiante
class Estudiante : public Persona {
private:
    string carrera;

public:
    Estudiante(const string& nombre, int edad, const string& carrera)
        : Persona(nombre, edad) {
        this->carrera = carrera;
    }

    void estudiar() const {
        cout << getNombre() << " está estudiando " << carrera << endl;
    }

    //En Estudiante:
    void rol() const override {
        cout << "Soy estudiante" << endl;
    }
};

// CLASE DERIVADA: Profesor
class Profesor : public Persona {
private:
    string materia;

public:
    Profesor(const string& nombre, int edad, const string& materia)
        : Persona(nombre, edad) {
        this->materia = materia;
    }

    void ensenar() const {
        cout << getNombre() << " está enseñando " << materia << endl;
    }

    //En Profesor:
    void rol() const override {
        cout << "Soy profesor" << endl;
    }
};

// MAIN
int main() {

    //En main():
    Estudiante estudiante("Carlos", 20, "Ingeniería");
    Profesor profesor("Ana", 45, "Programación");

    // Arreglo de punteros a Persona
    Persona* personas[2];

    personas[0] = &estudiante;
    personas[1] = &profesor;

    //Recorrido del arreglo rol
    cout << "=== POLIMORFISMO EN ACCION ===" << endl;

    for (int i = 0; i < 2; i++) {
        personas[i]->rol();  // Llamada polimórfica
    }

    return 0;
}
