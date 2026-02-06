#include <iostream>
using namespace std;

bool estaOrdenado(int arreglo[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        if (arreglo[i] > arreglo[i + 1]) {
            return false; // No está ordenado
        }
    }
    return true; // Está ordenado
}

int main() {
    int tam;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tam;

    int arreglo[tam];

    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    bool resultado = estaOrdenado(arreglo, tam);

    if (resultado) {
        cout << "El arreglo está ordenado de forma ascendente." << endl;
    } else {
        cout << "El arreglo NO está ordenado de forma ascendente." << endl;
    }

    return 0;
}
