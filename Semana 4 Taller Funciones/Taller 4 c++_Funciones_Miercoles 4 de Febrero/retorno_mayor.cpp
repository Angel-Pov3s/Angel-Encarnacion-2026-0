#include <iostream>
using namespace std;

int obtenerMayor(int a, int b) {
    int mayor;

    if (a > b) {
        mayor = a;
    } else {
        mayor = b;
    }

    return mayor;
}

int main() {
    int num1, num2, resultado;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    resultado = obtenerMayor(num1, num2);

    cout << "El numero mayor es: " << resultado << endl;

    return 0;
}
