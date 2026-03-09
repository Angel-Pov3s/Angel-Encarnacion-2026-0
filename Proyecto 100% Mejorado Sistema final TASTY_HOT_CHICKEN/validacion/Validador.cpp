#include "Validador.h"
#include "InputException.h"

#include <iostream>
#include <limits>

using namespace std;

int Validador::leer(string msg, int min, int max) {

    int v;

    while (true) {

        try {

            cout << msg;

            if (!(cin >> v))
                throw InputException("Formato no numerico.");

            if (v < min || v > max)
                throw out_of_range("Fuera de rango.");

            return v;

        }

        catch (const exception& e) {

            cout << ">>> Error: " << e.what() << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    }
}

string Validador::leer(string msg) {

    string v;

    cout << msg;

    cin.ignore();
    getline(cin, v);

    return v;
}