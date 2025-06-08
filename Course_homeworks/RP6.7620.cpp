#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bus{
    private:
    string nombrePropietario;
    string apellidoPropietario;
    string numero;
    string numeroPlaca;
    int cantidadAsientos;

    public:

    Bus(){
        cantidadAsientos = 0;
        nombrePropietario = apellidoPropietario = numero = numeroPlaca = "";
    }

    string getNombrePropietario(){
        return nombrePropietario;
    }

    int getCantidadAsientos(){
        return cantidadAsientos;
    }

    string getNumeroPlaca(){
        return numeroPlaca;
    }

    string getNumero(){
        return numero;
    }


    void setNumero(string num){
        numero = num;
    }

    void leer() {
        cout << "Ingrese el nombre del propietario: ";
        cin >> nombrePropietario;
        cout << "Ingrese el apellido del propietario: ";
        cin >> apellidoPropietario;
        cout << "Ingrese el número de placa: ";
        cin >> numeroPlaca;
        cout << "Ingrese numero de asientos: ";
        cin >> cantidadAsientos;
    }

    void mostrar(){
        cout << "Propietario: " << nombrePropietario << " " << apellidoPropietario << endl;
        cout << "Número de bus: " << numero << endl;
        cout << "Número placa: " << numeroPlaca << endl;
        cout << "Cantidad de asientos: " << cantidadAsientos << endl;
        cout << "------------------------" << endl;
    }

};

class Cooperativa{
    private:
    string nombre;
    string numeroCoop;
    Bus bus[100]; 
    int numeroDeBuses;
    
    public:

    Cooperativa(){
        nombre = numeroCoop = "";
        numeroDeBuses = 0;
    }

    void leer(){
        cout << "Ingrese nombre de la cooperativa: ";
        cin >> nombre;
        cout << "Ingrese el número de la cooperativa: ";
        cin >> numeroCoop;
        cout << "Ingrese número de buses: " << endl;
        cin >> numeroDeBuses;
    }

    void leerBuses() {
        for(int i = 0; i < numeroDeBuses; i++) {
            cout << "\n--- Bus #" << (i+1) << endl;
            bus[i].leer();
        }
    }

    /*
    - Por resolución de la ANT, el número de los buses debe tener el siguiente formato: 
    #COOP#BUS, por ejemplo para la cooperativa número 40 y su bus número 10, 
    el número del bus sería 4010. Elaborar un método que permita actualizar 
    todos los números de los bueses a dicho formato.
    */

    void actualizarNumeroBus(){ 
        for (int i = 0 ; i < numeroDeBuses ; i++){
            bus[i].setNumero(numeroCoop + bus[i].getNumero());
        }
    }

    vector<int> compararNumeroAsientos(){
        vector<int> posiciones;

        for (int i = 0 ; i < numeroDeBuses ; i++){
            if (bus[i].getCantidadAsientos() >= 20){
                posiciones.push_back(i);
            }
        }
        
        return posiciones;
    }
    
    void mostrarPorAsientos(){
        vector<int> posiciones = compararNumeroAsientos();

        for (int i : posiciones){
            bus[i].mostrar();
        }
    }

    string obtenerNombrePropietario(){
        string nombre;
        cout << "Ingrese el nombre del propietario a buscar: ";
        cin  >> nombre;

        return nombre;
    }

    vector<int> compararPorPropietario(){
        vector<int> posiciones;
        string nombreBusqueda = obtenerNombrePropietario();

        for (int i = 0 ; i < numeroDeBuses ; i++){
            if (bus[i].getNombrePropietario().compare(nombreBusqueda) == 0){
                posiciones.push_back(i);
            }
        }

        return posiciones;
    }

    void mostrarPorPropietario(){
        vector<int> posiciones = compararPorPropietario();

        if (posiciones.size() == 0){
            cout << "No se encontraron buses que el argumento propietario." << endl;
        }

        for (int i : posiciones){
            bus[i].mostrar();
        }

    }

    string ObtenerPlaca(){
        string placa;
        cout << "Ingrese la placa del bus a buscar: ";
        cin  >> placa;

        return placa;
    }

    int compararPorPlaca(){
        string placa = ObtenerPlaca();

        int i = 0;
        while (i < numeroDeBuses){
            if (bus[i].getNumeroPlaca().compare(placa) == 0){
                return i;
            }
            i++;
        }
        return -1;
    }

    void mostrarPorPlaca(){
        int indice = compararPorPlaca();
        if (indice == -1){
            cout << "No se encontró propietario." << endl;
        } else{
            bus[indice].mostrar();
        }
    }

    int solicitarMetodoMostrar(){
        int opcion;
        cout << "Ingrese el método a mostrar" << endl;

        cout << "1. Mostrar por placa" << endl;
        cout << "2. Mostrar por asiento" << endl;
        cout << "3. Mostrar por propietario" << endl;

        cin >> opcion;

        return opcion;
    }

    void mostrar(){
        switch (solicitarMetodoMostrar())
        {
        case 1:
            mostrarPorPlaca();
            break;
        case 2:
            mostrarPorAsientos();
            break;
        case 3:
            mostrarPorPropietario();
            break;
        
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }

};


int main(){
    Cooperativa coop;
    coop.leer();
    coop.leerBuses();
    coop.actualizarNumeroBus();
    coop.mostrar();

    return 0;
}