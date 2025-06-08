#include <iostream>
#include <vector>
#include "Biblioteca.h"
#include "LibroFisico.h"
#include "LibroElectronico.h"
using namespace std;


Biblioteca::~Biblioteca(){
    for (auto ptr : catalogo) {
        delete ptr;
    }
}

void Biblioteca::addUsuario() {
    usuario.emplace_back();
    usuario.back().leer(usuario.size());
}

void Biblioteca::addLibro() {
    string titulo, autor;
    
    cout << "Ingrese título del libro: ";
    cin.ignore();
    getline(cin, titulo);
    
    cout << "Ingrese autor del libro: ";
    getline(cin, autor);
    
    cout << "¿Qué tipo de libro desea crear?" << endl;
    cout << "1. Libro Físico" << endl;
    cout << "2. Libro Electrónico" << endl;
    int opcion;
    cin >> opcion;
    
    Libro* nuevoLibro = nullptr;
    
    if (opcion == 1) {
        nuevoLibro = new LibroFisico(titulo, autor);
    } else if (opcion == 2) {
        nuevoLibro = new LibroElectronico(titulo, autor);
    } else {
        cout << "Opción no válida. No se ha creado el libro." << endl;
        return;
    }
    
    nuevoLibro->pedirDatosEspecificos();
    catalogo.push_back(nuevoLibro);
}

void Biblioteca::mostrarUsuarios() const {
    for (const Cliente& user : usuario) {
        user.mostrar();
    }
}

void Biblioteca::mostrarLibros() const {
    for (const Libro* libro : catalogo) {
        libro->mostrar();
    }
}

string Biblioteca::solicitarPista() const {
    string pista;
    cout << "Ingrese una pista (palabra) del titulo del libro a buscar: ";
    cin >> pista;
    return pista;
}

void Biblioteca::mostrarLibroEncontrado(int indice) const {
    cout << "Libro: " << catalogo[indice]->getTitulo() << endl;
    cout << "Autor: " << catalogo[indice]->getAutor() << endl;
    cout << "Tipo: " << catalogo[indice]->getTipo() << endl;
}

bool Biblioteca::solicitarRecursion() const {
    bool res;
    cout << "Desea seguir buscando (filtrar)? (0. No / 1. Si): ";
    cin >> res;
    return res;
}

vector<int> Biblioteca::ejecutarBusquedaLibro(vector<int> indices) const { 
    vector<int> posiciones; 
    string pista = solicitarPista();

    for (int nindice : indices) {
        if (catalogo[nindice]->getTitulo().find(pista) != string::npos) {
            posiciones.push_back(nindice);
            mostrarLibroEncontrado(nindice);
        }
    }
    
    bool solicitudRecursion = solicitarRecursion();
    
    if (solicitudRecursion && posiciones.size() > 1) {
        return ejecutarBusquedaLibro(posiciones);
    } else {
        return posiciones;
    }
}

vector<int> Biblioteca::indicesTotalesLibro() const {
    vector<int> indices;
    for (size_t i = 0; i < catalogo.size(); i++) {
        indices.push_back(i);
    }
    return indices;
}

void Biblioteca::buscarLibro() const {
    if (catalogo.empty()) {
        cout << "No hay libros en el catálogo." << endl;
        return;
    }
    
    vector<int> lenghtArray = indicesTotalesLibro();
    vector<int> posiciones = ejecutarBusquedaLibro(lenghtArray);

    if (!posiciones.empty()) {
        cout << "Se encontraron " << posiciones.size() << " libro/s:" << endl;
        for (int pos : posiciones) {
            catalogo[pos]->mostrar();
        }
    } else {
        cout << "No se encontraron libros." << endl;
    }
}

void Biblioteca::ejecutarPrestamo() {
    // Implementar lógica para prestar libros a usuarios
}