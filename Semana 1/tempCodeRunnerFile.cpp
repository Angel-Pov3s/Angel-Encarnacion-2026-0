#include <iostream>
using namespace std;

int main() {
    float num1, num2, num3;
    float promedio;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "Ingrese el tercer numero: ";
    cin >> num3;

    promedio = (num1 + num2 + num3) / 3;

    cout << "El promedio de los tres numeros es: " << promedio << endl;

    return 0;
}