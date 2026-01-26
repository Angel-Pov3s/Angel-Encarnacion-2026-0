#include <stdio.h>
#include <cmath>
using namespace std;

int main() {

    int lado1, lado2; 
    float base, altura, perimetro;
    float area;

    //asignando valor

    lado1 = 9;
    lado2 = 6;
    base = 8;
    altura = 6;

    //calculando area
    area =(base * altura) / 2;
    printf("area = %.f\n", area);

    //calculando perimetro

    perimetro = lado1 + base + lado2;
    printf("perimetro = %.f\n", perimetro);

    return 0;
}