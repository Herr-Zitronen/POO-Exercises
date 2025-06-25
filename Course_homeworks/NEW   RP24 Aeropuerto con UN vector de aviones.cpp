/*
Se desea elaborar un programa orientado a objetos en el lenguaje de programación C++, que permita gestionar la información de los 
aviones de un aeropuerto del que se conoce su nombre y dirección. El aeropuerto tiene UN único vector de aviones.

De los aviones de pasajeros se conoce su marca, modelo, capacidad de pasajeros VIP y capacidad de pasajeros turistas.

De los aviones de carga se conoce su marca, modelo y capacidad de carga en toneladas. 

    Ingresar la información del aeropuerto y sus aviones
    Mostrar la información del aeropuerto y sus aviones que, cuya capacidad de pasajeros sea igual a un valor ingresado por el usuario del programa.
    Mostrar los aviones de carga cuyo año de fabricación sea 2000.
    Mostrar el avión que más kilómetros ha volado. 
    Mostrar la capacidad de carga promedio de los aviones de carga de una marca ingresada por el usuario.

NOTA:

    Programar los métodos leer() y mostrar() en cada clase que lo necesite. 
    Asegurar que al crearse los objetos, éstos inicialicen sus atributos numéricos a 0 y las cadenas de caracteres a "".
    El nombre del archivo tiene el siguiente formato CODIGO.RP24.cpp

*/

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class Avion { 
    private:
    string marca;
    string modelo;
    string anioFabricacion;
    string identificador;
    int kilometrosVolados;
    public:

    Avion(string id) : identificador(id), marca(""), modelo(""), anioFabricacion(""), kilometrosVolados(0) {}

    Avion() : marca(""), modelo(""), anioFabricacion(""), identificador(""), kilometrosVolados(0) {}

    virtual void leer(){
        cout << "INGRESAR" << endl;
        cout << "Marca: ";
        cin >> marca;
        cout << "Modelo: ";
        cin >> modelo;
        cout << "Año de Fabricacion: ";
        cin >> anioFabricacion;
        cout << "Kilómetros volados: ";
        cin >> kilometrosVolados;
        cout << "Identificador: ";
        cin >> identificador;
    }

    void mostrar(){
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año de Fabricacion: " << anioFabricacion << endl;
        cout << "Kilómetros volados: " << kilometrosVolados << endl;
        cout << "Identificador: " << identificador << endl;
    }
    // virtual int capacidadTotalPasajeros(){}; // clase puramente abstracta. (C++ solamente.)

    string getAnioFabricacion(){return anioFabricacion;}
    
    int getkilometrosVolados(){return kilometrosVolados;}

    virtual string getMarca(){return marca;}
    string getIdentificador(){return identificador;}
    virtual int getTipo(){return 0;}

};

class Avionpasajeros : public Avion {
    private:
    int capacidadPasajerosVIP;
    int capacidadPasajerosTUR;

    public:

    Avionpasajeros() : Avion(), capacidadPasajerosVIP(0), capacidadPasajerosTUR(0) {}

    void leer(){
        Avion::leer();
        cout << "Capacidad de Pasajeros VIP: ";
        cin >> capacidadPasajerosVIP;
        cout << "Capacidad de Pasajeros Turistas: ";
        cin >> capacidadPasajerosTUR;
    }

    void mostrar(){
        Avion::mostrar();
        cout << "Capacidad de Pasajeros VIP: " << capacidadPasajerosVIP << endl;
        cout << "Capacidad de Pasajeros Turistas: " << capacidadPasajerosTUR << endl;
    }

    int capacidadTotalPasajeros(){
        return capacidadPasajerosTUR + capacidadPasajerosVIP;
    }

    int getTipo(){return 1;}

};
 
class AvCarga : public Avion {
    private:
    int capacidadCargaTon;

    public:

    AvCarga() : Avion(), capacidadCargaTon(0) {}

    void leer(){
        Avion::leer();
        cout << "Capacidad de Carga (Toneladas): ";
        cin >> capacidadCargaTon;
    }

    void mostrar(){
        Avion::mostrar();
        cout << "Capacidad de Carga (Toneladas): " << capacidadCargaTon << endl;
    }

    int getcapacidadCargaTon(){return capacidadCargaTon;}

    int getTipo(){return 2;}
};

class Aeropuerto {
    private: 
    string nombre, direccion;
    Avion* aviones[200];
    int numAviones;
    //vector<Avion*> av;

    public:

    Aeropuerto() : numAviones(0), nombre(""), direccion("") {}

    // crear avion si no existe
    // eliminar avion por ID
    // modificar avion (leer)

    void operarAvion(){
        string id = solicitarValor("ID del avion a buscar: ");
        int posicion = buscarPorID(id);

        if (posicion == -1){
            agregarAvion(id);
        } else{
            
        }
    }

    void modificarAvion(Avion* avion){

    }

    void agregarAvion(string& id){
        if (numAviones < 200){
            aviones[numAviones++] = leerAv();
        }
    }

    int buscarPorID(string& id){
        bool encontrado = false;
        int i = 0;

        while (i < numAviones && encontrado == false){
            i++;
            if (aviones[i]->getIdentificador().compare(id) == 0){
                encontrado = true;
            }
        }

        if (encontrado){
            return i;
        } else {
            return -1;
        }
    }

    void eliminarAvion(){
        
    }


    // 1.
    void leer(){
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Direccion: ";
        cin >> direccion;
        cout << "Numero de Aviones: ";
        cin >> numAviones;
        leerAv();
    }

