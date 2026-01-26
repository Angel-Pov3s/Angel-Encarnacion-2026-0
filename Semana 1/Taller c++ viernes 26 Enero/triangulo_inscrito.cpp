#include <stdio.h>
#include <cmath>
using namespace std;

int main() {

    int lado1, lado2, lado3, radio;
    float area;

    //asignar valores:

    lado1 = 9;
    lado2 = 8;
    lado3 = 7;
    radio = 6;

    //calcular area:
    area = (lado1 * lado2 * lado3) / (4 * radio);
    printf("area = %.f\n", area);

    return 0;
}
