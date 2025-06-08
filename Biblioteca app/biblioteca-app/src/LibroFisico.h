// LibroFisico.h
#ifndef LIBROFISICO_H
#define LIBROFISICO_H

#include "Libro.h"

class LibroFisico : public Libro {
private:
    std::string ubicacion;

public:
    LibroFisico();
    LibroFisico(std::string _titulo, std::string _autor);
    
    void pedirDatosEspecificos() override;
    void mostrar() const override;
};

#endif // LIBROFISICO_H