#include <iostream>
using namespace std;

float calcularPromedio(float notas[], int n) {
    float suma = 0;

    for (int i = 0; i < n; i++) {
        suma = suma + notas[i];
    }

    return suma / n;
}

int main() {
    int n;

    cout << "Ingrese la cantidad de notas: ";
    cin >> n;

    float notas[n];

    for (int i = 0; i < n; i++) {
        cout << "Ingrese la nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    float promedio = calcularPromedio(notas, n);

    cout << "El promedio de las notas es: " << promedio << endl;

    return 0;
}
