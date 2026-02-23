#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

// ===================== ESTRUCTURAS =====================

struct Producto {
    string nombre;
    double precio;
    int cantidad;
    double subtotal;
};

struct Cliente {
    string nombre;
    string tipoDocumento;
    string ruc;
};

struct Trabajador {
    int id;
    string nombre;
    string rol; // Cajero o Mesero
};

// ===================== VALIDACIONES =====================

int leerEntero(string mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) return valor;
        cout << ">>> Error: Ingrese solo numeros.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string leerRespuestaSiNo(string mensaje) {
    string respuesta;
    while (true) {
        cout << mensaje;
        cin >> respuesta;
        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::tolower);
        if (respuesta == "si" || respuesta == "no") return respuesta;
        cout << ">>> Error: Escriba exactamente 'si' o 'no'.\n";
    }
}

// ===================== ARCHIVOS TXT =====================

void guardarClienteTXT(Cliente c) {
    ofstream archivo("clientes.txt", ios::app);
    archivo << c.nombre << " | "
            << c.tipoDocumento << " | "
            << c.ruc << endl;
    archivo.close();
}

void guardarTrabajadorTXT(Trabajador t) {
    ofstream archivo("trabajadores.txt", ios::app);
    archivo << t.id << " | "
            << t.nombre << " | "
            << t.rol << endl;
    archivo.close();
}

