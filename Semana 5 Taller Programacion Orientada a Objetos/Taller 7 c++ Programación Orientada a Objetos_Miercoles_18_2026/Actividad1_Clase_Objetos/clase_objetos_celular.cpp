#include <iostream>
#include <string>
using namespace std;

class Celular {
public:
    string marca;
    string modelo;
    int bateria;

    void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Bateria: " << bateria << "%" << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {

    Celular cel1;
    cel1.marca = "Samsung";
    cel1.modelo = "S23";
    cel1.bateria = 80;

    Celular cel2;
    cel2.marca = "Apple";
    cel2.modelo = "iPhone 14";
    cel2.bateria = 95;

    cel1.mostrarInfo();
    cel2.mostrarInfo();

    return 0;
}
