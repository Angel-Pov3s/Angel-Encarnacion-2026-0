#include <iostream>
#include <string>

using namespace std;

// CLASE BASE: Vehiculo
class Vehiculo {
private:
    string marca;
    int velocidadMax;

public:
    // Constructor
    Vehiculo(const string& marca, int velocidadMax) {
        this->marca = marca;
        setVelocidadMax(velocidadMax);
    }

    // Getters
    string getMarca() const { return marca; }
    int getVelocidadMax() const { return velocidadMax; }

    // Setters con validación
    void setMarca(const string& marca) {
        this->marca = marca;
    }

    void setVelocidadMax(int velocidadMax) {
        if (velocidadMax > 0)
            this->velocidadMax = velocidadMax;
        else {
            cout << "Velocidad inválida. Se asigna 1 km/h por defecto." << endl;
            this->velocidadMax = 1;
        }
    }

    // Método virtual
    virtual void mostrarInfo() const {
        cout << "Marca: " << marca << endl;
        cout << "Velocidad Maxima: " << velocidadMax << " km/h" << endl;
    }

    virtual ~Vehiculo() {}
};

// CLASE DERIVADA: Carro
class Carro : public Vehiculo {
private:
    int puertas;

public:
    Carro(const string& marca, int velocidadMax, int puertas)
        : Vehiculo(marca, velocidadMax) {
        setPuertas(puertas);
    }

    int getPuertas() const { return puertas; }

    void setPuertas(int puertas) {
        if (puertas > 0)
            this->puertas = puertas;
        else {
            cout << "Número de puertas inválido. Se asigna 4 por defecto." << endl;
            this->puertas = 4;
        }
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << "Puertas: " << puertas << endl;
    }
};

// CLASE DERIVADA: Moto
class Moto : public Vehiculo {
private:
    int cilindraje;

public:
    Moto(const string& marca, int velocidadMax, int cilindraje)
        : Vehiculo(marca, velocidadMax) {
        setCilindraje(cilindraje);
    }

    int getCilindraje() const { return cilindraje; }

    void setCilindraje(int cilindraje) {
        if (cilindraje > 0)
            this->cilindraje = cilindraje;
        else {
            cout << "Cilindraje inválido. Se asigna 125cc por defecto." << endl;
            this->cilindraje = 125;
        }
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << "Cilindraje: " << cilindraje << " cc" << endl;
    }
};

// MAIN – PRUEBAS
int main() {

    Carro carro("Toyota", 200, 4);
    Moto moto("Yamaha", 180, 600);

    cout << "===== DATOS DEL CARRO =====" << endl;
    carro.mostrarInfo();

    cout << "\n===== DATOS DE LA MOTO =====" << endl;
    moto.mostrarInfo();

    return 0;
}
