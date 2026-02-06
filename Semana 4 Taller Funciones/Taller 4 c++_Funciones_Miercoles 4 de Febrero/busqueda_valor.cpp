#include <iostream>
using namespace std;

bool buscarValor(int arreglo[], int tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (arreglo[i] == valor) {
            return true; // Valor encontrado
        }
    }
    return false; // Valor no encontrado
}

int main() {
    int tam, valorBuscado;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tam;

    int arreglo[tam];

    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    cout << "Ingrese el valor a buscar: ";
    cin >> valorBuscado;

    bool resultado = buscarValor(arreglo, tam, valorBuscado);

    if (resultado) {
        cout << "El valor SI existe en el arreglo." << endl;
    } else {
        cout << "El valor NO existe en el arreglo." << endl;
    }

    return 0;
}
