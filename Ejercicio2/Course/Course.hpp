#pragma once
#include "../Student/Student.hpp"

#include <vector>
#include <memory>
#include <iostream>

/**
 * @class Course
 * @brief Representa un curso que puede contener hasta 20 estudiantes.
 *
 * La clase Course modela una agrupación de estudiantes usando agregación,
 * almacenando punteros compartidos a objetos de tipo Student. 
 * Permite registrar, desinscribir, buscar y listar estudiantes.
 * Además, implementa una copia superficial (shallow copy), donde los objetos
 * Student son compartidos entre múltiples cursos mediante shared_ptr.
 *
 * @note La capacidad máxima del curso es de 20 estudiantes.
 */
class Course {
private:
    std::vector<std::shared_ptr<Student>> students; ///< Lista de estudiantes inscritos
    static const size_t capacidad_maxima = 20; ///< Capacidad máxima del curso

public:
    /**
     * @brief Constructor por defecto de la clase Course.
     */
    Course() = default;

    /**
     * @brief Obtiene el estudiante en una posición específica.
     * @param index Índice dentro del vector de estudiantes.
     * @return shared_ptr al estudiante en esa posición.
     */
    std::shared_ptr<Student> getStudent(int index) const;

    /**
     * @brief Registra un nuevo estudiante en el curso.
     * @param est shared_ptr al estudiante que se desea inscribir.
     * @throws std::runtime_error si el curso está lleno o el estudiante ya está inscrito.
     */
    void registerStudent(std::shared_ptr<Student> est);

    /**
     * @brief Desinscribe a un estudiante del curso según su ID.
     * @param ID Legajo del estudiante a eliminar.
     */
    void unregisterStudent(int ID);

    /**
     * @brief Busca la posición de un estudiante en el vector por su ID.
     * @param ID Legajo del estudiante a buscar.
     * @return Índice del estudiante si lo encuentra, -1 en caso contrario.
     */
    int searchStudent(int ID) const;

    /**
     * @brief Indica si el curso ha alcanzado su capacidad máxima.
     * @return true si el curso está completo, false si aún hay cupo.
     */
    bool courseFull() const;

    /**
     * @brief Imprime por pantalla la lista de estudiantes ordenada alfabéticamente.
     */
    void printStudents() const;

    /**
     * @brief Constructor de copia (shallow copy).
     * Copia el vector de punteros compartidos a estudiantes, de forma que
     * ambos cursos compartan los mismos objetos de tipo Student.
     * @param other Otro objeto Course desde el cual se copiará la lista de estudiantes.
     */
    Course(const Course& other);

    /**
     * @brief Sobrecarga del operador << para imprimir los datos del curso.
     * @param os Stream de salida.
     * @param curso Curso a imprimir.
     * @return Referencia al stream de salida.
     */
    friend std::ostream& operator<<(std::ostream& os, const Course& curso);
};
