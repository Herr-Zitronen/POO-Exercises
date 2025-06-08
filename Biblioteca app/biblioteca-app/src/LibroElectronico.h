// LibroElectronico.h
#ifndef LIBRO_ELECTRONICO_H
#define LIBRO_ELECTRONICO_H

#include "Libro.h"

class LibroElectronico : public Libro {
private:
    std::string formato;
    float tamanoMB;

public:
    LibroElectronico();
    LibroElectronico(std::string _titulo, std::string _autor);
    
    void pedirDatosEspecificos() override;
    void mostrar() const override;
};

#endif // LIBRO_ELECTRONICO_H