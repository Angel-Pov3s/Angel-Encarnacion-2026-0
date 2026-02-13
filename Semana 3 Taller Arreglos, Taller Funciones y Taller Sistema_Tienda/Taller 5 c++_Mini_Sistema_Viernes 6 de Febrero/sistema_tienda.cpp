#include <iostream>
#include <string>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    float precio;
    int stock;
};

int main() {
    const int MAX = 5;
    Producto productos[MAX];
    int contador = 0;
    int opcion;

    do {
        cout << "\n===== MENU TIENDA =====\n";
        cout << "1. Registrar productos\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto por codigo\n";
        cout << "4. Buscar producto por nombre\n";
        cout << "5. Mostrar producto con mayor stock\n";
        cout << "6. Mostrar producto mas caro\n";
        cout << "7. Calcular valor total del inventario\n";
        cout << "8. Salir\n";
        cout << "9. Ordenar por precio (Mayor a menor)\n";
        cout << "10. Ordenar por nombre (A-Z)\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            if (contador >= MAX) {
                cout << "No se pueden registrar mas productos.\n";
            } else {
                cout << "Codigo: ";
                cin >> productos[contador].codigo;

                cout << "Nombre: ";
                cin.ignore();
                getline(cin, productos[contador].nombre);

                do {
                    cout << "Precio: ";
                    cin >> productos[contador].precio;
                } while (productos[contador].precio <= 0);

                do {
                    cout << "Stock: ";
                    cin >> productos[contador].stock;
                } while (productos[contador].stock < 0);

                contador++;
                cout << "Producto registrado correctamente.\n";
            }
            break;

        case 2:
            if (contador == 0) {
                cout << "No hay productos registrados.\n";
            } else {  
                for (int i = 0; i < contador; i++) {
                    cout << "\nProducto " << i + 1 << endl;
                    cout << "Codigo: " << productos[i].codigo << endl;
                    cout << "Nombre: " << productos[i].nombre << endl;
                    cout << "Precio: " << productos[i].precio << endl;
                    cout << "Stock: " << productos[i].stock << endl;
                }
            }
            break;

        case 3: {
            int codigo;
            bool encontrado = false;
            cout << "Ingrese codigo a buscar: ";
            cin >> codigo;

            for (int i = 0; i < contador; i++) {
                if (productos[i].codigo == codigo) {
                    cout << "Producto encontrado:\n";
                    cout << productos[i].nombre << " - Precio: " 
                         << productos[i].precio << " - Stock: " 
                         << productos[i].stock << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "No encontrado.\n";
            break;
        }

        case 4: {
            string nombre;
            bool encontrado = false;
            cout << "Ingrese nombre a buscar: ";
            cin.ignore();
            getline(cin, nombre);

            for (int i = 0; i < contador; i++) {
                if (productos[i].nombre == nombre) {
                    cout << "Producto encontrado:\n";
                    cout << "Codigo: " << productos[i].codigo << endl;
                    cout << "Precio: " << productos[i].precio << endl;
                    cout << "Stock: " << productos[i].stock << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "No encontrado.\n";
            break;
        }

        case 5: {
            int mayor = 0;
            for (int i = 1; i < contador; i++) {
                if (productos[i].stock > productos[mayor].stock)
                    mayor = i;
            }
            cout << "Producto con mayor stock: "
                 << productos[mayor].nombre << endl;
            break;
        }

        case 6: {
            int caro = 0;
            for (int i = 1; i < contador; i++) {
                if (productos[i].precio > productos[caro].precio)
                    caro = i;
            }
            cout << "Producto mas caro: "
                 << productos[caro].nombre << endl;
            break;
        }

        case 7: {
            float total = 0;
            for (int i = 0; i < contador; i++) {
                total += productos[i].precio * productos[i].stock;
            }
            cout << "Valor total del inventario: " << total << endl;
            break;
        }

        case 9:
            for (int i = 0; i < contador - 1; i++) {
                for (int j = 0; j < contador - 1; j++) {
                    if (productos[j].precio < productos[j + 1].precio) {
                         Producto temp = productos[j];
                        productos[j] = productos[j + 1];
                        productos[j + 1] = temp;
                    }
                }
            }
            cout << "Productos ordenados por precio.\n";
            break;

        case 10:
            for (int i = 0; i < contador - 1; i++) {
                for (int j = 0; j < contador - 1; j++) {
                    if (productos[j].nombre > productos[j + 1].nombre) {
                        Producto temp = productos[j];
                        productos[j] = productos[j + 1];
                        productos[j + 1] = temp;
                    }
                }
            }
            cout << "Productos ordenados por nombre.\n";
            break;

        case 8:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 8);

    return 0;
}
