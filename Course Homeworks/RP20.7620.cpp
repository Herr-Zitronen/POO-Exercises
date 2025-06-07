#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Avion {
    private:
    string marca, modelo;
    int anioFabricacion;
    float kilometrosVolados;

    public:
    Avion() : marca(""), modelo(""), anioFabricacion(0), kilometrosVolados(0) {}

    void leer(){
        cout << "Ingrese marca: ";
        cin >> marca;
        cout << "Ingrese modelo: ";
        cin >> modelo;
        cout << "Ingrese año de fabricación: ";
        cin >> anioFabricacion;
        cout << "Ingrese kilómetros volados: ";
        cin >> kilometrosVolados;
    }

    void mostrar(){
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año de fabricación: " << anioFabricacion << endl;
        cout << "Kilómetros volados: " << kilometrosVolados << endl;
    }

    string getMarca() { return marca; }
    float getKilometrosVolados() { return kilometrosVolados; }
    int getAnioFabricacion() { return anioFabricacion; }
};

class AvionPasajeros : public Avion {
    private:
    int capacidadPasajerosVIP;
    int capacidadPasajerosTuristas;

    public:
    AvionPasajeros() : Avion(), capacidadPasajerosVIP(0), capacidadPasajerosTuristas(0) {}

    int totalPasajeros(){
        return capacidadPasajerosTuristas + capacidadPasajerosVIP;
    }

    void leer(){
        Avion::leer();
        cout << "Ingrese capacidad de pasajeros VIP: ";
        cin >> capacidadPasajerosVIP;
        cout << "Ingrese capacidad de pasajeros Turistas: ";
        cin >> capacidadPasajerosTuristas;
    }

    void mostrar(){
        Avion::mostrar();
        cout << "Capacidad de pasajeros VIP: " << capacidadPasajerosVIP << endl;
        cout << "Capacidad de pasajeros Turistas: " << capacidadPasajerosTuristas << endl;
        cout << "Capacidad total de pasajeros: " << totalPasajeros() << endl;
    }
};

class AvionCarga : public Avion {
    private:
    float capacidadCargaTon;

    public:
    AvionCarga() : Avion(), capacidadCargaTon(0.0) {}

    void leer(){
        Avion::leer();
        cout << "Ingrese capacidad de carga (toneladas): ";
        cin >> capacidadCargaTon;
    }

    void mostrar(){
        Avion::mostrar();
        cout << "Capacidad de carga: " << capacidadCargaTon << " toneladas" << endl;
    }

    float getCapacidadCarga() { return capacidadCargaTon; }
};

class Aeropuerto {
    private:
    string nombre, direccion;
    AvionPasajeros av[50];
    AvionCarga ac[50];
    int cantidadAV, cantidadAC;

    public:
    Aeropuerto() : nombre(""), direccion(""), cantidadAC(0), cantidadAV(0) {}

    void leer(){
        cout << "Ingrese nombre del aeropuerto: ";
        cin >> nombre;
        cout << "Ingrese dirección del aeropuerto: ";
        cin.ignore();
        getline(cin, direccion);

        cout << "Ingrese cantidad de aviones de pasajeros: ";
        cin >> cantidadAV;
        leerAV();
        
        cout << "Ingrese cantidad de aviones de carga: ";
        cin >> cantidadAC;
        leerAC();
    }

    void leerAV(){
        cout << "---------INGRESE AVIONES DE PASAJEROS-------------"<< endl;

        for(int i = 0; i < cantidadAV; i++) {
            cout << "\nDatos del avión de pasajeros " << (i+1) << ":" << endl;
            av[i].leer();
        }
        cout << "---------" << endl;
    }

    void leerAC(){
        cout << "---------INGRESE AVIONES DE CARGA-------------"<< endl;

        for(int i = 0; i < cantidadAC; i++) {
            cout << "\nDatos del avión de carga " << (i+1) << ":" << endl;
            ac[i].leer();
        }

        cout << "----------" << endl;
    }


