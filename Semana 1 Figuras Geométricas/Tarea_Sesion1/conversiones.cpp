#include <iostream>
using namespace std;

int main() {
    float metros;
    float centimetros;

    cout << "Ingrese la cantidad en metros: ";
    cin >> metros;

    centimetros = metros * 100;

    cout << "La cantidad en centimetros es: " << centimetros << endl;

    return 0;
}
