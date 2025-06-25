#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Punto {
    private:
    float x, y;
    string id;

    public:
    Punto() : x(0), y(0), id("") {}


    virtual void leer(){
        cout << "Ingrese ID ";
        cin >> id;
        cout << "Ingrese x: ";
        cin >> x;
        cout << "Ingrese y: ";
        cin >> y;
    }

    int getX(){return x;}
    int getY(){return y;}
    string getID(){return id;}

    void setX(int _x){
        x = _x;
    }

    void setY(int _y){
        y = _y;
    }

    virtual void mostrar(){
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
    }

    int distanciaAlOrigen(){return sqrt(x * x * y * y);}

    virtual int getTipo(){return 0;}

};

class Circulo : public Punto {
    private:
    float r;

    public:
    Circulo() : Punto(), r(0) {}

    void leer(){
        Punto::leer();
        cout << "Ingrese el radio: ";
        cin >> r;
    }

    int getRadio(){
        return r;
    }

    void setRadio(int _r){
        r = _r;
    }

    void mostrar(){
        Punto::mostrar();
        cout << "Radio: " << r << endl;
    }

    virtual int getTipo(){return 1;}
};

class Cilindro : public Circulo{
    private:
    float h;

    public:
    Cilindro() : Circulo(), h(0) {}

    void leer(){
        Circulo::leer();
        cout << "Ingrese la altura: ";
        cin >> h;
    }

    float calcularVolumen(){
        return 3.1415 * getRadio() * getRadio() * h;
    }

    float getVolumen(){
        return calcularVolumen();
    }

    void mostrar(){
        Circulo::mostrar();
        cout  << "Altura: " << h << endl;
    }

    virtual int getTipo(){return 2;}
};

class Figura {
    private:
    Punto* fig[100];
    int numFig;

    public: 
    Figura() : numFig(0) {}

    void leer(){
        cout << "Cantidad de figuras: ";
        cin >> numFig;
        cout << "Ingrese los datos de la figura: " << endl;
        leerFig();
    }

    void mostrar(){
        cout << "MOSTRAR DATOS DE LAS FIGURAS: " << endl;
        int tipo;

        for (int i = 0; i < numFig ; i++){
            cout << "Fig " << i + 1 << endl;

            tipo = fig[i]->getTipo();

            while (tipo != 0 && tipo != 1 && tipo != 2) {
                cout << "Error de opcion. Ingrese nuevamente: " << endl;
                cin >> tipo;
            }

            if (tipo == 0){
                fig[i]->mostrar();
            } else if (tipo == 1){
                Circulo* ptr = (Circulo*) fig[i];
                ptr->mostrar();
            } else{
                Cilindro* ptr = (Cilindro*) fig[i];
                ptr->mostrar();
            }

            cout << "-----------------------" << endl;
        }
    }

    void agregar(){
        cout << "AGREGAR NUEVA FIGURA" << endl;
        int opcion = seleccionarFig();

        if (numFig < 100){
            fig[numFig++] = leerFig(opcion);
        }
    }

    void mostrarFigMasCercaDelOrigen(){
        cout << "FIGURAS MAS CERCANAS AL ORIGEN" << endl;
        vector<int> posiciones = buscarFigMasCercanasAlOrigen();

        for (int pos : posiciones){
            cout << "===================" << endl;
            fig[pos]->mostrar();
            cout << "===================" << endl;
        }
    }

    void eliminarPorID(){
        cout << "ELIMINAR FIGURA POR ID" << endl;
        int pos = buscarFigPorID();

        if (pos >= 0 && pos < numFig){
            delete fig[pos];

            for (int i = pos; i < numFig - 1; i++){
                fig[i] = fig[i + 1];
            }

            numFig--;
            cout << "Figura eliminada." << endl;
        } else {
            cout << "Figura no encontrada." << endl;
        }
    }


    ~Figura(){ // is correct if i have capacity atribute for the pointers saved?
        for (int i = 0; i < numFig; i++){
            delete fig[i];
        }
    }

    
    private:

    int buscarFigPorID(){
        string id = solicitarValor("id a buscar: ");
        int i = 0;
        int result = -1;

        while (i < numFig && result == -1){
            if (fig[i]->getID() == id){
                result = i;
            }

            i++;
        }

        return result;

    }

    float calcularMenorDistancia(){
        float menorDistancia = fig[0]->distanciaAlOrigen();

        for (int i = 1; i < numFig ; i++){
            if (fig[i]->distanciaAlOrigen() < menorDistancia){
                menorDistancia = fig[i]->distanciaAlOrigen();
            }
        }

        return menorDistancia;
    }

    vector<int> buscarFigMasCercanasAlOrigen(){
        float menorDistancia = calcularMenorDistancia();
        vector<int> posiciones;

        for (int i = 0; i < numFig ; i++){
            if (fig[i]->distanciaAlOrigen() == menorDistancia){
                posiciones.push_back(i);
            }
        }

        return posiciones;
    }

    Punto* leerFig(int opcion){
        Punto* ptr;

        if (opcion == 1){
            ptr = new Circulo();
        } else if (opcion == 2){
            ptr = new Cilindro();
        } else{
            ptr = new Punto();
        }

        ptr->leer();
        return ptr;

    }

    void leerFig(){
        int opcion;

        for (int i = 0; i < numFig; i++){
            
            opcion = seleccionarFig();

            if (opcion == 1){
                fig[i] = new Circulo();
            } else if (opcion == 2){
                fig[i] = new Cilindro();
            } else{
                fig[i] = new Punto();
            }

            fig[i] ->leer();
        }
    }

    int seleccionarFig(){
        cout << "Punto creado" << endl;
        cout << "Desea hacer de esta figura un circulo o en un cilindro?";
        cout << "\n1. Circulo, 2. Cilindro, 3. No, gracias." << endl;

        int opcion = stoi(solicitarValor("opcion: "));

        while (opcion != 1 && opcion != 2 && opcion != 3) {
            cout << "Error de opcion, no se creo el objeto.\nIngrese nuevamente: ";
            cin >> opcion;
        }
        
        return opcion;
    }

    string solicitarValor(string mensaje){
        string valor;
        cout << "Ingrese " + mensaje;
        cin >> valor;
        return valor;
    }

};

int main(){
    // [ \text{distancia} = \sqrt{x2} ]

    Figura figs;

    // a.
    figs.leer();
    // b. 
    figs.mostrar();
    // c.
    figs.mostrarFigMasCercaDelOrigen();
    // d.
    figs.agregar();
    // e.
    figs.eliminarPorID();


}