#include <iostream>
using namespace std;

int main() {

    // ===== Variables de Entrada =====
    int n;          // cantidad de elementos
    int arr[100];   // arreglo
    int x;          // número a buscar

    // ===== Variables Intermedias =====
    int i;          // contador
    int pos;        // posición encontrada

    // ===== Solicitar datos =====
    cout << "Ingrese cantidad de elementos (1-100): ";
    cin >> n;

    // Restricción: validar tamaño
    while(n < 1 || n > 100){
        cout << "Error. Ingrese un valor entre 1 y 100: ";
        cin >> n;
    }

    // Llenar arreglo
    for(int i = 0; i < n; i++){
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }

    // Número a buscar
    cout << "Numero a buscar: ";
    cin >> x;

    // ===== Proceso de busqueda con WHILE =====
    i = 0;
    pos = -1; // valor por defecto si no se encuentra

    while(i < n){
        if(arr[i] == x){
            pos = i;
            break; // salir al encontrar la primera ocurrencia
        }
        i++;
    }

    // ===== Variable de Salida =====
    if(pos != -1)
        cout << "Numero encontrado en la posicion: " << pos;
    else
        cout << "Numero no encontrado (-1)";

    return 0;
}




//PROBLEMA 6


#include <iostream>
using namespace std;

int main() {

    // ===== Variables de Entrada =====
    int n;              // cantidad de elementos
    int arr[100];       // arreglo de enteros

    // ===== Variables Intermedias =====
    int i;              // contador/índice

    // ===== Solicitar cantidad (con restricción) =====
    cout << "Ingrese cantidad de elementos (1-100): ";
    cin >> n;

    // Validación de rango
    while(n < 1 || n > 100){
        cout << "Error. Ingrese un valor entre 1 y 100: ";
        cin >> n;
    }

    // ===== Cargar arreglo =====
    for(i = 0; i < n; i++){
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }

    // ===== Mostrar en orden inverso =====
    cout << "Arreglo invertido: ";

    for(i = n-1; i >= 0; i--){
        cout << arr[i] << " ";
    }

    // ===== Variable de Salida =====
    // (los elementos impresos en pantalla)

    return 0;
}

    //PROBLEMA 7

#include <iostream>
using namespace std;

int main() {

    // ===== Variables de Entrada =====
    int n;              // cantidad de elementos
    int arr[100];       // arreglo de enteros

    // ===== Variables Intermedias =====
    int i;              // contador
    int pos = 0;        // contador de positivos
    int neg = 0;        // contador de negativos
    int cer = 0;        // contador de ceros

    // ===== Solicitar cantidad de elementos =====
    cout << "Ingrese cantidad de elementos (1-100): ";
    cin >> n;

    // ===== Restricción de rango =====
    while(n < 1 || n > 100){
        cout << "Error. Ingrese un valor entre 1 y 100: ";
        cin >> n;
    }

    // ===== Lectura del arreglo =====
    for(i = 0; i < n; i++){
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }

    // ===== Proceso: clasificar números =====
    for(i = 0; i < n; i++){

        if(arr[i] > 0){
            pos++;
        }
        else if(arr[i] < 0){
            neg++;
        }
        else{
            cer++;
        }

    }

    // ===== Variables de Salida =====
    cout << "\nResultados:\n";
    cout << "Positivos: " << pos << endl;
    cout << "Negativos: " << neg << endl;
    cout << "Ceros: " << cer << endl;

    return 0;
}

//PROBLEMA 8
#include <iostream>
using namespace std;

int main() {

    // ===== Variables de Entrada =====
    int n;              // cantidad de elementos
    int arr[100];       // arreglo de números enteros

    // ===== Variables Intermedias =====
    int i, j;           // contadores de ciclos
    int temp;           // auxiliar para intercambio

    // ===== Solicitar cantidad =====
    cout << "Ingrese cantidad de elementos (1-100): ";
    cin >> n;

    // ===== Restricción =====
    while(n < 1 || n > 100){
        cout << "Error. Ingrese un valor entre 1 y 100: ";
        cin >> n;
    }

    // ===== Lectura de datos =====
    for(i = 0; i < n; i++){
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }

    // ===== Proceso: Bubble Sort (orden ascendente) =====
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-1-i; j++){

            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
    }

    // ===== Variables de Salida =====
    cout << "\nArreglo ordenado ascendente:\n";
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

//PROBLEMA 9

#include <iostream>
using namespace std;

int main() {

    // ===== Variables de Entrada =====
    int num;              // número ingresado por el usuario

    // ===== Variables Intermedias =====
    int arr[100];         // almacena números no negativos
    int n = 0;            // contador / tamaño real del arreglo

    // ===== Proceso (do-while obligatorio) =====
    do {
        cout << "Ingrese un numero (negativo para terminar): ";
        cin >> num;

        // Guardar solo si es no negativo y hay espacio
        if (num >= 0 && n < 100) {
            arr[n] = num;
            n++;
        }

        // Si el arreglo está lleno, detener
        if (n == 100) {
            cout << "Se alcanzo el limite maximo de 100 elementos.\n";
            break;
        }

    } while (num >= 0);

    // ===== Variables de Salida =====
    cout << "\nCantidad ingresada: " << n << endl;

    cout << "Numeros almacenados:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

//Problema 10

#include <iostream>
using namespace std;

int main() {

    // ===== Variables de Entrada =====
    int n;              // cantidad de elementos
    int arr[100];       // arreglo de números ingresados

    // ===== Variables Intermedias =====
    int i;              
    long long prod = 1; // acumulador del producto (inicia en 1)

    // ===== Solicitar cantidad =====
    cout << "Ingrese la cantidad de elementos (1 - 100): ";
    cin >> n;

    // ===== Restricciones =====
    if (n < 1 || n > 100) {
        cout << "Error: la cantidad debe estar entre 1 y 100.";
        return 0;
    }

    // ===== Lectura y cálculo del producto =====
    for (i = 0; i < n; i++) {
        cout << "Ingrese numero " << i + 1 << ": ";
        cin >> arr[i];

        prod = prod * arr[i];   // multiplicación acumulativa
    }

    // ===== Variable de Salida =====
    cout << "\nEl producto total es: " << prod;

    return 0;
}
 