#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese tamaño: ";
    cin >> n;

    int* arr = new int[n];

    int suma = 0;

    for(int i = 0; i < n; i++) {
        cout << "Valor " << i << ": ";
        cin >> arr[i];
        suma += arr[i];
    }

    cout << "\nArreglo:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    double promedio = (n > 0) ? (double)suma / n : 0;
    cout << "\nPromedio: " << promedio << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}

