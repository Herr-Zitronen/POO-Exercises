#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente() : nombre(""), id("") {}

void Cliente::leer(int _id) {
    id = to_string(_id);
    cout << "Nombre: ";
    cin >> nombre;
}

void Cliente::mostrar() const {
    cout << "Nombre: " << nombre << "\nID: " << id << endl;
}