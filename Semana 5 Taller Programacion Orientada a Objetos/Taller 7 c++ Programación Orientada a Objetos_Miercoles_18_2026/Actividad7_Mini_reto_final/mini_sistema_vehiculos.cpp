#include <iostream>
#include <string>

using namespace std;

class Vehiculo { // CLASE BASE: Vehiculo
private:
    string marca;
    int velocidadMax;

public:     // Constructor
    Vehiculo(const string& marca, int velocidadMax) {
        this->marca = marca;
        setVelocidadMax(velocidadMax);
    }

    string getMarca() const { return marca; }     // Getters
    int getVelocidadMax() const { return velocidadMax; }

    void setMarca(const string& marca) {     // Setters con validación
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

    virtual void mostrarInfo() const {     // Método virtual
        cout << "Marca: " << marca << endl;
        cout << "Velocidad Maxima: " << velocidadMax << " km/h" << endl;
    }

    virtual ~Vehiculo() {}
};

class Carro : public Vehiculo { // CLASE DERIVADA: Carro
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

class Moto : public Vehiculo { // CLASE DERIVADA: Moto
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

int main() { // MAIN – PRUEBAS

    Carro carro("Toyota", 200, 4);
    Moto moto("Yamaha", 180, 600);
    cout << "===== DATOS DEL CARRO =====" << endl;
    carro.mostrarInfo();
    cout << "\n===== DATOS DE LA MOTO =====" << endl;
    moto.mostrarInfo();

    return 0;
}
