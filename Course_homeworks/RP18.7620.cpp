#include <iostream>
#include <vector>
using namespace std;

class Cliente{
    private:
    string ci;
    string nombre;
    string apellido;
    float cantidadFrutas;

    public:

    Cliente() : ci(""), nombre(""), apellido(""), cantidadFrutas(0) {}

    void leer(){
        cout << "Ing ci: ";
        cin >> ci;
        cout << "Ing nombre: ";
        cin >> nombre;
        cout << "Ing apellido: ";
        cin >> apellido;
        cout << "Ing cantidad de frutas: ";
        cin >> cantidadFrutas;
    }

    float getCantidadFrutas(){return cantidadFrutas;}

    float valorPago(){
        return 2.45 * cantidadFrutas;
    }
    
    void mostrar(){
        cout << "Ci: " << ci;
        cout << "Nombre: " << nombre;
        cout << "Apellido: " << apellido;
        cout << "Cantidad de Frutas: " << cantidadFrutas;
    }
};

class Afiliado : public Cliente {
    private:
    string codigoAfiliado;

    public:
    
    Afiliado() : Cliente(), codigoAfiliado(""){}

    void leer(){
        Cliente::leer();
        cout << "Ing numero de Afiliado: ";
        cin >> codigoAfiliado;
    }

    float valorPago(){
        return 2.15 * getCantidadFrutas();
    }

    void mostrar(){
        Cliente::mostrar();
        cout << "Codigo Afiliado: " << codigoAfiliado;
    }


};

class Fruteria {
    private:
    string nombre;
    string direccion;
    Cliente cliente[100]; // afiliado < cliente
    Afiliado afiliado[50];
    int cantidadClientes, cantidadAfiliados;

    public:
    Fruteria() : nombre(""), direccion(""), cantidadAfiliados(0), cantidadClientes(0) {}

    void leer() {
        cout << "Ingrese nombre de la fruteria: ";
        cin >> nombre;
        cout << "Ingrese direccion de la fruteria: ";
        cin >> direccion;

        cout << "Ingrese cantidad de clientes: ";
        cin >> cantidadClientes;
        leerCliente();
        cout << "Ingrese cantidad de afiliados: ";
        cin >> cantidadAfiliados;
        leerAfiliado();
    }

    void leerCliente(){
        for (int i = 0; i < cantidadClientes ; i++){
            cliente[i].leer();
        }
    }

    void leerAfiliado(){
        for (int i = 0; i < cantidadAfiliados ; i++){
            afiliado[i].leer();
        }
    }

    void mostrar() {
        cout << "\nNombre de la fruteria: " << nombre << endl;
        cout << "Direccion de la fruteria: " << direccion << endl;
        
        cout << "\n--- Clientes ---\n";
        for (int i = 0; i < cantidadClientes; i++) {
            cliente[i].mostrar();
            cout << endl;
        }

        cout << "\n--- Afiliados ---\n";
        for (int i = 0; i < cantidadAfiliados; i++) {
            afiliado[i].mostrar();
            cout << endl;
        }
    }

    float buscarMayorPagoAfiliado() {
        float mayorPago = afiliado[0].valorPago();
        for (int i = 1; i < cantidadAfiliados; i++) {
            if (afiliado[i].valorPago() > mayorPago) {
                mayorPago = afiliado[i].valorPago();
            }
        }
        return mayorPago;
    }

    vector<int> seleccionarAfiliadosMasCompras() {
        vector<int> pos;
        float mayor = buscarMayorPagoAfiliado();
        for (int i = 0; i < cantidadAfiliados; i++) {
            if (afiliado[i].valorPago() == mayor) {
                pos.push_back(i);
            }
        }
        return pos;
    }

    void mostrarAfiliadosMasCompras() {
        vector<int> posiciones = seleccionarAfiliadosMasCompras();
        cout << "Afiliado(s) que más han comprado:\n";
        for (int pos : posiciones) {
            afiliado[pos].mostrar();
            cout << endl;
        }
    }

    float buscarMenorPago(){
        float menorPago = cliente[0].valorPago();

        for (int i = 1 ; i < cantidadClientes ; i++){
            if (cliente[i].valorPago() < menorPago) {
                menorPago = cliente[i].valorPago();
            }
        }
        return menorPago;
    }

    vector<int> SeleccionarClientesMenosCompras(){
        vector<int> pos;
        float pago = buscarMenorPago();
        for (int i = 0; i < cantidadClientes ; i++){
            if (cliente[i].valorPago() == pago) {
                pos.push_back(i);
            }
        }
        return pos;
    }

    void mostrarClientesMenosCompras(){
        vector<int> posiciones = SeleccionarClientesMenosCompras();
        cout << "Cliente(s) que menos han comprado:\n";
        for (int pos : posiciones) {
            cliente[pos].mostrar();
            cout << endl;
        }
    }

    void mostrarClientesYAfiliadosMas100() {
        cout << "Clientes y afiliados que han comprado más de $100.00:\n";
        
        for (int i = 0; i < cantidadClientes; i++) {
            if (cliente[i].valorPago() > 100.0) {
                cliente[i].mostrar();
                cout << endl;
            }
        }

        for (int i = 0; i < cantidadAfiliados; i++) {
            if (afiliado[i].valorPago() > 100.0) {
                afiliado[i].mostrar();
                cout << endl;
            }
        }
    }

};

int main(){
    Fruteria f;
    f.leer();
    f.mostrar();
    f.mostrarClientesMenosCompras();
    f.mostrarAfiliadosMasCompras();
    f.mostrarClientesYAfiliadosMas100();

    return 0;
}