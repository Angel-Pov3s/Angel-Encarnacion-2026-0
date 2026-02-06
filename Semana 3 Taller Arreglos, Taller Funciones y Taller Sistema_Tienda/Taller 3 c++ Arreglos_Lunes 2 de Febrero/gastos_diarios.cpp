#include <iostream>
using namespace std;

int main() {

    float gastos[7];
    float total = 0, promedio;
    int contador = 0;

    // Entrada de datos
    for (int i = 0; i < 7; i++) {
        cout << "Ingrese el gasto del dia " << i + 1 << ": ";
        cin >> gastos[i];
        total += gastos[i];
    }

    // Calculo del promedio
    promedio = total / 7;

    // Contar dias con gasto mayor al promedio
    for (int i = 0; i < 7; i++) {
        if (gastos[i] > promedio) {
            contador++;
        }
    }

    // Salida de resultados
    cout << "\nTotal: " << total << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Dias con gasto mayor al promedio: " << contador << endl;

    return 0;
}
