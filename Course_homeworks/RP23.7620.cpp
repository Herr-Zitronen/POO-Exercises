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

    string getAnioFabricacion(){return anioFabricacion;}
    
    int getkilometrosVolados(){return kilometrosVolados;}

    string getMarca(){return marca;}
    string getIdentificador(){return identificador;}

};

class AvPasajeros : public Avion {
    private:
    int capacidadPasajerosVIP;
    int capacidadPasajerosTUR;

    public:

    AvPasajeros() : Avion(), capacidadPasajerosVIP(0), capacidadPasajerosTUR(0) {}
    AvPasajeros(const string& id) : Avion(id), capacidadPasajerosVIP(0), capacidadPasajerosTUR(0) {}


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
};

class Aeropuerto {
    private: 
    string nombre, direccion;
    Avion* aviones[200];
    int numAviones;

    public:

    Aeropuerto() : numAviones(0), nombre(""), direccion("") {}

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
                aviones[i] = new AvPasajeros(identificador);
            } else if (opcion == 2){
                aviones[i] = new AvCarga(identificador);
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

    //

    void mostrarAvionPorIdentificador(){
        int posicion = buscarAvporIdentificador();
        cout << "MOSTRAR AVION POR IDENTIFICADOR" << endl;
        cout << "========================" << endl;

        if (posicion == -1) {
            cout << "No existe un avión con ese identificador." << endl;
            return;
        }
        cout << "--------------------" << endl;
        aviones[posicion]-> mostrar();
    }

    string solicitarValor(string mensaje){
        string valor;
        cout << "Ingrese " + mensaje << endl;
        cin >> valor;
        return valor;
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

    int buscarAvporIdentificador() {
        string identificador = solicitarValor("identificador: ");
        return buscarAvporIdentificador(identificador);
    }


    //

    void agregarAvion() {
        cout << "AGREGAR AVION" << endl;
        cout << "========================" << endl;

        if (numAviones >= 200) {
            cout << "No se pueden agregar más aviones." << endl;
            return;
        }
        string identificador = solicitarValor("identificador del nuevo avión: ");

        if (buscarAvporIdentificador(identificador) != -1) {
            cout << "Ya existe un avión con ese identificador." << endl;
            return;
        }

        int opcion = solicitarTipoAvion();
        Avion* nuevo = nullptr;

        if (opcion == 1) {
            nuevo = new AvPasajeros(identificador);
        } else if (opcion == 2) {
            nuevo = new AvCarga(identificador);
        } else {
            cout << "Tipo de avión inválido." << endl;
            return;
        }

        nuevo->leer();
        aviones[numAviones++] = nuevo;
        cout << "Avión agregado exitosamente." << endl;
    }

    void modificarAvion() {
        cout << "MODIFICAR AVION" << endl;
        cout << "========================" << endl;

        string identificador = solicitarValor("identificador a modificar: ");
        int pos = buscarAvporIdentificador(identificador);

        if (pos == -1) {
            cout << "No existe un avión con ese identificador." << endl;
            return;
        }

        cout << "Ingrese los nuevos datos del avión:" << endl;
        aviones[pos]->leer();
        cout << "Datos modificados exitosamente." << endl;
    }

    void eliminarAvion() {
        cout << "ELIMINAR AVION" << endl;
        cout << "========================" << endl;

        string identificador = solicitarValor("identificador a eliminar: ");
        int pos = buscarAvporIdentificador(identificador);

        if (pos == -1) {
            cout << "No existe un avión con ese identificador." << endl;
            return;
        }
        delete aviones[pos];

        for (int i = pos; i < numAviones - 1; i++) { // reordenar.
            aviones[i] = aviones[i + 1];
        }

        numAviones--;
        cout << "Avión eliminado exitosamente." << endl;
    }

    void mostrarAvionesMenorKm() {
        cout << "MOSTRAR AVIONES CON MENOR KM" << endl;
        cout << "========================" << endl;
        if (numAviones == 0) {
            cout << "No hay aviones." << endl;
            return;
        }

        int menorKM = aviones[0]->getkilometrosVolados();
        // implementacion corta

        for (int i = 1; i < numAviones; i++) {
            if (aviones[i]->getkilometrosVolados() < menorKM) {
                menorKM = aviones[i]->getkilometrosVolados();
            }
        }

        cout << "Aviones con menos kilómetros volados (" << menorKM << "):" << endl;

        for (int i = 0; i < numAviones; i++) {
            if (aviones[i]->getkilometrosVolados() == menorKM) {
                aviones[i]->mostrar();
            }
        }
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
    aero.mostrarAvionesMayorKm();
    // 3.
    aero.mostrarAvionPorIdentificador();
    // 4.
    aero.agregarAvion();
    // 5.
    aero.eliminarAvion();
    // 6.
    aero.modificarAvion();
    // 7. 
    aero.mostrarAvionesMenorKm();

    return 0;
}