

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Avion { 
    private:
    string marca;
    string modelo;
    string anioFabricacion;
    string identificador;
    int kilometrosVolados;
    public:

    Avion() : marca(""), modelo(""), anioFabricacion(""), identificador(""), kilometrosVolados(0) {}
    Avion(const string& id) : marca(""), modelo(""), anioFabricacion(""), identificador(id), kilometrosVolados(0) {}

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
        // No pido identificador aquí, ya que se pasa en el constructor.
        // Asi no se repite la lectura del identificador.
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

    string getMarca(){return marca;}
    string getIdentificador(){return identificador;}
    virtual int getTipo(){return 0;}

};

class Avionpasajeros : public Avion {
    private:
    int capacidadPasajerosVIP;
    int capacidadPasajerosTUR;

    public:

    Avionpasajeros() : Avion(), capacidadPasajerosVIP(0), capacidadPasajerosTUR(0) {}
    Avionpasajeros(const string& id) : Avion(id), capacidadPasajerosVIP(0), capacidadPasajerosTUR(0) {}

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
    AvCarga(const string& id) : Avion(id), capacidadCargaTon(0) {}

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

    public:

    Aeropuerto() : numAviones(0), nombre(""), direccion("") {}

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

    void leerAv(){
        int opcion;

        for (int i = 0; i < numAviones ; i++){
            opcion = solicitarTipoAvion();

            while (opcion != 1 && opcion != 2) {
                cout << "Error de opcion, no se creo el objeto.\nIngrese nuevamente: " << endl;
                cin >> opcion;
            }
            // solicitar identifiador.
            string identificador;
            cout << "Ingrese identificador del avión: ";
            cin >> identificador;

            while (buscarAvporIdentificador(identificador) != -1) {
                cout << "Ya existe un avión con ese identificador. Ingrese otro: ";
                cin >> identificador;
            }
            
            if (opcion == 1) {
                aviones[i] = new Avionpasajeros(identificador);
            } else if (opcion == 2){
                aviones[i] = new AvCarga(identificador);
            }
            
            aviones[i]->leer();
        }
    }

    int buscarAvporIdentificador(string identificador) {
        int i = 0;
        // Recorre el vector de aviones hasta encontrar el identificador o llegar al final.
        if (numAviones == 0) {
            return -1; // No hay aviones.
        }

        while (i < numAviones) {
            if (aviones[i]->getIdentificador() == identificador) {
                return i;
            }

            i++;
        }

        return -1;
    }

    int solicitarTipoAvion(){
        int input;
        cout << "--------------------" << endl;
        cout << "Ingrese tipo de avion" << endl;
        cout << "1. Avion de pasajeros" << endl;
        cout << "2. Avion de carga" << endl;

        cout << "Ingrese: ";
        cin >> input;

        return input;
    }

    // 2. 
    // Mostrar la información del aeropuerto y sus aviones que, cuya capacidad de pasajeros sea igual a un valor ingresado por el usuario del programa.
    void mostrar(){
        cout << "INFORMACION DEL AEROPUERTO" << endl;
        cout << "========================" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Numero de Aviones: " << numAviones << endl;
        cout << "AVIONES POR CAPACIDAD DE PASAJEROS" << endl;
        cout << "-------------------" << endl;
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
            cout << "--------------------" << endl;
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

    // 3. Mostrar los aviones de carga cuyo año de fabricación sea 2000.
    void mostrarAvionesCargaAnio2000() {
        cout << "AVIONES DE CARGA FABRICADOS EN EL AÑO 2000" << endl;
        cout << "========================" << endl;
        bool encontrado = false;
        
        for (int i = 0; i < numAviones; i++) {
            if (aviones[i]->getTipo() == 2 && aviones[i]->getAnioFabricacion() == "2000") {
                aviones[i]->mostrar();
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "No hay aviones de carga fabricados en el año 2000." << endl;
        }
        cout << "-------------------" << endl;
    }


    // 4.
    void mostrarAvionesMayorKm(){
        int mayorKM = CalcularMayorKmVolados();
        vector<int> posiciones = seleccionarAvionesMayorKmVolados(mayorKM);

        cout << "AVIONES CON MAYOR KM VOLADOS (" << mayorKM << "):" << endl;
        cout << "========================" << endl;
        for (int pos : posiciones){
            cout << "--------------------" << endl;
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


    // 5. Mostrar la capacidad de carga promedio de los aviones de carga de una marca ingresada por el usuario.
    void mostrarPromedioCargaPorMarca() {
        string marcaBuscada;
        cout << "Ingrese la marca para calcular el promedio de carga: ";
        cin >> marcaBuscada;
        int suma = 0, cantidad = 0;

        for (int i = 0; i < numAviones; i++) {
            if (aviones[i]->getTipo() == 2 && aviones[i]->getMarca() == marcaBuscada) {
                AvCarga* av = (AvCarga*)aviones[i];
                suma += av->getcapacidadCargaTon();
                cantidad++;
            }
        }

        if (cantidad > 0) {
            cout << "Promedio de capacidad de carga (Toneladas) para la marca " << marcaBuscada << ": "
                << (double)suma / cantidad << endl;
        } else {
            cout << "No hay aviones de carga de la marca " << marcaBuscada << "." << endl;
        }

        cout << "-------------------" << endl;
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
    aero.mostrarAvionesCargaAnio2000();
    // 4.
    aero.mostrarAvionesMayorKm();
    // 5.
    aero.mostrarPromedioCargaPorMarca();

    return 0;
}