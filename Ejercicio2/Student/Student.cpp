#include "Student.hpp"

Student::Student(const std::string& name, int ID): name(name), ID(ID) {}

std::string Student::get_name() const {return name;}

int Student::get_ID() const {return ID;}

void Student::set_subjects(const std::string& course, double score) {subjects[course] = score;}

double Student::average() const {
    if (subjects.empty()) return 0.0;

    double total = 0.0;
    for (const auto& pair : subjects) {
        total += pair.second;
    }

    return total / subjects.size();
}

bool Student::operator<(const Student& other) const {return name < other.name;}

std::ostream& operator<<(std::ostream& os, const Student& est) {
    os << "Nombre: " << est.get_name() << ", Legajo: " << est.get_ID() << ", Promedio: " << est.average();
    return os;
}
