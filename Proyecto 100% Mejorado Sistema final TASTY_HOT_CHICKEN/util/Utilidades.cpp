#include "Utilidades.h"

#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int leerEnteroSeguro(const string& mensaje, int min, int max) {

    int valor;

    while (true) {

        try {

            cout << mensaje;

            if (!(cin >> valor)) {
                throw runtime_error("Debe ingresar solo numeros.");
            }

            if (valor < min || valor > max) {
                throw out_of_range("Opcion fuera del rango permitido.");
            }

            return valor;
        }

        catch (exception &e) {

            cout << ">>> Error: " << e.what() << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string leerRespuestaSiNo(const string& mensaje) {

    string respuesta;

    while (true) {

        cout << mensaje;
        cin >> respuesta;

        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::tolower);

        if (respuesta == "si" || respuesta == "no")
            return respuesta;

        cout << ">>> Error: Escriba exactamente 'si' o 'no'.\n";
    }
}