#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <limits>
#include <map>
#include <cctype>

using namespace std;

/*================================================
EXCEPCIONES PERSONALIZADAS
================================================*/

class EntidadNoEncontrada: public runtime_error{
public:
    EntidadNoEncontrada(const string& m):runtime_error(m){}
};

class NumeroCelularInvalido : public runtime_error{
public:
    NumeroCelularInvalido(const string& msg):runtime_error(msg){}
};

/*================================================
FUNCIONES DE ENTRADA ROBUSTA
================================================*/

string leerTexto(const string& msg){
    string input;

    while(true){
        cout << msg;
        getline(cin,input);

        if(!input.empty())
            return input;

        cout<<"Error: el campo no puede estar vacio\n";
    }
}

int leerEntero(const string& msg,int min,int max){

    string input;

    while(true){

        cout<<msg;
        getline(cin,input);

        try{

            int valor = stoi(input);

            if(valor<min || valor>max)
                throw out_of_range("fuera de rango");

            return valor;

        }
        catch(...){
            cout<<"Error: ingrese numero valido ("<<min<<"-"<<max<<")\n";
        }
    }
}

double leerDouble(const string& msg,double min){

    string input;

    while(true){

        cout<<msg;
        getline(cin,input);

        try{

            double v = stod(input);

            if(v<=min)
                throw invalid_argument("valor invalido");

            return v;
        }
        catch(...){
            cout<<"Error: numero invalido\n";
        }
    }
}

string leerCelular() {

    string numero;

    while (true) {

        try {

            cout << "Numero celular: ";
            getline(cin, numero);

            if (numero.empty())
                throw NumeroCelularInvalido(
                    "NO PERMITIDO, INGRESE DE NUEVO SU NUMERO CELULAR (1 HASTA 9 CIFRAS)"
                );

            if (numero.length() > 9)
                throw NumeroCelularInvalido(
                    "NO PERMITIDO, INGRESE DE NUEVO SU NUMERO CELULAR (1 HASTA 9 CIFRAS)"
                );

            for (char c : numero)
                if (!isdigit(c))
                    throw NumeroCelularInvalido(
                        "NO PERMITIDO, INGRESE DE NUEVO SU NUMERO CELULAR (1 HASTA 9 CIFRAS)"
                    );

            return numero;
        }

        catch (NumeroCelularInvalido& e) {
            cout << e.what() << endl;
        }
    }
}

/*================================================
CLASE PERSONA
================================================*/

class Persona{

protected:

    string nombre;

public:

    Persona(string n):nombre(n){}

    virtual void mostrar()const{
        cout<<"Nombre: "<<nombre<<endl;
    }

    string getNombre()const{
        return nombre;
    }

    virtual ~Persona(){}
};

/*================================================
ENTRADA HISTORIA
================================================*/

class EntradaHistoria{

    string fecha;
    string nota;

public:

    EntradaHistoria(string f,string n):fecha(f),nota(n){}

    void mostrar()const{

        cout<<fecha<<" -> "<<nota<<endl;
    }
};

/*================================================
HISTORIA CLINICA
================================================*/

class HistoriaClinica{

    vector<EntradaHistoria> entradas;

public:

    void agregarEntrada(string fecha,string nota){

        entradas.emplace_back(fecha,nota);
    }

    void mostrar(){

        for(auto &e:entradas)
            e.mostrar();
    }
};

/*================================================
PACIENTE
(COMPOSICION)
================================================*/

class Paciente: public Persona{

    string dni;
    int edad;
    string telefono;

    unique_ptr<HistoriaClinica> historia;

public:

    Paciente(string d,string n,int e,string t)
        :Persona(n),dni(d),edad(e),telefono(t){

        if(dni.size()!=8)
            throw invalid_argument("DNI invalido");

        historia = make_unique<HistoriaClinica>();
    }

    string getDni()const{
        return dni;
    }

    HistoriaClinica* getHistoria(){
        return historia.get();
    }

    void mostrar()const override{

        cout<<"Paciente: "<<nombre
            <<" DNI: "<<dni
            <<" Edad: "<<edad<<endl;
    }
};

/*================================================
DOCTOR
================================================*/

class Doctor: public Persona{

    string codigo;
    string especialidad;
    double tarifa;

public:

    Doctor(string c,string n,string e,double t)
        :Persona(n),codigo(c),especialidad(e),tarifa(t){

        if(t<=0)
            throw invalid_argument("tarifa invalida");
    }

    string getCodigo()const{
        return codigo;
    }

    string getEspecialidad()const{
        return especialidad;
    }

    void mostrar()const override{

        cout<<"Doctor: "<<nombre
            <<" | "<<especialidad
            <<" | tarifa "<<tarifa<<endl;
    }
};

/*================================================
CITA (ASOCIACION)
================================================*/

class Cita{

    int id;

    Paciente* paciente;
    Doctor* doctor;

    string fecha;
    string hora;
    string motivo;

    bool activa=true;

public:

    Cita(int i,Paciente* p,Doctor* d,string f,string h,string m)
        :id(i),paciente(p),doctor(d),fecha(f),hora(h),motivo(m){}

    int getId()const{
        return id;
    }

    Doctor* getDoctor()const{
        return doctor;
    }

    Paciente* getPaciente()const{
        return paciente;
    }

    string getFecha()const{
        return fecha;
    }

    string getHora()const{
        return hora;
    }

    void cancelar(){
        activa=false;
    }

