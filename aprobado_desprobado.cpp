#include <iostream>
using namespace std;

int main() {
    int n_estudiantes;
    float nota;

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n_estudiantes;

    for (int i = 1; i <= n_estudiantes; i++) {  //El "int i = 1" es prácticamente la inicialización, ya que comienza desde 1 estudiante
        // El "i<=n_estudidantes es la primera condición de bucle, si cumple continua, este repite las n veces posible"
        // El i++ se refiere a que el valor de "i" es de 1 en 1, avanza de estudiante en estudiante
        cout << "\nIngrese la nota del estudiante " << i << ": ";
        cin >> nota;

        if (nota >= 11 && nota <= 20) { //Priera condición -- Si es verdadero, ejecuta y termina
            cout << "Estudiante " << i << ": Aprobado" << endl; 
        } 
        else if (nota >= 0 && nota <= 10) { //Segunda condición, Si es veraddero, ejecuta y termina
            cout << "Estudiante " << i << ": Desaprobado" << endl; 
        } 
        else {  //Si todas son falsas -- Al final se ejecuta el "else"
            cout << "Nota invalida. Debe estar entre 0 y 20." << endl; 
        }
    }

    return 0;
}