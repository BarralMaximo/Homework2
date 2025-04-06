#pragma once
#include "../Number/Number.hpp"

/**
 * @class Complejo
 * @brief Representa un número complejo, derivado de la clase abstracta Numero.
 * 
 * Esta clase modela números complejos en forma binómica, con parte real y parte imaginaria.
 * Implementa operaciones aritméticas (suma, resta, multiplicación y división) entre objetos
 * derivados de Numero, utilizando polimorfismo y devolviendo resultados como punteros únicos.
 * 
 * La clase se integra dentro de una jerarquía numérica junto a Entero y Real, permitiendo
 * operaciones entre distintos tipos de números mediante el uso de `dynamic_cast`.
 */
class Complejo : public Numero {
private:
    double Re;  ///< Parte real del número complejo
    double Im;  ///< Parte imaginaria del número complejo

public:
    /**
     * @brief Constructor que inicializa la parte real e imaginaria del número complejo.
     * @param real Valor de la parte real.
     * @param imaginaria Valor de la parte imaginaria.
     */
    Complejo(double real, double imaginaria);

    /**
     * @brief Obtiene la parte real.
     * @return Valor de la parte real.
     */
    double get_real() const;

    /**
     * @brief Obtiene la parte imaginaria.
     * @return Valor de la parte imaginaria.
     */
    double get_imag() const;

    /**
     * @brief Suma polimórfica entre este número complejo y otro número.
     * @param otro Referencia al número con el cual se suma.
     * @return Puntero único a un nuevo objeto Numero con el resultado.
     */
    std::unique_ptr<Numero> operator+(const Numero& otro) const override;

    /**
     * @brief Resta polimórfica entre este número complejo y otro número.
     * @param otro Referencia al número con el cual se resta.
     * @return Puntero único a un nuevo objeto Numero con el resultado.
     */
    std::unique_ptr<Numero> operator-(const Numero& otro) const override;

    /**
     * @brief Multiplicación polimórfica entre este número complejo y otro número.
     * @param otro Referencia al número con el cual se multiplica.
     * @return Puntero único a un nuevo objeto Numero con el resultado.
     */
    std::unique_ptr<Numero> operator*(const Numero& otro) const override;

    /**
     * @brief División polimórfica entre este número complejo y otro número.
     * @param otro Referencia al número con el cual se divide.
     * @return Puntero único a un nuevo objeto Numero con el resultado.
     */
    std::unique_ptr<Numero> operator/(const Numero& otro) const override;

    /**
     * @brief Devuelve una representación en cadena del número complejo.
     * @return String con el número en formato "a + bi" o "a - bi".
     */
    std::string toString() const override;
};
