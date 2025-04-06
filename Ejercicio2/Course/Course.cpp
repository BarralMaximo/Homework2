#include "Course.hpp"
#include <algorithm>

std::shared_ptr<Student> Course::getStudent(int index) const {
    if (index < 0 || index >= students.size()) {
        throw std::out_of_range("Índice inválido en getStudent");
    }
    return students[index];
}

void Course::registerStudent(std::shared_ptr<Student> est) {
    if (courseFull()) {
        std::cerr << "No se puede inscribir: el curso está completo.\n";
        return;
    }
    if (searchStudent(est->get_ID()) != -1) {
        std::cerr << "Estudiante ya inscripto.\n";
        return;
    }
    students.push_back(est);
}

void Course::unregisterStudent(int ID) {
    int i = searchStudent(ID);

    if (i == -1) {
        std::cout << "El estudiante no se encuentra registrado\n";
        return;
    }

    students.erase(students.begin() + i);
}

int Course::searchStudent(int ID) const {
    for (int i = 0; i < static_cast<int>(students.size()); ++i) {
        if (students[i]->get_ID() == ID) {return i;}
    }
    return -1;
}

bool Course::courseFull() const {return students.size() >= capacidad_maxima;}

void Course::printStudents() const {
    std::vector<std::shared_ptr<Student>> sorted = students;
    std::sort(sorted.begin(), sorted.end(),
              [](const std::shared_ptr<Student>& a, const std::shared_ptr<Student>& b) {
                  return *a < *b;
              });

    for (const auto& est : sorted) {
        std::cout << *est << '\n';
    }
}

/* Constructor de copia que realiza una shallow copy:
 Se copia el vector de punteros compartidos (shared_ptr) a estudiantes, lo que implica que el nuevo curso comparte los mismos estudiantes en memoria.
 Esto es intencional, ya que varios cursos pueden tener estudiantes en común.*/
Course::Course(const Course& other) {
    students = other.students;
}


std::ostream& operator<<(std::ostream& os, const Course& course) {
    for (const auto& est : course.students) {
        os << *est << '\n';
    }
    return os;
}
