#include <iostream>
using namespace std;

long long calcularFactorial(int num) {
    long long factorial = 1;

    for (int i = 1; i <= num; i++) {
        factorial = factorial * i;
    }

    return factorial;
}

int main() {
    int numero;

    cout << "Ingrese un numero entero no negativo: ";
    cin >> numero;

    if (numero < 0) {
        cout << "Error: No se puede calcular el factorial de un numero negativo." << endl;
    } else {
        long long resultado = calcularFactorial(numero);
        cout << "El factorial de " << numero << " es: " << resultado << endl;
    }

    return 0;
}
