#pragma once
#include "../Student/Student.hpp"

#include <vector>
#include <memory>
#include <iostream>

class Course {
private:
    std::vector<std::shared_ptr<Student>> students;
    static const size_t capacidad_maxima = 20;

public:
    Course() = default;

    std::shared_ptr<Student> getStudent(int index) const;
    void registerStudent(std::shared_ptr<Student> est);
    void unregisterStudent(int ID);
    int searchStudent(int ID) const;
    bool courseFull() const;
    void printStudents() const;

    Course(const Course& other);

    friend std::ostream& operator<<(std::ostream& os, const Course& curso);
};
