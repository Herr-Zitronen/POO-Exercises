#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Avion {
    private:
    string marca;
    string modelo;
    string anioFabricacion;
    int kilometrosVolados;
    public:

    Avion() : marca(""), modelo(""), anioFabricacion(""), kilometrosVolados(0) {}

    void leer(){
        cout << "INGRESAR" << endl;
        cout << "Marca: ";
        cin >> marca;
        cout << "Modelo: ";
        cin >> modelo;
        cout << "Año de Fabricacion: ";
        cin >> anioFabricacion;
        cout << "Kilómetros volados: ";
        cin >> kilometrosVolados;
    }

    void mostrar(){
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año de Fabricacion: " << anioFabricacion << endl;
        cout << "Kilómetros volados: " << kilometrosVolados << endl;
    }

    string getAnioFabricacion(){return anioFabricacion;}
    
    int getkilometrosVolados(){return kilometrosVolados;}

    string getmarca(){return marca;}

};

class AvPasajeros : public Avion {
    private:
    int capacidadPasajerosVIP;
    int capacidadPasajerosTUR;

    public:

    AvPasajeros() : Avion(), capacidadPasajerosVIP(0), capacidadPasajerosTUR(0) {}

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
};

class Aeropuerto {
    private: 
    string nombre, direccion;
    AvPasajeros* avP[100];
    AvCarga* avC[100];
    int numAvP, numAvC;

    public:

    Aeropuerto() : numAvP(0), numAvC(0), nombre(""), direccion("") {}

    void leer(){
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Direccion: ";
        cin >> direccion;
        cout << "Numero de Aviones de Pasajeros: ";
        cin >> numAvP;
        leerAvP();
        cout << "Numero de Aviones de Carga: ";
        cin >> numAvC;
        leerAvC();
    }
    
    void leerAvP(){
        for (int i = 0; i < numAvP ; i++){
            avP[i] = new AvPasajeros;
            avP[i] ->leer();
        }
    }

    void leerAvC(){
        for (int i = 0; i < numAvC ; i++){
            avC[i] = new AvCarga;
            avC[i] ->leer();
        }
    }

    // 2.

    void mostrar(){
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Numero de Aviones de Pasajeros: " << numAvP << endl;
        cout << "Numero de Aviones de Carga: " << numAvC << endl;
        cout << "AVIONES POR CAPACIAD DE CARGA INGRESADA POR USUARIO" << endl;
        mostrarPorCapacidadPasajeros();
        cout << "-------------------" << endl;
    }

    void mostrarPorCapacidadPasajeros(){
        if (numAvC == 0) {
            cout << "No hay aviones de carga." << endl;
            cout << "-------------------" << endl;
            return;
        }

        vector<int> posiciones = selAvPPorCapacidadPasajeros(
                                stoi(solicitarValor("Un valor de capacidad de Pasajeros")));

        for (int pos : posiciones){
            avP[pos]->mostrar(); 
        }
    }

    string solicitarValor(string mensaje){
        string valor;
        cout << "Ingrese " + mensaje << endl;
        cin >> valor;
        return valor;
    }

    vector <int> selAvPPorCapacidadPasajeros(int valorUsuario){
        vector <int> posiciones;
        for (int i = 0; i < numAvP ; i++){
            if (avP[i]->capacidadTotalPasajeros() == valorUsuario){
                posiciones.push_back(i);
            }
        }

        return posiciones;
    }

    //

    void mostrarAvCPorAnioDeFabricacion(){
        vector<int> posicionesAvC;

        posicionesAvC = selAvCPorAnioFabricacion();

        for (int pos : posicionesAvC){
            avC[pos]->mostrar(); 
        }
    }


    vector <int> selAvCPorAnioFabricacion(){
        vector <int> posiciones;
        for (int i = 0; i < numAvC ; i++){
            if (avC[i]->getAnioFabricacion().compare("2000") == 0){
                posiciones.push_back(i);
            }
        }

        return posiciones;
    }

    void mostrarAvionesMayorKm(){
        int mayorKM = CalcularMayorKmVolados();
        vector<int> posicionesAvP = seleccionarAvPMayorKmVolados(mayorKM);
        vector<int> posicionesAvC = seleccionarAvCMayorKmVolados(mayorKM);

        for (int pos : posicionesAvP){
            avP[pos]->mostrar();
        }

        for (int pos : posicionesAvC){
            avC[pos]->mostrar();
        }

    }

    int CalcularMayorKmVolados() {
        if (numAvP == 0 && numAvC == 0) return 0;
        
        int mayorKM = -1;
        
        if (numAvP > 0) {
            mayorKM = avP[0]->getkilometrosVolados();
            // resuelve para AVP
        } else if (numAvC > 0) {
            mayorKM = avC[0]->getkilometrosVolados();
            // resuelve para AVC
        }
        
        for (int i = 0; i < numAvP; i++) {
            if (avP[i]->getkilometrosVolados() > mayorKM) {
                mayorKM = avP[i]->getkilometrosVolados();
            }
        }
        
        for (int i = 0; i < numAvC; i++) {
            if (avC[i]->getkilometrosVolados() > mayorKM) {
                mayorKM = avC[i]->getkilometrosVolados();
            }
        }
        
        return mayorKM;
    }

    vector<int> seleccionarAvPMayorKmVolados(int mayorKM) {
        vector<int> indices;

        for (int i = 0; i < numAvP; i++) {
            if (avP[i]->getkilometrosVolados() == mayorKM) {
                indices.push_back(i);
            }
        }

        return indices;
    }

    vector<int> seleccionarAvCMayorKmVolados(int mayorKM){
        vector<int> indices;

        for (int i = 0; i < numAvC; i++) {
            if (avC[i]->getkilometrosVolados() == mayorKM) {
                indices.push_back(i);
            }
        }
        
        return indices;
    }

    float calcularCargaPromedio(string marca){
        float toneladasTotales = 0;
        int contador = 0;

        for (int i = 0; i < numAvC ; i++){
            if (avC[i]->getmarca().compare(marca) == 0){
                toneladasTotales = toneladasTotales + avC[i]->getcapacidadCargaTon();
                contador = contador + 1;
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
        for (int i = 0; i < numAvP; i++) {
            delete avP[i];
        }

        for (int i = 0; i < numAvC; i++) {
            delete avC[i];
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