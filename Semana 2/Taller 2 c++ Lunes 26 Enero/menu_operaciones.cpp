#include <iostream>
using namespace std;

int main() {

    int opcion;

    cout << "MENU DE OPERACIONES" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Operacion seleccionada: Suma";
            break;
        case 2:
            cout << "Operacion seleccionada: Resta";
            break;
        case 3:
            cout << "Operacion seleccionada: Multiplicacion";
            break;
        case 4:
            cout << "Operacion seleccionada: Division";
            break;
        default:
            cout << "Opcion no valida";
    }

    return 0;
}
