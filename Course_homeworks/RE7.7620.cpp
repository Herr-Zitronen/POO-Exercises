/*
3. Dado que el curso tiene una capacidad máxima de 40 estudiantes: 
¿Qué pasará si el usuario del sistema intenta ingresar 45 estudiantes? ¿Cómo se resolvería?

- Si el usuario intenta ingresar más de 40 estudiantes (es decir, más elementos de los que puede almacenar el arreglo),
el programa podría permitirlo, pero el comportamiento será indefinido y propenso a errores. 
Esto se debe a que acceder a índices fuera del límite del arreglo implica leer o escribir en zonas de memoria no asignadas 
formalmente al arreglo, lo que puede causar fallos.

- Para resolver este problema, dado que el curso solo puede tener un máximo de 40 estudiantes, se debe restringir 
el ingreso de datos a ese límite. Esto se puede lograr utilizando una estructura repetitiva que verifique la validez 
del número ingresado y solicite un nuevo valor en caso de que se exceda el máximo permitido.

Lógica para el ingreso:
    1. Pedir numero_estudiantes (input del usuario).
    2. Mientras (input > 40):
        2.1. Imprimir "La capacidad máxima es de 40. Ingrese un número válido de estudiantes."
        2.2. Pedir nuevamente el número.
    3. numero_estudiantes <- input; (asignar el valor validado al atributo numero_estudiantes).

*/

#include <iostream>
using namespace std;


class Estudiante {
    public:
    string nombre;
    string apellido;
    string codigo_estudiante;
    int asistencia; // entero (0 - 100)
    float nota_ciclo1;
    float nota_ciclo2;
    
    Estudiante(){ 
        nombre = apellido = codigo_estudiante =  "";
        nota_ciclo1 = nota_ciclo2 = 0;
        asistencia = 0;
    }

    void ingresar_datos(){
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "Código: ";
        cin >> codigo_estudiante;
        cout << "Nota primer ciclo: ";
        cin >> nota_ciclo1; 
        cout << "Nota segundo ciclo: ";
        cin >> nota_ciclo2;
        cout << "Porcentaje de asistencia (0-100): ";
        cin >> asistencia;
    }

    float calcular_promedio(){
        return (nota_ciclo1 + nota_ciclo2) / 2;
    }

    int clasificacion_estudiantes(){

        if (asistencia < 75) return -1;
        double promedio = calcular_promedio();

        if (promedio >= 7){
            return 1;
        } else if (promedio >= 4){
            return 0;
        } else{
            return -1;
        }
        
    }

    void mostrar_estudiante(){
        cout << "---------------------------" << endl;
        cout << "Estudiante " + nombre + " " + apellido + ".\nCódigo: " + codigo_estudiante << endl;
        cout << "Promedio: " << calcular_promedio() << endl;
        cout << "Asistencia: " << asistencia << "%" << endl;

        switch (clasificacion_estudiantes()) // el metodo se encarga de logica para decidir el estado del estudiante.
        {
        case 1:
            cout << "\nEstá APROBADO." << endl;
            break;
        case 0:
            cout << "\nEstá en RECUPERACIÓN." << endl;
            break;
        case -1:
            cout << "\nEstá REPROBADO." << endl;
            break;
        }
    }

    ~Estudiante(){
    }

};


class Curso {
    public: 
    string nombre_curso;
    char paralelo;
    int nivel;
    Estudiante estu[40];
    int numero_estudiantes;

    Curso(){
        nombre_curso = "";
        paralelo = ' ';
        numero_estudiantes = 0;
        nivel = 0;
    }

    void ingresar_datos(){
        cout << "Ingresar datos del curso" << endl;
        cout << "Curso: ";
        cin >> nombre_curso;
        cout << "Nivel: ";
        cin >> nivel;
        cout << "Paralelo: ";
        cin >> paralelo;
        cout << "Número de estudiantes (<= 40): ";
        cin >> numero_estudiantes;
    }

    // Se ingresan los datos de cada objeto Estudiante.
    void ingresar_datos_estudiants(){
        for (size_t i = 0; i < numero_estudiantes ; i++ ){
            cout << "Ingresar datos estudiante" << endl;
            estu[i].ingresar_datos();
        }
    }

// Muestra datos del curso, luego llama al metodo mostrar estudiante para 
// cada objeto Estudiante dentro de los estudiantes registrados en el curso.
    void mostrar_datos(){  
        cout << "******************************************" << endl;
        cout << "Curso: " << nombre_curso << "\t";
        cout << "Nivel: " << nivel << endl;
        cout << "Paralelo: " << paralelo << endl;
        cout << "ESTUDIANTES -> " << numero_estudiantes << endl;
        cout << "******************************************" << endl;

        for (size_t i = 0; i < numero_estudiantes ; i++){
            estu[i].mostrar_estudiante();
        } 

    }
    ~Curso(){
    }

};


int main(void){
    cout << " " << endl; // Por si la terminal se buguea.
    Curso curso;
    curso.ingresar_datos(); // Datos del curso.
    curso.ingresar_datos_estudiants(); // Datos de cada estudiante del curso ( y notas )
    curso.mostrar_datos(); 

    return 0; 
}