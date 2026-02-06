#include <stdio.h>
#include <cmath>
using namespace std;

int main() {

    int lado1, lado2, lado3;
    float area, semi_perimetro;

    //asignar valores:

    lado1 = 3;
    lado2 = 7;
    lado3 = 5;

    //calcular semiperimetro:
    semi_perimetro = (lado1 + lado2 + lado3) / 2.0;
    printf("semi_perimetro = %.2f\n", semi_perimetro);

    //calcular area:
    area = sqrt(
        semi_perimetro *
        (semi_perimetro - lado1) *
        (semi_perimetro - lado2) *
        (semi_perimetro - lado3)
    );
    printf("area = %.4f\n", area);

    return 0;
} 