// Libro.h
#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>

class Libro {
protected:
    std::string titulo;
    std::string autor;
    bool prestado;
    std::string tipo; 
    int numeroDePaginas;

public:
    Libro();
    Libro(std::string _titulo, std::string _autor);
    
    std::string getTitulo() const;
    std::string getAutor() const;
    bool getPrestado() const;
    std::string getTipo() const;

    void setTipo(std::string _tipo);
    
    virtual void leer();
    virtual void mostrar() const;
    virtual void pedirDatosEspecificos();
    void cambiarEstadoPrestamo();
    virtual ~Libro() {}
};

#endif // LIBRO_H