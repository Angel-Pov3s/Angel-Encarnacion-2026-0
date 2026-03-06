#include <iostream>
using namespace std;

// Clase base
class Producto {
protected:
    double precio;

public:
    Producto(double p) {
        if (p > 0)
            precio = p;
        else
            precio = 0;
    }

    double getPrecio() const {
        return precio;
    }
};

// Clase derivada (nivel 1)
class Electronico : public Producto {
protected:
    int garantia;

public:
    Electronico(double p, int g) : Producto(p) {
        if (g >= 0)
            garantia = g;
        else
            garantia = 0;
    }

    int getGarantia() const {
        return garantia;
    }
};

// Clase derivada (nivel 2)
class Laptop : public Electronico {
public:
    Laptop(double p, int g) : Electronico(p, g) {}

    double calcularPrecioFinal() const {
        const double impuesto = 0.18;
        return precio + (precio * impuesto);
    }
};

int main() {
    double precio;
    int garantia;

    cout << "Ingrese el precio de la laptop: " << precio << endl;

    cout << "Ingrese los años de garantia: " << garantia << endl;

    Laptop miLaptop(precio, garantia);

    cout << "Precio final con impuesto: " << miLaptop.calcularPrecioFinal() << endl;

    return 0;
}

#include <iostream>
#include <memory>   // Para uso de punteros inteligentes
using namespace std;

// Clase base abstracta
class Figura {
public:
    // Método virtual puro
    virtual double area() const = 0;

    // Destructor virtual (buena práctica en clases base)
    virtual ~Figura() {}
};

// Clase derivada
class Circulo : public Figura {
private:
    double radio;

public:
    // Constructor con validación
    Circulo(double r) {
        if (r > 0)
            radio = r;
        else
            radio = 0;
    }

    // Sobrescritura del método virtual
    double area() const override {
        const double PI = 3.1416;
        return PI * radio * radio;
    }
};

int main() {
    double radio;

    cout << "Ingrese el radio del circulo: ";
    cin >> radio;

    if (radio <= 0) {
        cout << "Error: El radio debe ser mayor que 0." << endl;
        return 1;
    }

    // Polimorfismo
    Figura* figura = new Circulo(radio);

    cout << "El area del circulo es: " << figura->area() << endl;

    delete figura;

    return 0;
}


#include <iostream>
using namespace std;

// Clase base
class Persona {
protected:
    string nombre;

public:
    Persona(string n) {
        if (!n.empty())
            nombre = n;
        else
            nombre = "Sin nombre";
    }

    string getNombre() const {
        return nombre;
    }
};

// Herencia virtual
class Estudiante : virtual public Persona {
protected:
    string codigoEstudiante;

public:
    Estudiante(string n, string codigo)
        : Persona(n) {
        codigoEstudiante = codigo;
    }

    string getCodigo() const {
        return codigoEstudiante;
    }
};

// Herencia virtual
class Trabajador : virtual public Persona {
protected:
    double salario;

public:
    Trabajador(string n, double s)
        : Persona(n) {
        if (s >= 0)
            salario = s;
        else
            salario = 0;
    }

    double getSalario() const {
        return salario;
    }
};

// Herencia híbrida (diamante)
class Becario : public Estudiante, public Trabajador {
public:
    Becario(string n, string codigo, double s)
        : Persona(n),   // Constructor obligatorio por herencia virtual
          Estudiante(n, codigo),
          Trabajador(n, s) {}

    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Codigo Estudiante: " << codigoEstudiante << endl;
        cout << "Salario: " << salario << endl;
    }
};

int main() {
    string nombre, codigo;
    double salario;

    cout << "Ingrese nombre: ";
    getline(cin, nombre);

    cout << "Ingrese codigo de estudiante: ";
    getline(cin, codigo);

    cout << "Ingrese salario: ";
    cin >> salario;

    if (salario < 0) {
        cout << "Error: El salario no puede ser negativo." << endl;
        return 1;
    }

    Becario becario(nombre, codigo, salario);

    cout << "\n--- Datos del Becario ---\n";
    becario.mostrarInformacion();

    return 0;
}



#include <iostream>
using namespace std;

// Clase base
class Persona {
protected:
    string nombre;

public:
    Persona(string n) {
        if (!n.empty())
            nombre = n;
        else
            nombre = "Sin nombre";
    }

    string getNombre() const {
        return nombre;
    }
};

