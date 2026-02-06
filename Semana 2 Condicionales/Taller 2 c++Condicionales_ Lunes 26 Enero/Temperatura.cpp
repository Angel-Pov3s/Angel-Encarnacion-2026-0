#include <iostream>
using namespace std;

int main() {

    int temperatura;

    cout << "Ingrese la temperatura: ";
    cin >> temperatura;

    if (temperatura > 30) {
        cout << "Ventilador ENCENDIDO";
    } else {
        cout << "Ventilador APAGADO";
    }

    return 0;
}
