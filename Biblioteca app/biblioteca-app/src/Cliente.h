#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
    string id;

public:
    Cliente();
    void leer(int _id);
    void mostrar() const;
};

#endif // CLIENTE_H