// Herencia virtual
class Estudiante : virtual public Persona {
protected:
    string codigoEstudiante;

public:
    Estudiante(string n, string codigo)
        : Persona(n) {
        codigoEstudiante = codigo;
    }

    string getCodigo() const {
        return codigoEstudiante;
    }
};

// Herencia virtual
class Trabajador : virtual public Persona {
protected:
    double salario;

public:
    Trabajador(string n, double s)
        : Persona(n) {
        if (s >= 0)
            salario = s;
        else
            salario = 0;
    }

    double getSalario() const {
        return salario;
    }
};

// Herencia híbrida (diamante)
class Becario : public Estudiante, public Trabajador {
public:
    Becario(string n, string codigo, double s) : Persona(n),   // Constructor obligatorio por herencia virtual
          Estudiante(n, codigo),
          Trabajador(n, s) {}

    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Codigo Estudiante: " << codigoEstudiante << endl;
        cout << "Salario: " << salario << endl;
    }
};

int main() {
    string nombre, codigo;
    double salario;

    cout << "Ingrese nombre: ";
    getline(cin, nombre);

    cout << "Ingrese codigo de estudiante: ";
    getline(cin, codigo);

    cout << "Ingrese salario: ";
    cin >> salario;

    if (salario < 0) {
        cout << "Error: El salario no puede ser negativo." << endl;
        return 1;
    }

    Becario becario(nombre, codigo, salario);

    cout << "\n--- Datos del Becario ---\n";
    becario.mostrarInformacion();

    return 0;
}

#include <iostream>
using namespace std;

class Pago {
protected:
    double monto;

public:
    Pago(double m) : monto(m) {}
    virtual void procesar() const {
        cout << "Procesando pago general por $" << monto << endl;
    }
    virtual ~Pago() = default;
};

class PagoTarjeta : public Pago {
public:
    using Pago::Pago; // hereda constructor
    void procesar() const override {
        cout << "Procesando pago con tarjeta por $" << monto << endl;
    }
};

int main() {
    double monto;
    int opcion;

    cout << "Monto: ";
    cin >> monto;
    if (monto <= 0) return cout << "Monto invalido\n", 1;

    cout << "1.General  2.Tarjeta: ";
    cin >> opcion;

    Pago* pago = (opcion == 1) ? (Pago*)new Pago(monto)
                 : (opcion == 2) ? (Pago*)new PagoTarjeta(monto)
                 : nullptr;

    if (!pago) return cout << "Opcion invalida\n", 1;

    pago->procesar();
    delete pago;
}



#include <iostream>
using namespace std;

// Clase Base
class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(string n, int e) : nombre(n), edad(e) {}

    void mostrarPersona() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

// Herencia virtual para evitar duplicidad (problema del diamante)
class Estudiante : virtual public Persona {
protected:
    string carrera;

public:
    Estudiante(string n, int e, string c)
        : Persona(n, e), carrera(c) {}

    void mostrarEstudiante() {
        cout << "Carrera: " << carrera << endl;
    }
};

class Trabajador : virtual public Persona {
protected:
    double salario;

public:
    Trabajador(string n, int e, double s)
        : Persona(n, e), salario(s) {}

    void mostrarTrabajador() {
        cout << "Salario: " << salario << endl;
    }
};

// Herencia Híbrida
class Asistente : public Estudiante, public Trabajador {
private:
    double bonoAcademico;

public:
    Asistente(string n, int e, string c, double s, double b)
        : Persona(n, e),
          Estudiante(n, e, c),
          Trabajador(n, e, s),
          bonoAcademico(b) {}

    double calcularIngresoTotal() {
        return salario + bonoAcademico;
    }

    void mostrarDatos() {
        mostrarPersona();
        mostrarEstudiante();
        mostrarTrabajador();
        cout << "Bono Academico: " << bonoAcademico << endl;
        cout << "Ingreso Total: " << calcularIngresoTotal() << endl;
    }
};

int main() {
    string nombre, carrera;
    int edad;
    double salario, bono;

    cout << "Ingrese nombre: ";
    cin >> nombre;

    cout << "Ingrese edad: ";
    cin >> edad;

    cout << "Ingrese carrera: ";
    cin >> carrera;

    cout << "Ingrese salario: ";
    cin >> salario;

    cout << "Ingrese bono academico: ";
    cin >> bono;

    Asistente a(nombre, edad, carrera, salario, bono);
    cout << "\n--- DATOS DEL ASISTENTE ---\n";
    a.mostrarDatos();

    return 0;
} 