#include <iostream>
using namespace std;


class Estudiante {
    public:
    string nombre;
    string apellido;
    string codigo_estudiante;
    
    float nota_ciclo1;
    float nota_ciclo2;
    
    Estudiante(){ 
        nombre = apellido = codigo_estudiante =  "";
        nota_ciclo1 = nota_ciclo2 = 0;
    }

    void ingresar_datos(){
//        cout << "Ingrese los datos del estudiante:" << endl;
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
    }

    float calcular_promedio(){
        return (nota_ciclo1 + nota_ciclo2) / 2;
    }

    int clasificacion_estudiantes(){
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
        cout << "--------------estudiante-------------" << endl;
        cout << "promedio: " << calcular_promedio();
        cout << "\nEstudiante " + nombre + " " + apellido + ".\nCódigo: " + codigo_estudiante << endl;
        switch (clasificacion_estudiantes())
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
    Estudiante estu[40];
    int numero_estudiantes;

    Curso(){
        nombre_curso = "";
        paralelo = ' ';
        numero_estudiantes = 0;
    }

    void ingresar_datos(){
        cout << "Ingresar datos del curso" << endl;
        cout << "Ingresar nombre: ";
        cin >> nombre_curso;
        cout << "Ingresar paralelo";
        cin >> paralelo;
        cout << "Ingresar numero de estudiantes";
        cin >> numero_estudiantes;
    }

    void ingresar_datos_estudiants(){
        for (size_t i = 0; i < numero_estudiantes ; i++ ){
            cout << "Ingresar datos estudiante" << endl;
            estu[i].ingresar_datos();
        }
    }

    // void ingresar_calificaciones(){
    //     cout << "numero estu: " << numero_estudiantes;
        
    //     for (size_t i = 0; i < numero_estudiantes ; i++ ){
    //         cout << "Ingresar calificaciones estudiante" << endl;
    //         estu[i].clasificacion_estudiantes();
    //     }
    // }

    void mostrar_datos(){
        cout << "Curso: " + nombre_curso << endl;
        cout << "Paralelo: " << paralelo << endl;
        cout << "ESTUDIANTES -> " << numero_estudiantes << endl;

        for (size_t i = 0; i < numero_estudiantes ; i++){
            estu[i].mostrar_estudiante();
        } 

    }


};


int main(void){
    cout << " " << endl;
    Curso curso;
    curso.ingresar_datos();
    curso.ingresar_datos_estudiants();
    curso.mostrar_datos();

    return 0; 
}