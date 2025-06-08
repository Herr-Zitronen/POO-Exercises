#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

class Cliente {
private:
    std::string nombre;
    std::string id;

public:
    Cliente();
    void leer(int _id);
    void mostrar() const;
};

#endif // CLIENTE_H