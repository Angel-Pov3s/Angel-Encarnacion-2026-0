#include <stdio.h>
#include <cmath>
using namespace std;

int main() {


    int lado1, lado2, lado3, radio;
    float area, semi_perimetro;

    //asignar valores:

    lado1 = 9;
    lado2 = 12;
    lado3 = 15;
    radio = 6;

    //Calcular semiperimetro:
    semi_perimetro = (lado1 + lado2 + lado3) / 2;
    printf("semi_perimetro = %.f\n", semi_perimetro);

    //Calcular area:
    area = radio * semi_perimetro;
    printf("area = %.f\n", area);

    return 0;
}