#include "Course/Course.hpp"
#include "Student/Student.hpp"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Función para limpiar entrada
void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void menuCopia(Course& copiaCurso, const Course& cursoOriginal) {
    int opcion;

    do {
        cout << "\n--- MENU CURSO COPIADO ---\n";
        cout << "1. Ver estudiantes\n";
        cout << "2. Asignar materia y nota a un estudiante\n";
        cout << "3. Comparar estudiantes (copiado vs original)\n";
        cout << "4. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> opcion;
        clear_input();

        if (opcion == 1) {
            copiaCurso.printStudents();

        } else if (opcion == 2) {
            int ID;
            cout << "ID del estudiante: ";
            cin >> ID;
            int index = copiaCurso.searchStudent(ID);
            if (index == -1) {
                cout << "Estudiante no encontrado en el curso copiado.\n";
            } else {
                string materia;
                double nota;
                cout << "Nombre de la materia: ";
                clear_input();
                getline(cin, materia);
                cout << "Nota final: ";
                cin >> nota;

                copiaCurso.getStudent(index)->set_subjects(materia, nota);
                cout << "Nota asignada correctamente al curso copiado.\n";
            }

        } else if (opcion == 3) {
            int ID;
            cout << "ID del estudiante: ";
            cin >> ID;
            int iOrig = cursoOriginal.searchStudent(ID);
            int iCopia = copiaCurso.searchStudent(ID);

            if (iOrig == -1 || iCopia == -1) {
                cout << "Estudiante no encontrado en uno de los cursos.\n";
            } else {
                auto orig = cursoOriginal.getStudent(iOrig);
                auto copia = copiaCurso.getStudent(iCopia);

                cout << "\n[Curso Original]\n" << *orig;
                cout << "\n[Curso Copiado]\n" << *copia << "\n";
            }
        }

    } while (opcion != 4);
}

int main() {
    Course curso;
    Course copiaCurso;

    int opcion;

    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Inscribir estudiante\n";
        cout << "2. Desinscribir estudiante\n";
        cout << "3. Buscar estudiante por ID\n";
        cout << "4. Ver si el curso está lleno\n";
        cout << "5. Imprimir lista de estudiantes\n";
        cout << "6. Asignar materia y nota\n";
        cout << "7. Ver promedio de un estudiante\n";
        cout << "8. Copiar curso y acceder a menú de copiado\n";
        cout << "9. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        clear_input();

        if (opcion == 1) {
            string nombre;
            int ID;
            cout << "Nombre completo del estudiante: ";
            getline(cin, nombre);
            cout << "ID (legajo): ";
            cin >> ID;
            if (curso.searchStudent(ID) != -1) {
                cout << "El estudiante ya está registrado.\n";
            } else {
                curso.registerStudent(make_shared<Student>(nombre, ID));
                cout << "Estudiante registrado correctamente.\n";
            }

        } else if (opcion == 2) {
            int ID;
            cout << "ID del estudiante a desinscribir: ";
            cin >> ID;
            curso.unregisterStudent(ID);

        } else if (opcion == 3) {
            int ID;
            cout << "ID a buscar: ";
            cin >> ID;
            int pos = curso.searchStudent(ID);
            if (pos != -1) {
                cout << "Estudiante encontrado:\n" << *curso.getStudent(pos) << "\n";
            } else {
                cout << "Estudiante no encontrado.\n";
            }

        } else if (opcion == 4) {
            if (curso.courseFull()) {
                cout << "El curso está lleno.\n";
            } else {
                cout << "El curso tiene espacio disponible.\n";
            }

        } else if (opcion == 5) {
            curso.printStudents();

        } else if (opcion == 6) {
            int ID;
            string materia;
            double nota;
            cout << "ID del estudiante: ";
            cin >> ID;
            int i = curso.searchStudent(ID);
            if (i == -1) {
                cout << "Estudiante no encontrado.\n";
            } else {
                cout << "Materia: ";
                clear_input();
                getline(cin, materia);
                cout << "Nota: ";
                cin >> nota;
                curso.getStudent(i)->set_subjects(materia, nota);
                cout << "Materia y nota asignadas.\n";
            }

        } else if (opcion == 7) {
            int ID;
            cout << "ID del estudiante: ";
            cin >> ID;
            int i = curso.searchStudent(ID);
            if (i == -1) {
                cout << "Estudiante no encontrado.\n";
            } else {
                cout << "Promedio: " << curso.getStudent(i)->average() << "\n";
            }

        } else if (opcion == 8) {
            copiaCurso = Course(curso);
            cout << "\nCurso copiado exitosamente.\n";
            menuCopia(copiaCurso, curso);
        }

    } while (opcion != 9);

    cout << "Saliendo del programa...\n";
    return 0;
}
