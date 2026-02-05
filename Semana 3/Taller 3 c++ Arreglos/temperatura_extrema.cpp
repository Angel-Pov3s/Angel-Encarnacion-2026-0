#include <iostream>
using namespace std;

int main() {

    float temperaturas[7];
    float tempMax, tempMin;
    int diaMax, diaMin;
    int contador = 0;

    for (int i = 0; i < 7; i++) {
        cout << "Ingrese la temperatura del dia " << i + 1 << ": ";
        cin >> temperaturas[i];
    }

    tempMax = temperaturas[0];
    tempMin = temperaturas[0];
    diaMax = 1;
    diaMin = 1;

    for (int i = 0; i < 7; i++) {

        if (temperaturas[i] > tempMax) {
            tempMax = temperaturas[i];
            diaMax = i + 1;
        }

        if (temperaturas[i] < tempMin) {
            tempMin = temperaturas[i];
            diaMin = i + 1;
        }

        if (temperaturas[i] > 30) {
            contador++;
        }
    }

    cout << "\nMaxima: " << tempMax << " (dia " << diaMax << ")" << endl;
    cout << "Minima: " << tempMin << " (dia " << diaMin << ")" << endl;
    cout << "Dias mayores a 30: " << contador << endl;

    return 0;
}