    bool estaActiva()const{
        return activa;
    }

    void mostrar(){

        cout<<"Cita "<<id
        <<" | Paciente "<<paciente->getNombre()
        <<" | Doctor "<<doctor->getNombre()
        <<" | "<<fecha<<" "<<hora
        <<" | "<<motivo;

        if(!activa) cout<<" [CANCELADA]";

        cout<<endl;
    }
};

/*================================================
CLINICA
(AGREGACION)
================================================*/

class Clinica{

    vector<unique_ptr<Paciente>> pacientes;
    vector<unique_ptr<Doctor>> doctores;
    vector<unique_ptr<Cita>> citas;

    int contadorCitas=1;

public:

    void registrarPaciente(string dni,string nombre,int edad,string tel){

        pacientes.push_back(
            make_unique<Paciente>(dni,nombre,edad,tel)
        );

        cout<<"Paciente registrado\n";
    }

    void registrarDoctor(string cod,string nom,string esp,double tarifa){

        doctores.push_back(
            make_unique<Doctor>(cod,nom,esp,tarifa)
        );

        cout<<"Doctor registrado\n";
    }

    Paciente* buscarPaciente(string dni){

        for(auto &p:pacientes)
            if(p->getDni()==dni)
                return p.get();

        throw EntidadNoEncontrada("Paciente no existe");
    }

    Doctor* buscarDoctor(string cod){

        for(auto &d:doctores)
            if(d->getCodigo()==cod)
                return d.get();

        throw EntidadNoEncontrada("Doctor no existe");
    }

    void agendarCita(string dni,string cod,string fecha,string hora,string motivo){

        Paciente* p=buscarPaciente(dni);
        Doctor* d=buscarDoctor(cod);

        for(auto &c:citas)
            if(c->getDoctor()==d &&
               c->getFecha()==fecha &&
               c->getHora()==hora &&
               c->estaActiva())

                throw runtime_error("doctor ocupado");

        citas.push_back(
            make_unique<Cita>(contadorCitas++,p,d,fecha,hora,motivo)
        );

        cout<<"Cita creada\n";
    }

    void cancelarCita(int id){

        for(auto &c:citas)

            if(c->getId()==id){

                c->cancelar();
                cout<<"Cita cancelada\n";
                return;
            }

        throw EntidadNoEncontrada("Cita no encontrada");
    }

    void citasPaciente(string dni){

        Paciente* p=buscarPaciente(dni);

        for(auto &c:citas)
            if(c->getPaciente()==p)
                c->mostrar();
    }

    void citasDoctor(string cod){

        Doctor* d=buscarDoctor(cod);

        for(auto &c:citas)
            if(c->getDoctor()==d)
                c->mostrar();
    }

    vector<unique_ptr<Cita>>& getCitas(){
        return citas;
    }
};

/*================================================
REPORTE
(DEPENDENCIA)
================================================*/

class Reporte{

public:

    static void citasPorEspecialidad(Clinica& c){

        map<string,int> contador;

        for(auto &cita:c.getCitas()){

            string esp=cita->getDoctor()->getEspecialidad();
            contador[esp]++;
        }

        cout<<"\n--- REPORTE ---\n";

        for(auto &p:contador)
            cout<<p.first<<" -> "<<p.second<<" citas\n";
    }
};

/*================================================
MAIN
================================================*/

int main(){

    Clinica clinica;

    while(true){

        try{

            cout<<"\n--- CLINICA SALUD+ ---\n";

            cout<<"1 Registrar paciente\n";
            cout<<"2 Registrar doctor\n";
            cout<<"3 Agendar cita\n";
            cout<<"4 Cancelar cita\n";
            cout<<"5 Citas por paciente\n";
            cout<<"6 Citas por doctor\n";
            cout<<"7 Reporte especialidad\n";
            cout<<"8 Salir\n";

            int op = leerEntero("Opcion: ",1,8);

            if(op==8) break;

            if(op==1){

                string dni = leerTexto("DNI: ");
                string nombre = leerTexto("Nombre: ");
                int edad = leerEntero("Edad: ",0,120);
                string tel = leerCelular();
                clinica.registrarPaciente(dni,nombre,edad,tel);
            }

            if(op==2){

                string cod = leerTexto("Codigo: ");
                string nom = leerTexto("Nombre Doctor: ");
                string esp = leerTexto("Especialidad: ");
                double tarifa = leerDouble("Tarifa: ",0);

                clinica.registrarDoctor(cod,nom,esp,tarifa);
            }

            if(op==3){

                string dni = leerTexto("DNI paciente: ");
                string cod = leerTexto("Codigo doctor: ");
                string fecha = leerTexto("Fecha (YYYY-MM-DD): ");
                string hora = leerTexto("Hora (HH:MM): ");
                string motivo = leerTexto("Motivo: ");

                clinica.agendarCita(dni,cod,fecha,hora,motivo);
            }

            if(op==4){

                int id = leerEntero("ID cita: ",1,100000);

                clinica.cancelarCita(id);
            }

            if(op==5){

                string dni = leerTexto("DNI paciente: ");
                clinica.citasPaciente(dni);
            }

            if(op==6){

                string cod = leerTexto("Codigo doctor: ");
                clinica.citasDoctor(cod);
            }

            if(op==7){

                Reporte::citasPorEspecialidad(clinica);
            }

        }
        catch(exception& e){

            cout<<"Error: "<<e.what()<<endl;
        }
    }

    cout<<"Sistema finalizado\n";
}