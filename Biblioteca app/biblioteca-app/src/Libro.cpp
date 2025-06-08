#include "Libro.h"
#include <iostream>
#include <string>
using namespace std;

Libro::Libro() : titulo(""), autor(""), prestado(false), tipo(""), numeroDePaginas(0) {}

Libro::Libro(string _titulo, string _autor) : titulo(_titulo), autor(_autor), prestado(false), tipo("") {}

string Libro::getTitulo() const {
    return titulo;
}

string Libro::getAutor() const {
    return autor;
}

bool Libro::getPrestado() const {
    return prestado;
}

string Libro::getTipo() const {
    return tipo;
}

void Libro::setTipo(string _tipo) {
    tipo = _tipo;
}

void Libro::leer() {
    std::cout << "Ingrese título del libro: ";
    std::cin.ignore(); 
    std::getline(std::cin, titulo); 
    std::cout << "Ingrese autor del libro: ";
    std::getline(std::cin, autor);  
    std::cout << "Ingrese número de páginas: ";
    std::cin >> numeroDePaginas;
}

void Libro::mostrar() const {
    std::cout << "-------***---------" << std::endl;
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Autor: " << autor << std::endl;
    std::cout << "Número de Paginas: " << numeroDePaginas << std::endl;
    std::cout << (prestado ? "Prestado" : "Disponible") << std::endl;
}

void Libro::pedirDatosEspecificos() {}

void Libro::cambiarEstadoPrestamo() {
    prestado = !prestado;
}