    Avion* leerAv(){
        int opcion = solicitarTipoAvion();
        Avion* avion
            while (opcion != 1 || opcion != 0) {
                cout << "Error de opcion, no se creo el objeto.\nIngrese nuevamente: " << endl;
                cin >> opcion;
            }

            if (opcion == 1) {
                avion = new Avionpasajeros;
            } else if (opcion == 2){
                avion = new AvCarga;
            }
            
            avion->leer();
            return avion
    }

    void leerAv(){
        int opcion;

        for (int i = 0; i < numAviones ; i++){
            opcion = solicitarTipoAvion();

            while (opcion != 1 || opcion != 0) {
                cout << "Error de opcion, no se creo el objeto.\nIngrese nuevamente: " << endl;
                cin >> opcion;
            }

            if (opcion == 1) {
                aviones[i] = new Avionpasajeros;
            } else if (opcion == 2){
                aviones[i] = new AvCarga;
            }
            
            aviones[i]->leer();
        }
    }

    int solicitarTipoAvion(){
        int input;

        cout << "Ingrese tipo de avion" << endl;
        cout << "1. Avion de pasajeros" << endl;
        cout << "2. Avion de carga" << endl;

        cout << "Ingrese: ";
        cin >> input;

        return input;
    }

    // 2. 
    // Mostrar la información del aeropuerto y sus aviones que, cuya capacidad de 
    // pasajeros sea igual a un valor ingresado por el usuario del programa.
    void mostrar(){
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Numero de Aviones: " << numAviones << endl;
        cout << "AVIONES POR CAPACIAD DE CARGA INGRESADA POR USUARIO" << endl;
        mostrarPorCapacidadPasajeros();
        cout << "-------------------" << endl;
    }

    void mostrarPorCapacidadPasajeros(){
        if (numAviones == 0) {
            cout << "No hay aviones." << endl;
            cout << "-------------------" << endl;
            return;
        }

        vector<int> posiciones = selavionesorCapacidadPasajeros(
                                stoi(solicitarValor("Un valor de capacidad de Pasajeros")));

        for (int pos : posiciones){
            aviones[pos]->mostrar(); 
        }
    }

    string solicitarValor(string mensaje){
        string valor;
        cout << "Ingrese " + mensaje << endl;
        cin >> valor;
        return valor;
    }

    vector <int> selavionesorCapacidadPasajeros(int valorUsuario){
        vector <int> posiciones;

        for (int i = 0; i < numAviones ; i++){
            if (aviones[i]->getTipo() == 1){
                Avionpasajeros* pAp = (Avionpasajeros*) aviones[i];
                if (pAp-> capacidadTotalPasajeros() == valorUsuario){
                    posiciones.push_back(i);
                }
            }    
        }

        return posiciones;
    }

    //3. Mostrar los aviones de carga cuyo año de fabricación sea 2000.

    void mostrarAvCPorAnioDeFabricacion(){
        vector<int> posicionesAvC;

        posicionesAvC = selAvCPorAnioFabricacion();

        for (int pos : posicionesAvC){
            aviones[pos]->mostrar(); 
        }
    }


    vector <int> selAvCPorAnioFabricacion(){
        vector <int> posiciones;
        for (int i = 0; i < numAviones ; i++){
            if (aviones[i]->getAnioFabricacion().compare("2000") == 0){
                posiciones.push_back(i);
            }
        }

        return posiciones;
    }

    // 4.
    void mostrarAvionesMayorKm(){
        int mayorKM = CalcularMayorKmVolados();
        vector<int> posiciones = seleccionarAvionesMayorKmVolados(mayorKM);

        for (int pos : posiciones){
            aviones[pos]->mostrar();
        }

    }

    int CalcularMayorKmVolados() {
        if (numAviones == 0) return 0;
        int mayorKM = aviones[0]->getkilometrosVolados();
        
        for (int i = 1; i < numAviones; i++) {
            if (aviones[i]->getkilometrosVolados() > mayorKM) {
                mayorKM = aviones[i]->getkilometrosVolados();
            }
        }
        
        return mayorKM;
    }

    vector<int> seleccionarAvionesMayorKmVolados(int mayorKM) {
        vector<int> indices;

        for (int i = 0; i < numAviones; i++) {
            if (aviones[i]->getkilometrosVolados() == mayorKM) {
                indices.push_back(i);
            }
        }

        return indices;
    }

    //
    // Mostrar la capacidad de carga promedio de los aviones de carga de una marca ingresada por el usuario.

    float calcularCargaPromedio(string marca){
        float toneladasTotales = 0;
        int contador = 0;

        for (int i = 0; i < numAviones ; i++){
            if (aviones[i]->getTipo() == 2){
                AvCarga* pAvc = (AvCarga*) aviones[i];

                if (pAvc->getMarca().compare(marca) == 0){
                    toneladasTotales = toneladasTotales + pAvc->getcapacidadCargaTon();
                    contador = contador + 1;
                }
            }

        }

        if (contador == 0){
            return 0;
        }

        return toneladasTotales / contador;
    }

    void mostrarCargaPromedioPorMarca(){
        string marca = solicitarValor("Marca de Avion de Carga");
        
        cout << "Capacidad de carga promedio de los aviones de carga de " + marca << " es: ";
        cout << calcularCargaPromedio(marca) << endl;
    }

    ~Aeropuerto(){
        
        for (int i = 0; i < numAviones; i++) {
            delete aviones[i];
        }
    }

};

int main(){
    Aeropuerto aero;
    // 1.
    aero.leer();
    // 2.
    aero.mostrar();
    // 3.
    aero.mostrarAvCPorAnioDeFabricacion();
    // 4.
    aero.mostrarAvionesMayorKm();
    // 5. 
    aero.mostrarCargaPromedioPorMarca();
    

    return 0;
}