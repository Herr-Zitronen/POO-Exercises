#include <iostream>
#include <string>



class Libro{
public:

Libro(std::string);

void establecerTitulo(std::string);

public:
std::string titulo;

};

Libro::Libro(std::string nombre){
    establecerTitulo(nombre);

}

void Libro::establecerTitulo(std::string nombre){
    titulo = nombre;
}

int main(){
    Libro l("Hello");
    std::cout << "Nombre del libro: " << l.titulo;
}