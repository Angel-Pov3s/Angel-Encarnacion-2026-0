#include <iostream>
using namespace std;

int main() {
    string nombre;

    cout<<"Cual es tu nombre?: ";
    getline(cin, nombre); //Simplemente al ingresar su nombre, el programa lo va leer a traves de "cin"
    //Posterior a ello se va almacenar el dato en la variable "nombre"
    //Getline es una funcion que sirve para leer una linea completa de texto (Nombres y apellido)
    cout<<"Tu nombre es: "<<nombre<<endl<<"Un gusto en conocerte, "<<nombre;
    return 0;
}