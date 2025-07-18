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


    float calcular_menor_nota(){  
        if (numero_estudiantes == 0) {
            cout << "No hay estudiantes registrados." << endl;
            return -1; 
        }

        float nota_menor = estu[0].calcular_promedio();

        for (size_t i = 1; i < numero_estudiantes ; i ++){
            float promedio_actual = estu[i].calcular_promedio();

            if (nota_menor > promedio_actual){
                nota_menor = promedio_actual;
            }
        }
        return nota_menor;
    }

    float calcular_mayor_nota(){  
        if (numero_estudiantes == 0) {
            cout << "No hay estudiantes registrados." << endl;
            return -1; 
        }

        float nota_mayor = estu[0].calcular_promedio();

        for (size_t i = 1; i < numero_estudiantes ; i ++){
            float promedio_actual = estu[i].calcular_promedio();

            if (nota_mayor < promedio_actual){
                nota_mayor = promedio_actual;
            }
        }
        return nota_mayor;
    }

    void mostrar_datos() {
    cout << "*******************************************" << endl;

    if (numero_estudiantes == 0) {
        cout << "No hay estudiantes registrados en el curso." << endl;
    } else {
        cout << "La menor nota es: " << calcular_menor_nota() << endl;
        cout << "La mayor nota es: " << calcular_mayor_nota() << endl;
    }

    cout << "*******************************************" << endl;
    }

    
    ~Curso(){
    }

};


int main(void){
    cout << " " << endl; // 
    Curso curso;
    curso.ingresar_datos(); // Datos del curso.
    curso.ingresar_datos_estudiants(); // Datos de cada estudiante del curso ( notas )

    curso.mostrar_datos();

    return 0; 
}