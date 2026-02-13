#include <iostream>
#include <string>
#include <iomanip>
#include <limits> // Necesario para limpiar el buffer
#include <algorithm> // Para transformar a minúsculas

using namespace std;

// Estructura para los productos
struct Producto {
    string nombre;
    int cantidad;
    double subtotal;
};

// --- FUNCIÓN PARA VALIDAR ENTRADA NUMÉRICA ---
// Esta función evita que el programa falle si el usuario ingresa letras
int leerEntero(string mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            return valor;
        } else {
            cout << ">>> Error: Ingrese solo numeros." << endl;
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
        }
    }
}

// Función para validar la respuesta SI o NO de forma estricta
string leerRespuestaSiNo(string mensaje) {
    string respuesta;
    while (true) {
        cout << mensaje;
        cin >> respuesta;
        // Convertir respuesta a minúsculas para comparar
        for (int i = 0; i < respuesta.length(); i++) {
            respuesta[i] = tolower(respuesta[i]);
        }
        if (respuesta == "si" || respuesta == "no") {
            return respuesta;
        } else {
            cout << ">>> Error: Por favor escriba exactamente 'si' o 'no'." << endl;
        }
    }
}

// --- PILAR: PASO POR REFERENCIA ---
void mostrarQR(int metodo) {
    system("clear || cls");
    cout << "  .---------------------------." << endl;
    cout << "  |       PAGO CON " << (metodo == 3 ? "YAPE" : "PLIN") << "       |" << endl;
    cout << "  |---------------------------|" << endl;
    cout << "  |  CEL: 962559265           |" << endl;
    cout << "  |  TITULAR: TASTY CHICKEN   |" << endl;
    cout << "  |                           |" << endl;
    cout << "  |    [# # # # # # # #]      |" << endl;
    cout << "  |    [#    # #    #  ]      |" << endl;
    cout << "  |    [#  #     #  #  ]      |" << endl;
    cout << "  |    [#    # #    #  ]      |" << endl;
    cout << "  |    [# # # # # # # #]      |" << endl;
    cout << "  |      CODIGO QR SCAN       |" << endl;
    cout << "  '---------------------------'" << endl;
    cout << "  Presione Enter tras realizar el pago...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// --- PILAR: PASO POR PUNTERO ---
void imprimirTicket(Producto* lista, int n, double total, string cliente, string ruc = "") {
    system("clear || cls");
    cout << "========================================" << endl;
    if (ruc == "") cout << "             BOLETA DE VENTA" << endl;
    else cout << "            FACTURA ELECTRÓNICA\nRUC: " << ruc << endl;
    cout << "========================================" << endl;
    cout << "Cliente: " << cliente << endl;
    cout << "----------------------------------------" << endl;
    cout << "Cant. | Descripcion          | Total" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "[" << lista[i].cantidad << "] | " 
             << left << setw(20) << lista[i].nombre 
             << " | S/ " << fixed << setprecision(2) << lista[i].subtotal << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << "TOTAL A PAGAR: S/ " << total << endl;
    cout << "========================================" << endl;
}

int main() {
    // --- PILAR: MEMORIA DINÁMICA ---
    Producto* pedido = new Producto[100]; 
    int contador = 0;
    string continuar = "si";
    double totalGeneral = 0;

    cout << "======================================" << endl;
    cout << "    Bienvenidos a Tasty Hot Chicken" << endl;
    cout << "======================================" << endl;

    while (continuar == "si") {
        int cat, opc, cant;
        string nombreActual;
        double precioActual = 0;

        // Restricción de Categoría
        do {
            cat = leerEntero("\n1. Platos\n2. Bebidas\nSeleccione categoria: ");
            if (cat < 1 || cat > 2) cout << ">>> Error: Solo opciones 1 o 2." << endl;
        } while (cat < 1 || cat > 2);

        system("clear || cls");

        if (cat == 1) {
            do {
                cout << "--- PLATOS ---\n1. Brosther Pecho (S/12)\t2. B. Entre-Pierna (S/11)\t3. B. Pierna (S/10)\n4. B. Ala (S/9)\t\t5. Salchibrosther (S/16)\t6. H. Clasica (S/8)\n7. H. Mixta (S/10)\t8. H. Royal (S/12)\t\t9. H. Tasty (S/22)\n10. Alitas BBQ (S/20)\t11. A. Acevichadas (S/20)\t12. A. Crispy (S/20)\n13. A. Maracuya (S/20)\t14. A. Picantes (S/20)\t\t15. Salchipapa Cl. (S/8)\n16. Salchipapa Esp. (S/11)\t17. S. Amazonica (S/25)\t18. Choripapa Cl. (S/10)\n19. Choripapa Esp. (S/13)\nSeleccione Plato (1-19): ";
                opc = leerEntero("");
                if (opc < 1 || opc > 19) cout << ">>> Error: Plato no existe." << endl;
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
                cout << "--- BEBIDAS ---\n1. Cocona (S/2)\t2. Chicha (S/2)\t3. Gaseosa Pers. (S/4)\n4. Agua Pers. (S/2)\t5. Cafe (S/3)\t6. Jugo Fresa (S/4)\n7. Jugo Platano (S/4)\t8. Jugo Esp. (S/6)\t9. Jugo Piña (S/4)\n10. Jugo Malta (S/7)\nSeleccione Bebida (1-10): ";
                opc = leerEntero("");
                if (opc < 1 || opc > 10) cout << ">>> Error: Bebida no existe." << endl;
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

        // Restricción de Cantidad
        do {
            cant = leerEntero("Cantidad: ");
            if (cant <= 0) cout << ">>> Error: La cantidad debe ser mayor a 0." << endl;
        } while (cant <= 0);
        
        pedido[contador].nombre = nombreActual;
        pedido[contador].cantidad = cant;
        pedido[contador].subtotal = cant * precioActual;
        totalGeneral += pedido[contador].subtotal;
        contador++;

        // RESTRICCIÓN SOLICITADA: Solo acepta "si" o "no"
        continuar = leerRespuestaSiNo("¿Desea pedir algo mas? (si/no): ");
    }

    // Facturación con restricciones
    int tipoC, pago;
    string cliente, ruc = "";
    do {
        tipoC = leerEntero("\n¿Desea boleta o factura?\n1. Boleta\n2. Factura\nSeleccione: ");
    } while (tipoC != 1 && tipoC != 2);

    if (tipoC == 2) {
        bool rucValido = false;
        while (!rucValido) {
            cout << "Ingrese RUC (Exactamente 11 digitos numericos): ";
            cin >> ruc;
            if (ruc.length() == 11) {
                rucValido = true;
                for(char c : ruc) if(!isdigit(c)) rucValido = false;
            }
            if (!rucValido) cout << ">>> Error: RUC invalido." << endl;
        }
        cliente = "Empresa ABC SAC";
    } else {
        cout << "Ingrese nombres y apellidos: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, cliente);
    }

    // Método de pago con restricciones
    do {
        pago = leerEntero("\nMetodo de pago:\n1. Efectivo\n2. Tarjeta\n3. Yape\n4. Plin\nSeleccione: ");
    } while (pago < 1 || pago > 4);

    if (pago >= 3) mostrarQR(pago);

    imprimirTicket(pedido, contador, totalGeneral, cliente, ruc);

    // --- LIBERACIÓN DE MEMORIA ---
    delete[] pedido; 
    pedido = nullptr; 

    return 0;
}