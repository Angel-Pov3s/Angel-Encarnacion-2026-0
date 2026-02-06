#include <iostream>
using namespace std;

bool esPar(int num) {
    if (num % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int numero;
    bool resultado;

    cout << "Ingrese un numero entero: ";
    cin >> numero;

    resultado = esPar(numero);

    if (resultado == true) {
        cout << "El numero es par" << endl;
    } else {
        cout << "El numero es impar" << endl;
    }

    return 0;
}
