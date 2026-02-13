#include <iostream>
using namespace std;

/*--------------------------------------------------
 Función: invertir
 Tipo: procedimiento (void)
 Parámetros:
    arr[] -> arreglo por referencia
    n     -> tamaño del arreglo
--------------------------------------------------*/
void invertir(int arr[], int n)
{
    int temp; // variable intermedia para intercambio

    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main()
{
    // ===== Variables de Entrada =====
    int n;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    // Restricción básica
    if (n <= 0 || n > 100)
    {
        cout << "Tamaño no válido (1 - 100)" << endl;
        return 0;
    }

    int arr[100]; // arreglo máximo

    // ===== Lectura de datos =====
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese elemento [" << i << "]: ";
        cin >> arr[i];
    }

    // ===== Llamada a la función (paso por referencia) =====
    invertir(arr, n);

    // ===== Variable de Salida =====
    cout << "\nArreglo invertido:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


#include <iostream>
using namespace std;

// ===== FUNCION (paso por referencia) =====
void duplicar(int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = arr[i] * 2;   // modifica el arreglo original
    }
}

// ===== PROGRAMA PRINCIPAL =====
int main() {
    // Variables de Entrada
    int n;

    // Variable intermedia
    int i;

    // Solicitar tamaño
    cout << "Ingrese el tamaño del arreglo (1 - 100): ";
    cin >> n;

    // Restricción
    if(n <= 0 || n > 100) {
        cout << "Tamaño inválido";
        return 0;
    }

    // Declarar arreglo
    int arr[100];

    // Leer elementos
    for(i = 0; i < n; i++) {
        cout << "Ingrese numero [" << i << "]: ";
        cin >> arr[i];
    }

    // Llamada a la funcion (PASO POR REFERENCIA)
    duplicar(arr, n);

    // Mostrar resultado
    cout << "\nArreglo duplicado:\n";
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


int* p = new int(10);

delete p;

cout << *p;  // Acá está el ERROR dangling pointer
