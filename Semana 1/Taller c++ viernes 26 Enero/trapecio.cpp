#include <stdio.h>
#include <cmath>
using namespace std;

int main() {

    int base_mayor, base_menor, altura;
    float area;

    //asignando valores:
    base_mayor = 10;
    base_menor = 6;
    altura = 5;

    //calculando area
    area = (base_mayor + base_menor) * altura / 2.0;
    printf("area = %.f\n", area);

    return 0;
}
