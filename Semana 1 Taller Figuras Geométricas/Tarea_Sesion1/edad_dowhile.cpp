#include <iostream>
using namespace std;

int main() {
int edad;

do {
    cout << "Ingrese su edad: ";
    cin >> edad;
} while (edad < 0);

return 0;

}
