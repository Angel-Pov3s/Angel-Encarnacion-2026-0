#include <stdio.h>
#include <cmath>
using namespace std;

int main() {

int diagonal_mayor, diagonal_menor;
    float area, lado;
    float perimetro;
    float resultado1, resultado2;

    //asignando valores
    diagonal_mayor = 8;
    diagonal_menor = 6;

    //calcular area:
    area = diagonal_mayor * diagonal_menor / 2;
    printf("area = %.f\n", area);

    //calcular lado:
    lado = sqrt(
        pow(diagonal_mayor / 2.0, 2) +
        pow(diagonal_menor / 2.0, 2)
    );
    printf("lado = %.f\n", lado);

    //calcular periemtro:
    perimetro = 4 * lado;
    printf("perimetro = %.f\n", perimetro);

    return 0;
}
    
