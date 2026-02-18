#include <iostream>
#include <string>

using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    // Constructor por defecto
    Celular() {
        marca = "Desconocida";
        modelo = "Generico";
        bateria = 100;
    }

    // Constructor con 2 parámetros
    Celular(string marca, string modelo) {
        this->marca = marca;
        this->modelo = modelo;
        this->bateria = 100;
    }

    // Constructor con 3 parámetros
    Celular(string marca, string modelo, int bateria) {
        this->marca = marca;
        this->modelo = modelo;

        if (bateria >= 0 && bateria <= 100)
            this->bateria = bateria;
        else
            this->bateria = 100;
    }

    void mostrarInfo() {
        cout << marca << " - " << modelo << " - "
             << bateria << "%" << endl;
    }
};

int main() {

    Celular c1;
    Celular c2("Samsung", "S23");
    Celular c3("Apple", "iPhone 14", 85);

    c1.mostrarInfo();
    c2.mostrarInfo();
    c3.mostrarInfo();

    return 0;
}
