// RP5: Curso con Encapsulamiento

#include <iostream>
using namespace std;


class Estudiante {
    private:
    string nombre;
    string apellido;
    string codigo_estudiante;
    int asistencia;
    float nota_ciclo1;
    float nota_ciclo2;
    
    public:

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

    float getNotaCiclo2(){return nota_ciclo2;}

    float calcular_promedio(){
        return (nota_ciclo1 + nota_ciclo2) / 2;
    }

    int clasificacion_estudiantes(){
        double promedio = calcular_promedio();

        if (asistencia < 75) return -1;

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
        cout << "Promedio: " << calcular_promedio() << endl;
        cout << "Asistencia: " << asistencia << endl;
        cout << "Estudiante " + nombre + " " + apellido + ".\nCódigo: " + codigo_estudiante << endl;
        switch (clasificacion_estudiantes())
        {
        case 1:
            cout << "\nEstá APROBADO." << endl;
            break;
        case 0:
            cout << "\nEstá en SUSPENSO." << endl;
            break;
        case -1:
            cout << "\nEstá REPROBADO." << endl;
            break;
        }
    }

};


class Curso {
    private: 
    string nombre_curso;
    char paralelo;
    int nivel;
    Estudiante estu[40];
    int numero_estudiantes;
    
    public:

    Curso(){
        nombre_curso = "";
        paralelo = ' ';
        numero_estudiantes = 0;
    }

    void ingresar_datos(){
        cout << "Ingresar datos del curso" << endl;
        cout << "Ingresar nombre: ";
        cin >> nombre_curso;
        cout << "Ingrese el nivel: ";
        cin >> nivel;
        cout << "Ingresar paralelo: ";
        cin >> paralelo;
        cout << "Ingresar numero de estudiantes: ";
        cin >> numero_estudiantes;
    }

    void ingresar_datos_estudiants(){
        for (size_t i = 0; i < numero_estudiantes ; i++ ){
            cout << "Ingresar datos estudiante" << endl;
            estu[i].ingresar_datos();
        }
    }

    void mostrar_estus(){
        cout << "Clasificación de los estudiantes del curso" << endl;

        for (size_t i = 0; i < numero_estudiantes ; i++){
            estu[i].mostrar_estudiante();
        } 
    }

    bool verificar_nota_ciclo_2(Estudiante estudiante){
        return (estudiante.getNotaCiclo2() >= 7);
    }

    void mostrar_estus_nota_ciclo2(){
        cout << "Estudiantes con nota del segundo ciclo >= 7" << endl;
        for (size_t i = 0; i < numero_estudiantes ; i++){
            if (verificar_nota_ciclo_2(estu[i])){
                estu[i].mostrar_estudiante();
            }
        }
    }

    void mostrar_curso(){
        cout << "Curso: " + nombre_curso << endl;
        cout << "Paralelo: " << paralelo << endl;
        cout << "Nivel: " << nivel << endl;
        cout << "ESTUDIANTES -> " << numero_estudiantes << endl;
    }

    void mostrar_datos(){
        mostrar_curso();
        mostrar_estus();
        mostrar_estus_nota_ciclo2();
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