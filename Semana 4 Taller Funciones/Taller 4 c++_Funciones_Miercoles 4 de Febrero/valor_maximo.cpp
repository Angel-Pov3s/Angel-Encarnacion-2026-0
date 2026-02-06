#include <iostream>
using namespace std;

int obtenerMaximo(int arr[], int n) {
    int maximo = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }

    return maximo;
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

    int mayor = obtenerMaximo(arreglo, n);

    cout << "El valor maximo del arreglo es: " << mayor << endl;

    return 0;
}
