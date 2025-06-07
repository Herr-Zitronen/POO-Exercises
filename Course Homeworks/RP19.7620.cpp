#include <iostream>
#include <vector>
using namespace std;

class Trabajador {
    private:
    string ci;
    string nombre;
    string apellido;

    public:
    Trabajador() : ci(""), nombre(""), apellido("") {}

    void leer(){
        cout << "Ingrese ci: ";
        cin >> ci;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
    }

    void mostrar(){
        cout << "---------" << endl;
        cout << "MOSTRAR" << endl;
        cout << "Ci: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
    }

};

class TrabajadorContratado : public Trabajador{
    private: 
    int cantidadHoras;
    float valorHorasTrabajadas;

    public:
    TrabajadorContratado() : Trabajador(), cantidadHoras(0), valorHorasTrabajadas(0.0) {}

    void leer(){
        Trabajador::leer();
        cout << "Cantidad de horas trabajadas: ";
        cin >> cantidadHoras;
        cout << "Valor por Horas Trabajadas: ";
        cin >> valorHorasTrabajadas;
        
    }

    void mostrar(){
        Trabajador::mostrar();
        cout << "Cantidad de horas trabajadas: " << cantidadHoras << endl;
        cout << "Valor por horas trabajadas: " << valorHorasTrabajadas << endl;
        cout << "Pago total: " << aPagar() << endl;
    }

    float aPagar(){
        return cantidadHoras * valorHorasTrabajadas;
    }
};

class TrabajadorNombramiento : public Trabajador{
    private:
    float salario;
    float descuentoMes;

    public: 
    TrabajadorNombramiento() : Trabajador(), salario(0), descuentoMes(0){}

    void leer(){
        Trabajador::leer();
        cout << "Salario: ";
        cin >> salario;
        cout << "Descuento del mes: ";
        cin >> descuentoMes;
    }

    void mostrar(){
        Trabajador::mostrar();
        cout << "Salario: " << salario << endl;
        cout << "Descuento del mes: " << descuentoMes << endl;
        cout << "Pago total: " << aPagar() << endl;
    }

    float aPagar(){
        return salario - descuentoMes;
    }

};

class TrabajadorDestajo : public Trabajador{
    private:
    float salarioBasico;
    float porcentajeGanancia;
    int totalVentas;
    public:

    TrabajadorDestajo() : Trabajador(), salarioBasico(0.0), porcentajeGanancia(0.0), totalVentas(0){}

    void leer(){
        Trabajador::leer();
        cout << "Salario basico: ";
        cin >> salarioBasico;
        cout << "Porcentaje de ganancia: ";
        cin >> porcentajeGanancia;
        cout << "Total de ventas: ";
        cin >> totalVentas;
    }

    void mostrar(){
        Trabajador::mostrar();
        cout << "Salario Basico: " << salarioBasico << endl;
        cout << "Porcentaje de ganancia: " << porcentajeGanancia << endl;
        cout << "Total de ventas: " << totalVentas << endl;
        cout << "Pago total: " << aPagar() << endl;
        cout << "-----------" << endl;
    }

    float aPagar(){
        return salarioBasico + (porcentajeGanancia * totalVentas);
    }

};

// trabajador a destajo 
/*
tiene ci,. nombre, apellido, salario basico, porcentaje de ganancia, total de venta

salariomensual = salario basico + (ganancia * venta)
*/

class Empresa {
    private:
    string nombre;
    string direccion;
    TrabajadorContratado tc[100];
    TrabajadorNombramiento tn[100];
    TrabajadorDestajo td[100];
    int cantidadTC;
    int cantidadTN;
    int cantidadTD;

    public:
    Empresa() : nombre(""), direccion(""), cantidadTC(0), cantidadTN(0), cantidadTD(0) {}

    void leer(){
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Direccion: ";
        cin >> direccion;
        cout << "\nCantidad Tc: ";
        cin >> cantidadTC;
        cout << "Ingresar TC: " << endl;
        leerTC();
        cout << "\nCantidad Tn: ";
        cin >> cantidadTN;
        cout << "Ingresar TN: " << endl;
        leerTN();
        cout << "\nCantidad Td: ";
        cin >> cantidadTD;
        cout << "Ingresar TD: " << endl;
        leerTD();
    }

    void leerTC(){
        for (int i = 0; i < cantidadTC ; i++){
            tc[i].leer();
        }
    }

    void leerTN(){
        for (int i = 0; i < cantidadTN ; i++){
            tn[i].leer();
        }
    }

    void leerTD(){
        for (int i = 0; i < cantidadTD ; i++){
            td[i].leer();
        }
    }

    // Mostrar Empresa
    void mostrar(){
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Cantidad de trabajadores contratados :" << cantidadTC << endl;
        cout << "Cantidad de trabajadores con nombramiento :" << cantidadTN << endl;
        cout << "Cantidad de trabajadores a destajo :" << cantidadTD << endl;
    }

    float solicitarValor(){
        float valor;
        
        cout << "Ingrese valor: ";
        cin >> valor;

        return valor;
    }

