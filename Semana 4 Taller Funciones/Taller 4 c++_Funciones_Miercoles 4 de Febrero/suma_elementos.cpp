#include <iostream>
using namespace std;

// Función que suma los elementos de un arreglo
int sumarArreglo(int arr[], int n) {
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma = suma + arr[i];
    }

    return suma;
}

int main() {
    int n;

    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> n;

    int arreglo[n];

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    int resultado = sumarArreglo(arreglo, n);

    cout << "La suma de los elementos del arreglo es: " << resultado << endl;

    return 0;
}
