#include <iostream>
using namespace std;

bool validarOpcion(int opcion, int min, int max) {
    if (opcion >= min && opcion <= max) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int opcion;
    int minimo = 1;
    int maximo = 5;

    cout << "MENU PRINCIPAL" << endl;
    cout << "1. Registrar" << endl;
    cout << "2. Consultar" << endl;
    cout << "3. Modificar" << endl;
    cout << "4. Eliminar" << endl;
    cout << "5. Salir" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;

    if (validarOpcion(opcion, minimo, maximo)) {
        cout << "Opcion valida" << endl;
    } else {
        cout << "Opcion invalida. Fuera del rango permitido." << endl;
    }

    return 0;
}
