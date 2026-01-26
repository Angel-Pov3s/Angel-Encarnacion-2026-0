#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    int base, altura;
    int area, perimetro;
    float diagonal;

    //asignando valores:

    base = 8;
    altura =  6;

    //calcular area:
    area = base * altura;
    printf("area = %d\n", area);

    //calcular promedio
    perimetro = 2*(8+6);
    printf("perimetro = %d\n", perimetro);

    //calcular diagonal
    diagonal = sqrt(8*8 + (6*6));
    printf("diagonal = %.f\n", diagonal);
    
    return 0;
}