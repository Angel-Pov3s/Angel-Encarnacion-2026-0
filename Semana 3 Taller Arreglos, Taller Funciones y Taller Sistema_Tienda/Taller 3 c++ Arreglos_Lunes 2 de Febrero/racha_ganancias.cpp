#include <iostream>
using namespace std;

int main() {
    int ganancias[] = {-5, 10, 12, -3, 4, 6, 8, -2};
    int n = 8;

    int rachaActual = 0;
    int rachaMaxima = 0;

    for (int i = 0; i < n; i++) {
        if (ganancias[i] > 0) {
            rachaActual++;

            if (rachaActual > rachaMaxima) {
                rachaMaxima = rachaActual;
            }
        } else {
            rachaActual = 0;
        }
    }

    cout << "Mayor racha positiva: " 
         << rachaMaxima << " dias" << endl;

    return 0;
}
