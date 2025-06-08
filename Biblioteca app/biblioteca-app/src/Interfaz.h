#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "Biblioteca.h"

class Interfaz {
private:
    Biblioteca biblo;

    void mostrarMenuAcciones() const;
    int pedirAccion() const;
    void ejecutarAccion();

public:
    void ejecutar();
};

#endif // INTERFAZ_H