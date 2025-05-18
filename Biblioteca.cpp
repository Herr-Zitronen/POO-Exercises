/*
Cambios de v4: 
- Se añadió la recursión en el método ejecutarBusquedaLibro().
    - Se añadieron metodos para cumplir con la modularización
- No se usa el size del array. Sino que se almacenan todos los indices con el metodo indicesTotales()
    y se utiliza ese parámetro para inicar con la busqueda. En cada ciclo recursivo, se pasa como argumento
    el vector Posiciones que contiene los indices seleccionados. 
- El centinela de la recursión es la decisión del usuario para terminar la busqueda
    o si el vector Posiciones solo contiene un elemento, lo que significa que ya no hay
    más que buscar.

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Libro {
    string titulo;
    string autor;
    bool prestado;

    public:
    Libro(){
        titulo = autor = "";
        prestado = false;
    }

    string getTitulo() {return titulo;}
    string getAutor() {return autor;}

    void ingresarLibro(){
        cout << "Ingrese título del libro: ";
        cin >> titulo; //getline permite guardar con espacios
        cout << "Ingrese autor del libro: ";
        cin >> autor;  
    }

    void mostrar(){
        cout << "-------***---------" << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << (prestado ? "Prestado" : "Disponible") << endl;
        // if (prestado) {cout << "prestado"} else "Disponible"; 

        cout << "----------------" << endl;
    }

    void cambiarEstadoPrestamo(){
        prestado = !prestado;
    }

};

class Cliente {
    string nombre;
    int id;
    //vector<Libro*> libros_prestados;

    public:
    Cliente(){
        this->nombre = "";
        this->id = 0;
    }

    void mostrar(){ 
        cout << "-------***---------" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "ID: " << id << endl;
        cout << "----------------" << endl;
    }

    void ingresarCliente(int nid){
        id = nid;
        cout << "Ingrese el nombre: ";
        cin >> nombre;
    }

};

class Biblioteca{
    vector<Libro> catalogo;
    vector<Cliente> usuario;

    public:
    void addUsuario(){
        int size = usuario.size(); // Tamaño del vector (inicial 0) == posicion del elemento.
        usuario.emplace_back();
        usuario.at(size).ingresarCliente(size + 1);
    }

    void addLibro(){  
        int size = catalogo.size();            
        catalogo.emplace_back(); // emplace_back llama directamente al constructor para std::vector Class.
        
        catalogo.at(size).ingresarLibro();

    }

    void mostrarUsuarios(){
        for (Cliente user : usuario){
            user.mostrar();
        }
    }

    void mostrarLibros(){
        for (Libro libro : catalogo){
            libro.mostrar();
        }
    }

    string solicitarPista(){
        string pista;
        cout << "Ingrese una pista (palabra) del titulo del libro a buscar." << endl;
        cin >> pista;
        return pista;
    }

    // vector<int> ejecutarBusquedaLibro(){ 
    //     vector<int> posiciones; // almacena todas las posiciones encontradas
    //     string pista = solicitarPista();

    //     for (size_t i = 0; i < catalogo.size(); i++) {
    //         if (catalogo[i].getTitulo().find(pista) != string::npos) { 
    //             // npos: sin posicion.

    //             posiciones.push_back(i);
    //         }
    //     }

    //     return posiciones; 
    // }

    void mostrarLibroEncontrado(int indice){
        cout << "Libro: " << catalogo[indice].getTitulo() << endl;
        cout << "Autor: " << catalogo[indice].getAutor() << endl;
    }

    bool solicitarRecursion(){
        bool res;
        cout << "Desea seguir buscando (filtrar)? (0. No / 1. Si): ";
        cin >> res;

        return res;
    }

    vector<int> ejecutarBusquedaLibro(vector<int> indices){ 
        vector<int> posiciones; 
        string pista = solicitarPista();

        for (int nindice : indices){
            if (catalogo[nindice].getTitulo().find(pista) != string::npos){
                posiciones.push_back(nindice);
                mostrarLibroEncontrado(nindice);
            }
        }

        bool solicitudRecursion = solicitarRecursion();
        
        if (solicitudRecursion && posiciones.size() != 1){
            return ejecutarBusquedaLibro(posiciones);
        } else {
            return posiciones;
        }
    }

    /* ERRORRRRR (Solucion en el caso de no tener la longitud, reto de prueba)
    La solucion es ineficiente, pero para evitar el bucle infinito, se podria utilizar
    algún tipo de método para la evaluacion condicional. O añadir en el codigo de abajo la
    condición extra para terminar la iteración.

    for (size_t i = 0; i < catalogo.size() && ...; i = nindice) {
            if (catalogo[i].getTitulo().find(pista) != string::npos) { 
                posiciones.push_back(i);
                mostrarLibroEncontrado(i);
            }
        }
    
    }
    
    */

    vector<int> indicesTotalesLibro(){
        vector<int> indices;
        for (int i = 0; i < catalogo.size() ; i++){
            indices.push_back(i);
        }
        return indices;
    }

    void buscarLibro(){
        vector<int> lenghtArray = indicesTotalesLibro();
        vector<int> posiciones = ejecutarBusquedaLibro(lenghtArray);

        if (!posiciones.empty()) {
            cout << "Se encontraron " << posiciones.size() << " libro/s:" << endl;
            for (int pos : posiciones) {
                catalogo[pos].mostrar();
            }
        } else {
            cout << "No se encontraron libros." << endl;
        }
    }

    void ejecutarPrestamo(){};
    // al final de ejecutar prestamo: Libro[i].cambiarprestamo(); 

};

class Interfaz{
    Biblioteca biblo;

    void mostrarMenuAcciones(){
        cout << "Menu:" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Mostrar Libros" << endl;
        cout << "2. Mostrar Usuarios" << endl;
        cout << "3. Añadir Usuarios" << endl;
        cout << "4. Añadir Libros" << endl;
        cout << "5. Buscar Libro" << endl;
        cout << "6. Prestar Libro a Usuario" << endl;
    }

    int pedirAccion(){
        int op;
        cout << "Ingrese una opcion: ";
        cin >> op;
        
        return op;
    }

    void ejecutarAccion(){
        int op = pedirAccion();

        while (op != 0){
            switch (op)
            {
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
            op = pedirAccion();
        }

        cout << "Saliendo del programa.";
    }

    public:
    void ejecutar(){
        mostrarMenuAcciones();
        ejecutarAccion();
    }

};


int main(void){
    Interfaz interfaz;
    interfaz.ejecutar();
    return 0;
}