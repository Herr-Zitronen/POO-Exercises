#include <iostream>
#include <vector>
using namespace std;

class Punto {
private:
    int x, y;

public:
    Punto() : x(0), y(0) {}

    void leer() {
        cout << "Ingrese coordenada x: ";
        cin >> x;
        cout << "Ingrese coordenada y: ";
        cin >> y;
    }

    int getX() { return x; }
    int getY() { return y; }

    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }

    void mostrar() {
        cout << "X: " << x << ", Y: " << y << endl;
    }
};

class Circulo : public Punto {
private:
    int r;

public:
    Circulo() : Punto(), r(0) {}

    void leer() {
        Punto::leer();
        cout << "Ingrese radio: ";
        cin >> r;
    }

    int getRadio() { return r; }

    void setRadio(int _r) { r = _r; }

    void mostrar() {
        Punto::mostrar();
        cout << "Radio: " << r << endl;
    }
};

class Cilindro : public Circulo {
private:
    int h;

public:
    Cilindro() : Circulo(), h(0) {}

    void leer() {
        Circulo::leer();
        cout << "Ingrese altura: ";
        cin >> h;
    }

    float calcularVolumen() {
        return 3.1415 * getRadio() * getRadio() * h;
    }

    float getVolumen() { return calcularVolumen(); }

    void mostrar() {
        Circulo::mostrar();
        cout << "Altura: " << h << endl;
        cout << "Volumen: " << calcularVolumen() << endl;
    }
};

class Figura {
private:
    int numCil;
    vector<Cilindro> cil;

public:
    Figura() : numCil(0) {}

    void leerDatos() {
        do {
            cout << "Ingrese el número de cilindros (mayor que 0): ";
            cin >> numCil;
            if (numCil <= 0) {
                cout << "El número de cilindros debe ser mayor que 0. Intente nuevamente." << endl;
            }
        } while (numCil <= 0);

        cil.resize(numCil); // Redimensionar el vector.
    }

    void leerCilindros() {
        for (int i = 0; i < numCil; i++) {
            cout << "\nCilindro " << i + 1 << ":" << endl;
            cil[i].leer();
        }
    }

    void mostrarCilindros() {
        cout << "\n=== Datos de los Cilindros ===" << endl;

        for (int i = 0; i < numCil; i++) {
            cout << "\nCilindro " << i + 1 << ":" << endl;
            cil[i].mostrar();
        }
    }

    int solicitarVolumen() {
        int volumen;

        do {
            cout << "Ingrese un valor de volumen (> 0): ";
            cin >> volumen;
            if (volumen <= 0) {
                cout << "El volumen debe ser mayor que 0. Intente nuevamente." << endl;
            }
        } while (volumen <= 0);
        return volumen;
    }

    vector<int> seleccionPorVolumen() {
        vector<int> pos;
        int volumenUser = solicitarVolumen();

        for (int i = 0; i < numCil; i++) {
            if (cil[i].getVolumen() < volumenUser) {
                pos.push_back(i);
            }
        }
        return pos;
    }

    void mostrarPorVolumen() {
        vector<int> posiciones = seleccionPorVolumen();
        
        if (posiciones.empty()) {
            cout << "No hay cilindros con volumen menor al valor ingresado." << endl;
        } else {
            cout << "\n===Cilindros con volumen menor al valor ingresado===" << endl;

            for (int pos : posiciones) {
                cout << "\nCilindro " << pos + 1 << ":" << endl;
                cil[pos].mostrar();
            }
        }
    }
};

int main() {
    Figura fig;
    fig.leerDatos();
    fig.leerCilindros();
    fig.mostrarCilindros();
    fig.mostrarPorVolumen();

    return 0;
}