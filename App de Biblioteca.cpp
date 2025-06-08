#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cliente {
private:
    string nombre, id;
public:

    Cliente() : nombre(""), id("") {}

    void leer(int _id){
        id = to_string(_id);
        cout << "Nombre: ";
        cin >> nombre;
    }
    
    void mostrar() const {
        cout << "Nombre: " << nombre << "\nID: " << id << endl;
    }
};


class Libro {
protected:
// getline() para crear el puntero de objeto Libro (nuevoLibro)

    string titulo;
    string autor;
    bool prestado;
    string tipo; 
    int numeroDePaginas;
public:
    Libro() : titulo(""), autor(""), prestado(false), tipo(""), numeroDePaginas(0) {}
    
    Libro(string _titulo, string _autor) : titulo(_titulo), autor(_autor), prestado(false), tipo("") {}
    
    string getTitulo() const {return titulo;}
    string getAutor() const {return autor;}
    bool getPrestado() const {return prestado;}
    string getTipo() const {return tipo;}

    void setTipo(string _tipo) {
        tipo = _tipo;
    }

    // Uso de virtual para sobreesacribir estos metodos

    virtual void leer(){
        cout << "Ingrese título del libro: ";
        cin.ignore(); 
        getline(cin, titulo); 
        cout << "Ingrese autor del libro: ";
        getline(cin, autor);  
        cout << "Ingrese número de páginas: ";
        cin >> numeroDePaginas;
    }

    virtual void mostrar() const {
        cout << "-------***---------" << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Número de Paginas: " << numeroDePaginas << endl;
        cout << (prestado ? "Prestado" : "Disponible") << endl;
    }
    
    virtual void pedirDatosEspecificos() {} 
    // Esto es necesario por el trabajo con el puntero Libro*, donde este accede al metodo de Libro
    // Pues este metodo esta con override para que Libro* acceda al metodo de acuerdo a la asginacion new.
    
    
    // Método debe ser protected.
    void cambiarEstadoPrestamo(){
        prestado = !prestado;
    }
};


class LibroFisico : public Libro {
private:
    string ubicacion;
public:
    LibroFisico() : Libro(), ubicacion("") {tipo = "Fisico";}
    
    LibroFisico(string _titulo, string _autor) : Libro(_titulo, _autor), ubicacion("") {tipo = "Físico";}
    
    void pedirDatosEspecificos() override {
        leer();
        cin.ignore();
        cout << "Ingrese ubicación física (estante): ";
        getline(cin, ubicacion);
    }
    
    void mostrar() const override {
        Libro::mostrar();
        cout << "Tipo: Libro Físico" << endl;
        cout << "Ubicación: " << ubicacion << endl;
        cout << "----------------" << endl;
    }
};


class LibroElectronico : public Libro {
private:
    string formato;
    float tamanoMB;

public:
    LibroElectronico() : Libro(), formato(""), tamanoMB(0.0) {
        tipo = "Electrónico";
    }
    
    LibroElectronico(string _titulo, string _autor) : Libro(_titulo, _autor), formato(""), tamanoMB(0.0) {
        tipo = "Electrónico";
    }
    
    void pedirDatosEspecificos() override {
        leer();
        cout << "Ingrese formato del libro (PDF, EPUB, etc.): ";
        cin >> formato;
        cout << "Ingrese tamaño en MB: ";
        cin >> tamanoMB;
    }
    
    void mostrar() const override {
        Libro::mostrar();
        cout << "Tipo: Libro Electrónico" << endl;
        cout << "Formato: " << formato << endl;
        cout << "Tamaño: " << tamanoMB << " MB" << endl;
        cout << "----------------" << endl;
    }
};

class Biblioteca {
private:
    vector<Libro*> catalogo; 
    vector<Cliente> usuario;

public:
    ~Biblioteca() {
        for (auto ptr : catalogo) {
            delete ptr;
        }
    }

// Este destructor (~Biblioteca) se encarga de liberar la memoria dinámica
// que fue asignada a los objetos apuntados por los punteros almacenados en 'catalogo'.
// El ciclo for recorre cada puntero y usa 'delete' para liberar la memoria de cada objeto.
// Esto previene fugas de memoria (memory leaks), asegurando que toda la memoria reservada
// dinámicamente se libere cuando el objeto Biblioteca se destruya.

    void addUsuario() {
        // int size = usuario.size();
        // usuario.emplace_back();
        // usuario.at(size).leer(size + 1);
        usuario.emplace_back();
        usuario.back().leer(usuario.size());
    }

    void addLibro() {
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
        // puntero vacio.
        // Si no se inicializa, podria causar problemas al intentar al acceder.
        
        if (opcion == 1) { // no se realiza copia alguna. Se crea un nuevo objeto.
            nuevoLibro = new LibroFisico(titulo, autor);
            // nuevoLibro = new LibroFisico(); 
            // nuevoLibro->leer(); 
        } else if (opcion == 2) {
            nuevoLibro = new LibroElectronico(titulo, autor);
        } else {
            cout << "Opción no válida. No se ha creado el libro." << endl;
            return; // bye.
        }
        
        nuevoLibro->pedirDatosEspecificos();
        catalogo.push_back(nuevoLibro);
    }

    void mostrarUsuarios() const {
        for (const Cliente& user : usuario) {
            user.mostrar();
        }
    }

    void mostrarLibros() const {
        for (const Libro* libro : catalogo) {
            libro->mostrar();
        }
    }

    string solicitarPista() const {
        string pista;
        cout << "Ingrese una pista (palabra) del titulo del libro a buscar: ";
        cin >> pista;
        return pista;
    }

    void mostrarLibroEncontrado(int indice) const {
        cout << "Libro: " << catalogo[indice]->getTitulo() << endl;
        cout << "Autor: " << catalogo[indice]->getAutor() << endl;
        cout << "Tipo: " << catalogo[indice]->getTipo() << endl;
    }

    bool solicitarRecursion() const {
        bool res;
        cout << "Desea seguir buscando (filtrar)? (0. No / 1. Si): ";
        cin >> res;
        return res;
    }

    vector<int> ejecutarBusquedaLibro(vector<int> indices) const { 
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

    vector<int> indicesTotalesLibro() const {
        vector<int> indices;
        for (int i = 0; i < catalogo.size(); i++) {
            indices.push_back(i);
        }
        return indices;
    }

    void buscarLibro() const {
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

    void ejecutarPrestamo() {
    }
};

class Interfaz {
private:
    Biblioteca biblo;

    void mostrarMenuAcciones() const {
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

    int pedirAccion() const {
        int op;
        cout << "\nIngrese una opcion: ";
        cin >> op;
        return op;
    }

    void ejecutarAccion() {
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

public:
    void ejecutar() {
        mostrarMenuAcciones();
        ejecutarAccion();
    }
};

int main(void) {
    Interfaz interfaz;
    interfaz.ejecutar();
    return 0;
}