bool buscarTrabajadorPorID(int idBuscado, Trabajador &trabajadorEncontrado) {

    ifstream archivo("trabajadores.txt");
    if (!archivo.is_open()) return false;

    string linea;

    while (getline(archivo, linea)) {

        size_t pos1 = linea.find("|");
        size_t pos2 = linea.rfind("|");

        if (pos1 == string::npos || pos2 == string::npos) continue;

        string idStr = linea.substr(0, pos1);
        string nombre = linea.substr(pos1 + 2, pos2 - pos1 - 3);
        string rol = linea.substr(pos2 + 2);

        int id = stoi(idStr);

        if (id == idBuscado) {
            trabajadorEncontrado.id = id;
            trabajadorEncontrado.nombre = nombre;
            trabajadorEncontrado.rol = rol;
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}
void guardarPedidoTXT(Cliente c, Trabajador t, Producto* lista, int n, double total) {
    ofstream archivo("pedidos.txt", ios::app);
    archivo << "========================================\n";
    archivo << "Cliente: " << c.nombre << endl;
    archivo << "Documento: " << c.tipoDocumento << endl;
    archivo << "Atendido por: " << t.nombre << " (" << t.rol << ")\n";
    archivo << "----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        archivo << lista[i].nombre << " | "
                << lista[i].cantidad << " | "
                << lista[i].subtotal << endl;
    }
    archivo << "TOTAL: S/ " << total << endl;
    archivo << "========================================\n\n";
    archivo.close();
}

// ===================== REGISTRO TRABAJADOR =====================

Trabajador loginTrabajador() {

    Trabajador t;

    cout << "\n===== LOGIN TRABAJADOR =====\n";
    t.id = leerEntero("Ingrese su ID: ");
    cin.ignore();

    if (buscarTrabajadorPorID(t.id, t)) {

        cout << "\nBienvenido nuevamente " << t.nombre << endl;
        cout << "Rol: " << t.rol << endl;

    } else {

        cout << "\nID no encontrado. Registrando nuevo trabajador...\n";

        cout << "Nombre: ";
        getline(cin, t.nombre);

        int rol = leerEntero("1. Cajero\n2. Mesero\nSeleccione: ");
        t.rol = (rol == 1) ? "Cajero" : "Mesero";

        guardarTrabajadorTXT(t);

        cout << "\nRegistro exitoso.\n";
    }

    return t;
}


// ===================== REGISTRO CLIENTE =====================

Cliente registrarCliente() {
    Cliente c;
    cout << "\n===== DATOS inicial del cliente =====\n";
    int tipo = leerEntero("1. Boleta\n2. Factura\nSeleccione: ");

    cin.ignore();
    cout << "Nombre del cliente: ";
    getline(cin, c.nombre);

    if (tipo == 2) {
        c.tipoDocumento = "Factura";
        bool valido = false;
        while (!valido) {
            cout << "Ingrese RUC (11 digitos): ";
            cin >> c.ruc;
            valido = (c.ruc.length() == 11 &&
                      all_of(c.ruc.begin(), c.ruc.end(), ::isdigit));
            if (!valido) cout << ">>> RUC invalido.\n";
        }
    } else {
        c.tipoDocumento = "Boleta";
        c.ruc = "-";
    }

    guardarClienteTXT(c);
    return c;
}

// ===================== QR =====================

void mostrarQR(int metodo) {
    system("cls"); // En Linux usar: system("clear");

    cout << "\n";
    cout << "=========================================\n";
    cout << "              PAGO DIGITAL               \n";
    cout << "=========================================\n";

    if (metodo == 3)
        cout << "          PAGO CON YAPE\n";
    else
        cout << "          PAGO CON PLIN\n";

    cout << "-----------------------------------------\n";
    cout << "  CEL: 962559265\n";
    cout << "  TITULAR: TASTY CHICKEN\n";
    cout << "-----------------------------------------\n\n";

    cout << "        [# # # # # # # #]\n";
    cout << "        [#   #   #   #   ]\n";
    cout << "        [# #   # #   # # ]\n";
    cout << "        [#   #   #   #   ]\n";
    cout << "        [# # # # # # # #]\n";
    cout << "\n";
    cout << "            CODIGO QR SCAN\n";
    cout << "-----------------------------------------\n";
    cout << "Presione ENTER tras realizar el pago...";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void procesarPago() {
    int metodo;

    cout << "\nSeleccione metodo de pago:\n";
    cout << "1. Efectivo\n";
    cout << "2. Tarjeta\n";
    cout << "3. Yape\n";
    cout << "4. Plin\n";
    cout << "Opcion: ";
    cin >> metodo;

    switch (metodo) {
        case 1:
            cout << "Pago en efectivo registrado.\n";
            break;

        case 2:
            cout << "Pago con tarjeta procesado.\n";
            break;

        case 3:
        case 4:
            mostrarQR(metodo);
            break;

        default:
            cout << "Metodo invalido.\n";
    }
}
// ===================== TICKET =====================

void imprimirTicket(Producto* lista, int n, double total, Cliente c, Trabajador t) {
    system("cls || clear");

    cout << "========================================\n";
    cout << "         TASTY HOT CHICKEN\n";
    cout << "========================================\n";
    cout << "Cliente: " << c.nombre << endl;
    cout << "Documento: " << c.tipoDocumento << endl;
    cout << "Atendido por: " << t.nombre << " (" << t.rol << ")\n";
    cout << "----------------------------------------\n";
    cout << "Cant | Producto                | Total\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << setw(4) << lista[i].cantidad << " | "
             << left << setw(22) << lista[i].nombre
             << " | S/ " << fixed << setprecision(2)
             << lista[i].subtotal << endl;
    }

    cout << "----------------------------------------\n";
    cout << "TOTAL: S/ " << total << endl;
    cout << "========================================\n";
}

// ===================== PROGRAMA PRINCIPAL =====================

int main() {

    Trabajador trabajador = loginTrabajador();
    Cliente cliente = registrarCliente();

    Producto* pedido = new Producto[100];
    int contador = 0;
    double totalGeneral = 0;
    string continuar = "si";

    cout << "\n===== BIENVENIDO A TASTY HOT CHICKEN =====\n";

    while (continuar == "si") {

        int cat, opc, cant;
        string nombreActual;
        double precioActual = 0;

        do {
            cat = leerEntero("\n1. Platos\n2. Bebidas\nSeleccione categoria: ");
        } while (cat < 1 || cat > 2);

        if (cat == 1) {

            do {
                cout << "\n--- PLATOS ---\n"
                     << "1. Brosther Pecho (S/12)\n"
                     << "2. B. Entre-Pierna (S/11)\n"
                     << "3. B. Pierna (S/10)\n"
                     << "4. B. Ala (S/9)\n"
                     << "5. Salchibrosther (S/16)\n"
                     << "6. H. Clasica (S/8)\n"
                     << "7. H. Mixta (S/10)\n"
                     << "8. H. Royal (S/12)\n"
                     << "9. H. Tasty (S/22)\n"
                     << "10. Alitas BBQ (S/20)\n"
                     << "11. A. Acevichadas (S/20)\n"
                     << "12. A. Crispy (S/20)\n"
                     << "13. A. Maracuya (S/20)\n"
                     << "14. A. Picantes (S/20)\n"
                     << "15. Salchipapa Cl. (S/8)\n"
                     << "16. Salchipapa Esp. (S/11)\n"
                     << "17. S. Amazonica (S/25)\n"
                     << "18. Choripapa Cl. (S/10)\n"
                     << "19. Choripapa Esp. (S/13)\n";
                opc = leerEntero("Seleccione: ");
            } while (opc < 1 || opc > 19);

            switch(opc) {
                case 1: nombreActual="Brosther Pecho"; precioActual=12; break;
                case 2: nombreActual="Brosther E-Pierna"; precioActual=11; break;
                case 3: nombreActual="Brosther Pierna"; precioActual=10; break;
                case 4: nombreActual="Brosther Ala"; precioActual=9; break;
                case 5: nombreActual="Salchibrosther"; precioActual=16; break;
                case 6: nombreActual="H. Clasica"; precioActual=8; break;
                case 7: nombreActual="H. Mixta"; precioActual=10; break;
                case 8: nombreActual="H. Royal"; precioActual=12; break;
                case 9: nombreActual="H. Tasty"; precioActual=22; break;
                case 10: nombreActual="Alitas BBQ"; precioActual=20; break;
                case 11: nombreActual="Alitas Acevichadas"; precioActual=20; break;
                case 12: nombreActual="Alitas Crispy"; precioActual=20; break;
                case 13: nombreActual="Alitas Maracuya"; precioActual=20; break;
                case 14: nombreActual="Alitas Picantes"; precioActual=20; break;
                case 15: nombreActual="Salchipapa Cl."; precioActual=8; break;
                case 16: nombreActual="Salchipapa Esp."; precioActual=11; break;
                case 17: nombreActual="Salchipapa Amaz."; precioActual=25; break;
                case 18: nombreActual="Choripapa Cl."; precioActual=10; break;
                case 19: nombreActual="Choripapa Esp."; precioActual=13; break;
            }

        } else {

            do {
                cout << "\n--- BEBIDAS ---\n"
                     << "1. Cocona (S/2)\n"
                     << "2. Chicha (S/2)\n"
                     << "3. Gaseosa Pers. (S/4)\n"
                     << "4. Agua Pers. (S/2)\n"
                     << "5. Cafe (S/3)\n"
                     << "6. Jugo Fresa (S/4)\n"
                     << "7. Jugo Platano (S/4)\n"
                     << "8. Jugo Esp. (S/6)\n"
                     << "9. Jugo Piña (S/4)\n"
                     << "10. Jugo Malta (S/7)\n";
                opc = leerEntero("Seleccione: ");
            } while (opc < 1 || opc > 10);

            switch(opc) {
                case 1: nombreActual="Bebida Cocona"; precioActual=2; break;
                case 2: nombreActual="Chicha Morada"; precioActual=2; break;
                case 3: nombreActual="Gaseosa Pers."; precioActual=4; break;
                case 4: nombreActual="Agua Personal"; precioActual=2; break;
                case 5: nombreActual="Cafe"; precioActual=3; break;
                case 6: nombreActual="Jugo Fresa"; precioActual=4; break;
                case 7: nombreActual="Jugo Platano"; precioActual=4; break;
                case 8: nombreActual="Jugo Especial"; precioActual=6; break;
                case 9: nombreActual="Jugo Piña"; precioActual=4; break;
                case 10: nombreActual="Jugo Malta"; precioActual=7; break;
            }
        }

        cant = leerEntero("Cantidad: ");

        pedido[contador].nombre = nombreActual;
        pedido[contador].precio = precioActual;
        pedido[contador].cantidad = cant;
        pedido[contador].subtotal = precioActual * cant;

        totalGeneral += pedido[contador].subtotal;
        contador++;

        continuar = leerRespuestaSiNo("¿Desea pedir algo mas? (si/no): ");
    }

    int pago = leerEntero("\nMetodo de pago:\n1. Efectivo\n2. Tarjeta\n3. Yape\n4. Plin\nSeleccione: ");
    if (pago >= 3) mostrarQR(pago);

    imprimirTicket(pedido, contador, totalGeneral, cliente, trabajador);
    guardarPedidoTXT(cliente, trabajador, pedido, contador, totalGeneral);

    delete[] pedido;
    return 0;
}