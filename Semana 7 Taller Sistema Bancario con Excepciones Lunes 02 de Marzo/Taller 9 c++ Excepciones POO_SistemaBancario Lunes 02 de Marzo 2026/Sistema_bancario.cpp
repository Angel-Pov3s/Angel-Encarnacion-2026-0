#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

// ===============================
// EXCEPCIÓN PERSONALIZADA
// ===============================
class CuentaNoEncontrada : public runtime_error {
public:
    CuentaNoEncontrada(const string& mensaje)
        : runtime_error(mensaje) {}
};

// ===============================
// CLASE CUENTABANCARIA
// ===============================
class CuentaBancaria {
private:
    int numeroCuenta;
    string titular;
    double saldo;

public:
    // Constructor
    CuentaBancaria(int numero, const string& nombre, double saldoInicial = 0.0)
        : numeroCuenta(numero), titular(nombre), saldo(saldoInicial) {}

    void depositar(double monto) {
        if (monto <= 0)
            throw invalid_argument("El monto a depositar debe ser positivo.");
        saldo += monto;
    }

    void retirar(double monto) {
        if (monto <= 0)
            throw invalid_argument("El monto a retirar debe ser positivo.");

        if (monto > saldo)
            throw runtime_error("Saldo insuficiente para realizar el retiro.");

        saldo -= monto;
    }

    double consultarSaldo() const {
        return saldo;
    }

    int getNumeroCuenta() const {
        return numeroCuenta;
    }

    string getTitular() const {
        return titular;
    }
};

// ===============================
// CLASE BANCO
// ===============================
class Banco {
private:
    vector<CuentaBancaria> cuentas;

public:
    void agregarCuenta(int numero, const string& nombre) {
        cuentas.emplace_back(numero, nombre);
        cout << "Cuenta creada correctamente.\n";
    }

    CuentaBancaria& buscarCuenta(int numero) {
        for (auto& cuenta : cuentas) {
            if (cuenta.getNumeroCuenta() == numero)
                return cuenta;
        }
        throw CuentaNoEncontrada("La cuenta no existe.");
    }

    void mostrarCuentas() const {
        if (cuentas.empty()) {
            cout << "No hay cuentas registradas.\n";
            return;
        }

        for (const auto& cuenta : cuentas) {
            cout << "Cuenta: " << cuenta.getNumeroCuenta()
                 << " | Titular: " << cuenta.getTitular()
                 << " | Saldo: S/ " << cuenta.consultarSaldo() << endl;
        }
    }
};

// ===============================
// FUNCIÓN AUXILIAR PARA VALIDAR ENTEROS
// ===============================
int leerEntero() {
    int valor;
    if (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Entrada invalida. Se esperaba un numero entero.");
    }
    return valor;
}

double leerDouble() {
    double valor;
    if (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Entrada invalida. Se esperaba un numero.");
    }
    return valor;
}

// MAIN
int main() {
    Banco banco;
    int opcion;

    do {
        try {
            cout << "\n===== SISTEMA BANCARIO =====\n";
            cout << "1. Crear cuenta\n";
            cout << "2. Depositar dinero\n";
            cout << "3. Retirar dinero\n";
            cout << "4. Consultar saldo\n";
            cout << "5. Mostrar todas las cuentas\n";
            cout << "6. Salir\n";
            cout << "Seleccione una opcion: ";

            opcion = leerEntero();

            if (opcion < 1 || opcion > 6)
                throw out_of_range("Opcion de menu invalida.");

            int numero;
            double monto;
            string nombre;

            switch (opcion) {
            case 1:
                cout << "Ingrese numero de cuenta: ";
                numero = leerEntero();
                cout << "Ingrese nombre del titular: ";
                cin.ignore();
                getline(cin, nombre);
                banco.agregarCuenta(numero, nombre);
                break;

            case 2:
                cout << "Numero de cuenta: ";
                numero = leerEntero();
                cout << "Monto a depositar: ";
                monto = leerDouble();
                banco.buscarCuenta(numero).depositar(monto);
                cout << "Deposito exitoso.\n";
                break;

            case 3:
                cout << "Numero de cuenta: ";
                numero = leerEntero();
                cout << "Monto a retirar: ";
                monto = leerDouble();
                banco.buscarCuenta(numero).retirar(monto);
                cout << "Retiro exitoso.\n";
                break;

            case 4:
                cout << "Numero de cuenta: ";
                numero = leerEntero();
                cout << "Saldo actual: S/ "
                     << banco.buscarCuenta(numero).consultarSaldo() << endl;
                break;

            case 5:
                banco.mostrarCuentas();
                break;

            case 6:
                cout << "Saliendo del sistema...\n";
                break;
            }

        }
        // ORDEN CORRECTO DE CAPTURA (de más específico a más general)
        catch (const CuentaNoEncontrada& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "Error inesperado: " << e.what() << endl;
        }

    } while (opcion != 6);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Estudiante {
protected:
    string carrera;

public:
    Estudiante(string c) : carrera(c) {}
};

class Trabajador {
protected:
    double salario;

public:
    Trabajador(double s) : salario(s) {}
};

class EstudianteTrabajador : public Estudiante, public Trabajador {
public:
    EstudianteTrabajador(string c, double s)
        : Estudiante(c), Trabajador(s) {}

    void mostrar() const {
        cout << "Carrera: " << carrera << endl;
        cout << "Salario: " << salario << endl;
    }
};

int main() {

    string carrera;
    double salario;

    cout << "Ingrese la carrera: ";
    getline(cin, carrera);

    while (carrera.empty()) {
        cout << "La carrera no puede estar vacia. Ingrese nuevamente: ";
        getline(cin, carrera);
    }

    cout << "Ingrese el salario: ";
    cin >> salario;

    while (salario <= 0) {
        cout << "Salario invalido. Ingrese nuevamente: ";
        cin >> salario;
    }

    EstudianteTrabajador et(carrera, salario);

    cout << "\nDatos del Estudiante Trabajador:\n";
    et.mostrar();

    return 0;
}