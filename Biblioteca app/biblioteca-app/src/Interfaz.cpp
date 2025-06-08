#include <iostream>
#include "Interfaz.h"
#include "Biblioteca.h"

using namespace std;

void Interfaz::mostrarMenuAcciones() const {
    cout << "\n=== SISTEMA DE BIBLIOTECA ===" << endl;
    cout << "Menu:" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Mostrar Libros" << endl;
    cout << "2. Mostrar Usuarios" << endl;
    cout << "3. Añadir Usuarios" << endl;
    cout << "4. Añadir Libros" << endl;
    cout << "5. Buscar Libro" << endl;
    cout << "6. Prestar Libro a Usuario" << endl;
    cout << "=========================" << endl;
}

int Interfaz::pedirAccion() const {
    int op;
    cout << "\nIngrese una opcion: ";
    cin >> op;
    return op;
}

void Interfaz::ejecutarAccion() {
    int op = pedirAccion();

    while (op != 0) {
        switch (op) {
        case 1:
            biblo.mostrarLibros();
            break;
        case 2:
            biblo.mostrarUsuarios();
            break;
        case 3:
            biblo.addUsuario();
            break;
        case 4:
            biblo.addLibro();
            break;
        case 5:
            biblo.buscarLibro();
            break;
        case 6:
            biblo.ejecutarPrestamo();
            break;
        default:
            cout << "Opción no valida." << endl;
            break;
        }

        mostrarMenuAcciones();
        op = pedirAccion();
    }

    cout << "Saliendo del programa." << endl;
}

void Interfaz::ejecutar() {
    mostrarMenuAcciones();
    ejecutarAccion();
}