#include <iostream>
using namespace std;

int main() {
    int asistencia[3][5] = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0}
    };

    int sumaEstudiante;
    int totalAula = 0;

    for (int i = 0; i < 3; i++) {
        sumaEstudiante = 0;

        for (int j = 0; j < 5; j++) {
            sumaEstudiante += asistencia[i][j];
            totalAula += asistencia[i][j];
        }

        cout << "Estudiante " << i + 1 
             << " - Asistencia total: " 
             << sumaEstudiante << endl;

        if (sumaEstudiante == 5) {
            cout << " -> Asistencia perfecta" << endl;
        }
    }

    cout << "\nTotal de asistencias del aula: " 
         << totalAula << endl;

    return 0;
}
