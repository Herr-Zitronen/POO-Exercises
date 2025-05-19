#include <iostream>
#include <vector>

using namespace std;


class Factura{
    private:
    string numeroMedidor;
    string cidueno;
    int lecturaActual;
    int lecturaAnterior;

    public:

    Factura(){
        numeroMedidor = cidueno = "";
        lecturaActual = lecturaAnterior = 0;
    }

    string getNumMedidor(){
        return numeroMedidor;
    }

    void leer(){
        cout << "Ingrese numero del medidor: ";
        cin >> numeroMedidor;
        cout << "Ingrese CI del dueño: ";
        cin >> cidueno;
        cout << "Ingrese lectura Actual: ";
        cin >> lecturaActual;
        cout << "Ingrese lectura Anterior: ";
        cin >> lecturaAnterior;
    }

    void mostrar(){
        cout << "---------------" << endl;
        cout << "numero del Medidor: " << numeroMedidor << endl;
        cout << "CI del dueño: " << cidueno << endl;
        cout << "Lectura actual: " << lecturaActual << endl;
        cout << "Lectura anterior: " << lecturaAnterior << endl;
    }

    int obtenerConsumo(){
        return (lecturaActual - lecturaAnterior); 
    }



};

class EmpresaElectrica{
    private:
    string nombre;
    string ciudad;
    Factura factus[130];
    int numeroFacturas;

    public:

    EmpresaElectrica(){
        nombre = ciudad = "";
        numeroFacturas = 0;
    }

    void leer(){
        cout << "Ingrese nombre de la empresa: ";
        cin >> nombre;
        cout << "Ingrese ciudad: ";
        cin >> ciudad;
        cout << "Ingrese numero de Facturas: ";
        cin >> numeroFacturas;
    }

    void leerFactus(){
        for (int i = 0; i < numeroFacturas; i++){
            factus[i].leer();
        }
    }

    float calcularConsumoPromedio(){
        float promedio;
        float consumoTotal = 0.0;

        for (int i = 0; i < numeroFacturas ; i++){
            consumoTotal = consumoTotal + factus[i].obtenerConsumo();
        }

        promedio = consumoTotal / numeroFacturas;

        return promedio;
    }

    vector<int> seleccionFacturasPromedio(){
        vector<int> posiciones;
        float promedio = calcularConsumoPromedio();

        for (int i = 0; i < numeroFacturas ; i++){
            if (factus[i].obtenerConsumo() >= promedio){
                posiciones.push_back(i);
            }
        }

        return posiciones;
    }

    string solicitarNumeroMedidor(){
        string nmed;
        cout << "Ingrese un numero de medidor: ";
        cin >> nmed;

        return nmed;
    }

    int seleccionFacturasMedidor(){
        string numeroMed = solicitarNumeroMedidor();
        bool encontrado = false;
        int pos = -1;
        int i = 0;
        
        while (!encontrado && i < numeroFacturas){
            if (factus[i].getNumMedidor().compare(numeroMed) == 0){
                pos = i;
                encontrado = true;
            }

            i++;
        }

        return pos;
    }


    void mostrarFacturasPorPromedio(){
        vector<int> posiciones = seleccionFacturasPromedio();

        cout << "Facturas por promedio" << endl;

        for (int pos : posiciones){
            factus[pos].mostrar();
        }
    }

    void mostrarFacturasPorNumMedidor(){
        int pos = seleccionFacturasMedidor();
        
        if (pos != -1){
            cout << "Facturas por número de medidor" << endl;
            factus[pos].mostrar();
        }else{
            cout << "No se encontro ese numero de medidor." << endl;
        }
        
    }

};


int main(){
    EmpresaElectrica empresa;

    empresa.leer();
    empresa.leerFactus();
    empresa.mostrarFacturasPorPromedio();
    empresa.mostrarFacturasPorNumMedidor();


    return 0;
}