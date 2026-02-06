#include <iostream>
using namespace std;

int obtenerMinimo(int arr[], int n_elemento) {
    int minimo = arr[0];

    for (int i = 1; i < n_elemento; i++) {
        if (arr[i] < minimo) {
            minimo = arr[i];
        }
    }

    return minimo;
}

int main() {
    int n_elemento;

    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> n_elemento;

    int arreglo[n_elemento];

    for (int i = 0; i < n_elemento; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    int menor = obtenerMinimo(arreglo, n_elemento);

    cout << "El valor minimo del arreglo es: " << menor << endl;

    return 0;
}
