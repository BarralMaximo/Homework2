#pragma once
#include <string>
#include <map>
#include <iostream>

/**
 * @class Student
 * @brief Representa un estudiante con nombre, legajo y sus calificaciones en cursos.
 *
 * Esta clase modela a un estudiante individual, identificable por un número de legajo único
 * y su nombre completo. Cada estudiante puede tener múltiples materias asociadas con su
 * correspondiente nota final, almacenadas en un mapa.
 */
class Student {
private:
    std::string name; ///< Nombre completo del estudiante.
    int ID; ///< Legajo único del estudiante.
    std::map<std::string, double> subjects; ///< Mapa de materias y sus notas finales.

public:
    /**
     * @brief Constructor que inicializa un estudiante con nombre e ID.
     * @param name Nombre completo del estudiante.
     * @param ID Legajo único del estudiante.
     */
    Student(const std::string& name, int ID);

    /**
     * @brief Obtiene el nombre del estudiante.
     * @return Nombre del estudiante.
     */
    std::string get_name() const;

    /**
     * @brief Obtiene el legajo (ID) del estudiante.
     * @return Legajo del estudiante.
     */
    int get_ID() const;

    /**
     * @brief Asigna una nota a un curso del estudiante.
     * Si la materia ya existía, la nota se sobrescribe.
     * @param course Nombre del curso.
     * @param score Nota final del curso.
     */
    void set_subjects(const std::string& course, double score);

    /**
     * @brief Calcula el promedio general del estudiante.
     * @return Promedio de todas las notas; 0.0 si no hay materias cargadas.
     */
    double average() const;

    /**
     * @brief Operador de comparación para ordenar estudiantes alfabéticamente por nombre.
     * @param other Otro estudiante con el que comparar.
     * @return true si el nombre de este estudiante es menor al del otro.
     */
    bool operator<(const Student& other) const;

    /**
     * @brief Operador de inserción para imprimir la información del estudiante.
     * @param os Stream de salida.
     * @param est Estudiante a imprimir.
     * @return Referencia al stream de salida.
     */
    friend std::ostream& operator<<(std::ostream& os, const Student& est);
};