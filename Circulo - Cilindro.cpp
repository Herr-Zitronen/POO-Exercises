#include <iostream>
using namespace std;

class Punto {
private:
    float x, y;
public:
    Punto(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
};

class Circulo : public Punto {
private:
    float radio;
public:
    Circulo(float x = 0, float y = 0, float radio = 0) : Punto(x, y), radio(radio) {}

    float getRadio() const { return radio; }

    void setRadio(float radio) { this->radio = radio; }
};

class Cilindro : public Circulo {
private:
    float altura;
public:

    Cilindro(float x = 0, float y = 0, float radio = 0, float altura = 0)
        : Circulo(x, y, radio), altura(altura) {}
    
    
    float getAltura() const { return altura; }
    void setAltura(float altura) { this->altura = altura; }
};

int main(){

    return 0;
}