#include <iostream>
using namespace std;

int main() {
    float lado;
    float perimetro;

    cout << "Ingrese la longitud del lado del cuadrado: ";
    cin >> lado;

    perimetro = 4 * lado;

    cout << "El perimetro del cuadrado es: " << perimetro << endl;

    return 0;
}