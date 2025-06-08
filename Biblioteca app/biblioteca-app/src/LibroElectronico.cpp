#include "LibroElectronico.h"
#include <iostream>
using namespace std;

LibroElectronico::LibroElectronico() : Libro(), formato(""), tamanoMB(0.0) {
    tipo = "Electrónico";
}

LibroElectronico::LibroElectronico(string _titulo, string _autor) : Libro(_titulo, _autor), formato(""), tamanoMB(0.0) {
    tipo = "Electrónico";
}

void LibroElectronico::pedirDatosEspecificos() {
    leer();
    std::cout << "Ingrese formato del libro (PDF, EPUB, etc.): ";
    std::cin >> formato;
    std::cout << "Ingrese tamaño en MB: ";
    std::cin >> tamanoMB;
}

void LibroElectronico::mostrar() const {
    Libro::mostrar();
    std::cout << "Tipo: Libro Electrónico" << std::endl;
    std::cout << "Formato: " << formato << std::endl;
    std::cout << "Tamaño: " << tamanoMB << " MB" << std::endl;
    std::cout << "----------------" << std::endl;
}