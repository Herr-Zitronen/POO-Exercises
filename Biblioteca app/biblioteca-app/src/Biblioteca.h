// Biblioteca.h
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "Libro.h"
#include "Cliente.h"

class Biblioteca {
private:
    std::vector<Libro*> catalogo; 
    std::vector<Cliente> usuario;

public:
    ~Biblioteca();

    void addUsuario();
    void addLibro();
    void mostrarUsuarios() const;
    void mostrarLibros() const;
    void buscarLibro() const;
    void ejecutarPrestamo();
    
private:
    std::string solicitarPista() const;
    void mostrarLibroEncontrado(int indice) const;
    bool solicitarRecursion() const;
    std::vector<int> ejecutarBusquedaLibro(std::vector<int> indices) const; 
    std::vector<int> indicesTotalesLibro() const;
}; 

#endif // BIBLIOTECA_H