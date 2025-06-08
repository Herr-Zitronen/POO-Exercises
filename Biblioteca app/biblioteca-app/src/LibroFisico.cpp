#include "LibroFisico.h"
#include <iostream>
using namespace std;

LibroFisico::LibroFisico() : Libro(), ubicacion("") {
    tipo = "Físico";
}

LibroFisico::LibroFisico(string _titulo, string _autor) : Libro(_titulo, _autor), ubicacion("") {
    tipo = "Físico";
}

void LibroFisico::pedirDatosEspecificos() {
    leer();
    std::cin.ignore();
    std::cout << "Ingrese ubicación física (estante): ";
    std::getline(std::cin, ubicacion);
}

void LibroFisico::mostrar() const {
    Libro::mostrar();
    std::cout << "Tipo: Libro Físico" << std::endl;
    std::cout << "Ubicación: " << ubicacion << std::endl;
    std::cout << "----------------" << std::endl;
}