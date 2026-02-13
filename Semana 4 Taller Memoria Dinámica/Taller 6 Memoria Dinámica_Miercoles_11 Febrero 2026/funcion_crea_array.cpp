#include <iostream>
using namespace std;

int* crearArreglo(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        arr[i] = 2 * (i + 1);
    return arr;
}

int main() {
    int n = 5;
    int* arr = crearArreglo(n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;
    arr = nullptr;
}
