#include <vector>
#include <iostream>
using namespace std;

int main() {
    int f, c;
    cin >> f >> c;

    vector<vector<int>> matriz(f, vector<int>(c));

    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++)
            cin >> matriz[i][j];

    for(int i = 0; i < f; i++) {
        int sumaFila = 0;
        for(int j = 0; j < c; j++) {
            cout << matriz[i][j] << " ";
            sumaFila += matriz[i][j];
        }
        cout << " | Suma: " << sumaFila << endl;
    }
}