    // TC
    vector<int> seleccionTCporValor(float valor){
        vector<int> pos;

        for (int i = 0; i < cantidadTC ; i++){
            if (tc[i].aPagar() > valor){
                pos.push_back(i);
            }
        }

        return pos;
    }

    void mostrarTCPorValor(vector<int> posiciones){
        for (int pos: posiciones){
            tc[pos].mostrar();
        }
    }

    // TN

    vector<int> seleccionTNporValor(float valor){
        vector<int> pos;

        for (int i = 0; i < cantidadTN ; i++){
            if (tn[i].aPagar() > valor){
                pos.push_back(i);
            }
        }

        return pos;
    }

    void mostrarTNPorValor(vector<int> posiciones){
        for (int pos: posiciones){
            tn[pos].mostrar();
        }
    }

    // TD

    vector<int> seleccionTDporValor(float valor){
        vector<int> pos;

        for (int i = 0; i < cantidadTD ; i++){
            if (td[i].aPagar() > valor){
                pos.push_back(i);
            }
        }

        return pos;
    }

    void mostrarTDPorValor(vector<int> posiciones){
        for (int pos: posiciones){
            td[pos].mostrar();
        }
    }

    // Muestra la seleccion de Trabajadores de acuerdo al valor del Usuario.
    void mostrarSeleccionTrabajadores(){
        float valor = solicitarValor();

        mostrarTCPorValor(seleccionTCporValor(valor));
        mostrarTNPorValor(seleccionTNporValor(valor));
        mostrarTDPorValor(seleccionTDporValor(valor));
    }
//
    // 
    void mostrarInformacion(){
        mostrar();
        mostrarSeleccionTrabajadores();
    }

    float calculartotalPagoEmpresa(){
        float pago = 0;

        for (int i = 0; i < cantidadTC; i++){
            pago += tc[i].aPagar();
        }

        for (int i = 0; i < cantidadTN; i++){
            pago += tn[i].aPagar();
        }

        for (int i = 0; i < cantidadTD; i++){
            pago += td[i].aPagar();
        }

        return pago;
    }

    void mostrarTotalPagoEmpresa(){
        cout << "Total a pagar: " << calculartotalPagoEmpresa() << endl;
    }


//
    float calcularMenorPagoTC(){
        float pago = tc[0].aPagar();

        for (int i = 1; i < cantidadTC; i++){
            if (tc[i].aPagar() < pago){
                pago = tc[i].aPagar();
            }
        }

        return pago;
    }

    void mostrarMenorPagoTC(){
        cout << "Total a pagar del menor: " << calcularMenorPagoTC() << endl;
    }

    
    float calcularMayorPagoTC(){
        float pago = tc[0].aPagar();

        for (int i = 1; i < cantidadTC; i++){
            if (tc[i].aPagar() > pago){
                pago = tc[i].aPagar();
            }
        }

        return pago;
    }
    
    void mostrarMayorPagoTC(){
        cout << "Total a pagar del mayor: " << calcularMayorPagoTC() << endl;
    }

    void mostrarPagosTC(){
        mostrarMayorPagoTC();
        mostrarMenorPagoTC();
    }


    //

    void mostrarTCMenoresPago(){
        float pagoMenor = calcularMenorPagoTC();
        cout << "Trabajadores contratados con menor pago: " << pagoMenor << endl;

        for (int i = 0 ; i < cantidadTC ; i++){
            if (tc[i].aPagar() == pagoMenor){
                tc[i].mostrar();
            }
        }
    }


    //

    float calcularMenorPagoTD(){
        float pago = td[0].aPagar();

        for (int i = 1; i < cantidadTD; i++){
            if (td[i].aPagar() < pago){
                pago = td[i].aPagar();
            }
        }

        return pago;
    }

    void mostrarMenorPagoTD(){
        cout << "Total a pagar del menor: " << calcularMenorPagoTD() << endl;
    }

    float calcularMayorPagoTD(){
        float pago = td[0].aPagar();

        for (int i = 1; i < cantidadTD; i++){
            if (td[i].aPagar() > pago){
                pago = td[i].aPagar();
            }
        }

        return pago;
    }

    void mostrarMayorPagoTD(){
        cout << "Total a pagar del mayor: " << calcularMayorPagoTD() << endl;
    }

    void mostrarPagosTD(){
        mostrarMayorPagoTD();
        mostrarMenorPagoTD();
    }

    void mostrarTDMenoresPago(){
        float pagoMenor = calcularMenorPagoTD();
        cout << "Trabajadores destajo con menor pago: " << pagoMenor << endl;

        for (int i = 0 ; i < cantidadTD ; i++){
            if (td[i].aPagar() == pagoMenor){
                td[i].mostrar();
            }
        }
    }
};

int main(){
    Empresa e;
    e.leer();
    e.mostrarInformacion();
    e.mostrarTotalPagoEmpresa();
    // TC:
    e.mostrarPagosTC();
    e.mostrarTCMenoresPago();
    
    // Added en clases
    // TD:
    e.mostrarPagosTD();
    e.mostrarTDMenoresPago();

    return 0;
}