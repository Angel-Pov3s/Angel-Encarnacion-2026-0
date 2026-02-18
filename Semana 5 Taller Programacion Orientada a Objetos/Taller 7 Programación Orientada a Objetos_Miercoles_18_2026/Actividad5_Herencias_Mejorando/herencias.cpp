#include <iostream>
#include <string>

using namespace std;

// PARTE A – CLASE BASE
class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Persona(const string& nombre, int edad) {
        this->nombre = nombre;
        setEdad(edad); // Aplicamos validación
    }

    // Getters
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    // Setters con validación
    void setNombre(const string& nombre) {
        this->nombre = nombre;
    }

    void setEdad(int edad) {
        if (edad >= 0) {
            this->edad = edad;
        } else {
            cout << "Edad invalida. Se asigna 0 por defecto." << endl;
            this->edad = 0;
        }
    }

    void mostrar() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

// PARTE B – CLASE DERIVADA: Estudiante
class Estudiante : public Persona {
private:
    string carrera;

public:
    Estudiante(const string& nombre, int edad, const string& carrera)
        : Persona(nombre, edad) {
        this->carrera = carrera;
    }

    string getCarrera() const { return carrera; }

    void setCarrera(const string& carrera) {
        this->carrera = carrera;
    }

    void estudiar() const {
        cout << getNombre() << " Esta estudiando la carrera de "
             << carrera << endl;
    }

    void mostrar() const {
        Persona::mostrar();
        cout << "Carrera: " << carrera << endl;
    }
};

// PARTE B – CLASE DERIVADA: Profesor
class Profesor : public Persona {
private:
    string materia;

public:
    Profesor(const string& nombre, int edad, const string& materia)
        : Persona(nombre, edad) {
        this->materia = materia;
    }

    string getMateria() const { return materia; }

    void setMateria(const string& materia) {
        this->materia = materia;
    }

    void ensenar() const {
        cout << getNombre() << " Esta ensenando la materia de "
             << materia << endl;
    }

    void mostrar() const {
        Persona::mostrar();
        cout << "Materia: " << materia << endl;
    }
};

// PARTE C – PRUEBAS EN MAIN
int main() {

    // Creación de objetos
    Estudiante estudiante("Carlos", 20, "Ingenieria de Sistemas");
    Profesor profesor("Ana", 45, "Programacion");

    cout << "===== DATOS DEL ESTUDIANTE =====" << endl;
    estudiante.mostrar();
    estudiante.estudiar();

    cout << "\n===== DATOS DEL PROFESOR =====" << endl;
    profesor.mostrar();
    profesor.ensenar();

    return 0;
}
