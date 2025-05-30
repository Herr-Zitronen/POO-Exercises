#include <iostream>
using namespace std;

class Punto {
private:
    float x, y;
public:
    // Constructor por defecto y parametrizado.

    Punto() : x(0), y(0) {}
    Punto(float x, float y) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
};

class Circulo : public Punto {
private:
    float r;
public:
    Circulo() : Punto(), r(0) {}
    Circulo(float x, float y, float radio) : Punto(x, y), r(radio) {}

    float getRadio() const { return r; }

    void setRadio(float radio) { r = radio; }
};

class Cilindro : public Circulo {
private:
    float h;
public:
    Cilindro() : Circulo(), h(0) {}
    Cilindro(float x, float y, float radio, float altura)
        : Circulo(x, y, radio), h(altura) {}
    
    
    float getAltura() const { return h; }
    void setAltura(float altura) { h = altura; }
};

int main(){

    return 0;
}