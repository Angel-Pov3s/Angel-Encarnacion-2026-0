#include <iostream>
#include <string>

using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    // Getters
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getBateria() const { return bateria; }

    // Setters usando mismo nombre y this->
    void setMarca(string marca) {
        this->marca = marca;
    }

    void setModelo(string modelo) {
        this->modelo = modelo;
    }

    void setBateria(int bateria) {
        if (bateria >= 0 && bateria <= 100) {
            this->bateria = bateria;
        } else {
            cout << "Error: bateria fuera de rango (0-100)" << endl;
        }
    }

    void mostrarInfo() const {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Bateria: " << bateria << "%" << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    Celular cel;

    cel.setMarca("Samsung");
    cel.setModelo("S23");
    cel.setBateria(85);

    cel.mostrarInfo();

    return 0;
}
