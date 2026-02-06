#include <stdio.h>
#include <cmath>

int main() {
    int lado, area;
    int perimetro;
    float diagonal;

    // Asignar valor al lado
    lado = 6;

    // Calcular área
    area = lado * lado;
    printf("Area = %d\n", area);

    // Calcular perímetro
    perimetro = 4 * lado;
    printf("Perimetro = %d\n", perimetro);

    //calcular la diagonal
    diagonal = lado * sqrtf(2);
    printf("La raiz cuadrada de la diagonal es: %.4f\n", diagonal);

    return 0;
}
