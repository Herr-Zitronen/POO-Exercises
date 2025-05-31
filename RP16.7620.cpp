#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

class Punto {
private:
    float x, y;
public:
    Punto(float x, float y) : x(x), y(y) {}

    void leer() {
        cout << "Ingrese coordenada x: ";
        cin >> x;
        cout << "Ingrese coordenada y: ";
        cin >> y;
    }

    void mostrar() const {
        cout << "Punto (" << x << ", " << y << ")" << endl;
    }
};

class Circulo : public Punto {
private:
    float r;
public:
    Circulo(float x, float y, float r) : Punto(x, y), r(r) {}

    void leer() {
        Punto::leer();
        cout << "Ingrese el radio del círculo: ";
        cin >> r;
    }

    void mostrarRadio() const {
        cout << "Radio: " << r << endl;
    }

    void mostrarArea() const {
        cout << "Área del círculo: " << PI * r * r << endl;
    }

    float getRadio() const {
        return r;
    }

    void mostrar() const {
        Punto::mostrar();
        mostrarRadio();
        mostrarArea();
    }
};

class Cilindro : public Circulo {
private:
    float h;
public:
    Cilindro(float x, float y, float r, float h) : Circulo(x, y, r), h(h) {}

    void leer() {
        Circulo::leer();
        cout << "Ingrese la altura del cilindro: ";
        cin >> h;
    }

    void mostrarAltura() const {
        cout << "Altura: " << h << endl;
    }

    void mostrarVolumen() const {
        float radio = getRadio();
        float areaBase = PI * radio * radio;
        float volumen = areaBase * h;
        cout << "Volumen del cilindro: " << volumen << endl;
    }

    void mostrarArea() const{
        double radio = getRadio();
        double areaBase = PI * radio * radio;
        double areaLateral = 2 * PI * radio * h;
        double areaTotal = 2 * areaBase + areaLateral;
        cout << "Área total del cilindro: " << areaTotal << endl;
    }

    void mostrar() const {
        Circulo::mostrar();
        mostrarArea();
        mostrarAltura();
        mostrarVolumen();
    }
};

int main() {
    Cilindro cil(0.0, 0.0, 0.0, 0.0);
    cil.leer();
    cil.mostrar();

    return 0;
}