    void mostrarAeropuerto(){
        cout << "\n----- INFORMACIÓN DEL AEROPUERTO -----" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Dirección: " << direccion << endl;
    }

    

    void mostrar(){
        mostrarAeropuerto();
        mostrarAVPorCantidadPasajeros();
    }

    int solicitarCantidadPasajeros(){
        int cantidad;
        cout << "\nIngrese la cantidad de pasajeros a buscar: ";
        cin >> cantidad;
        return cantidad;
    }

    void mostrarAVPorCantidadPasajeros(){
        int cantidad = solicitarCantidadPasajeros();
        cout << "\nAviones con capacidad igual a " << cantidad << " pasajeros:" << endl;
        bool encontrado = false;
        
        for (int i = 0; i < cantidadAV; i++){
            if (av[i].totalPasajeros() == cantidad){
                av[i].mostrar();
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            cout << "No se encontraron aviones con esa capacidad." << endl;
        }
    }

    void mostrarACAnio2000() {
        cout << "\nAviones de carga fabricados en el año 2000:" << endl;
        bool encontrado = false;
        
        for (int i = 0; i < cantidadAC; i++) {
            if (ac[i].getAnioFabricacion() == 2000) {
                ac[i].mostrar();
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            cout << "No se encontraron aviones de carga del año 2000." << endl;
        }
    }

    void mostrarAvionMasKilometros() {
        if (cantidadAV == 0 && cantidadAC == 0) {
            cout << "\nNo hay aviones registrados." << endl;
            return;
        }

        float maxKilometros = 0;
        bool esAvionPasajeros = true;
        int indice = 0;
        
        for (int i = 0; i < cantidadAV; i++) {
            if (av[i].getKilometrosVolados() > maxKilometros) {
                maxKilometros = av[i].getKilometrosVolados();
                esAvionPasajeros = true;
                indice = i;
            }
        }
        
        for (int i = 0; i < cantidadAC; i++) {
            if (ac[i].getKilometrosVolados() > maxKilometros) {
                maxKilometros = ac[i].getKilometrosVolados();
                esAvionPasajeros = false;
                indice = i;
            }
        }
        
        cout << "\nAvión que más kilómetros ha volado:" << endl;
        if (esAvionPasajeros) {
            cout << "Es un avión de pasajeros:" << endl;
            av[indice].mostrar();
        } else {
            cout << "Es un avión de carga:" << endl;
            ac[indice].mostrar();
        }
    }

    string solicitarMarca(){
        string marcaBuscar;
        cout << "\nIngrese la marca para calcular capacidad promedio de carga: ";
        cin >> marcaBuscar;

        return marcaBuscar;
    }

    vector<int> seleccionarPorMarca(string marcaBuscar){
        vector<int> posiciones;
        int contador = 0;

        for (int i = 0; i < cantidadAC; i++) {
            if (ac[i].getMarca() == marcaBuscar) {
                posiciones.push_back(i);
            }
        }
        return posiciones;
    }

    void mostrarACporCarga() {
        string marcaBuscar = solicitarMarca();
        float sumaCapacidad = 0;
        vector<int> posiciones = seleccionarPorMarca(marcaBuscar);
        int size = posiciones.size();
        
        for (int pos: posiciones){
            sumaCapacidad += ac[pos].getCapacidadCarga();
        }
        
        if (size > 0) {
            float promedio = sumaCapacidad / size;
            cout << "Capacidad promedio de carga para la marca " << marcaBuscar << ": " 
                 << promedio << " toneladas" << endl;
        } else {
            cout << "No se encontraron aviones de carga de la marca " << marcaBuscar << endl;
        }
    }
};

int main(){
    Aeropuerto aeropuerto;

    aeropuerto.leer();
    aeropuerto.mostrar();
    aeropuerto.mostrarACAnio2000();
    aeropuerto.mostrarAvionMasKilometros();
    aeropuerto.mostrarACporCarga();
    
    return 0;
}
