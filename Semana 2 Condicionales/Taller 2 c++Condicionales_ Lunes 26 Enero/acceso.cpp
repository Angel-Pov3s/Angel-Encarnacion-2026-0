#include <iostream>
using namespace std;

int main() {

    int edad;

    cout << "Bienvenido a Recavarren House" << endl;
    cout << "Ingrese su edad: ";
    cin >> edad;

    if (edad >= 18) {
        cout << "Acceso permitido a Recavarren House";
    } else {
        cout << "Acceso denegado a Recavarren House";
    }

    return 0;
}
