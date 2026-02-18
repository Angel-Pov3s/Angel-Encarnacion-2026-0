#include <iostream>
#include <string>

using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getBateria() const { return bateria; }

    void setMarca(string m) { marca = m; }
    void setModelo(string mod) { modelo = mod; }

    void setBateria(int b) {
        if (b >= 0 && b <= 100)
            bateria = b;
        else
            cout << "Error: bateria fuera de rango (0-100)" << endl;
    }

    void mostrarInfo() {
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

