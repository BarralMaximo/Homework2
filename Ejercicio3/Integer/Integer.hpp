#pragma once
#include "../Number/Number.hpp"

/**
 * @class Entero
 * @brief Representa un número entero dentro de una jerarquía numérica abstracta.
 * 
 * Esta clase hereda de la clase abstracta Numero e implementa operaciones aritméticas
 * con otros objetos también derivados de Numero, utilizando polimorfismo. El resultado
 * de cada operación se devuelve como un puntero único a un nuevo objeto.
 * 
 * Se puede combinar con objetos del tipo Entero, Real o Complejo mediante el uso de `dynamic_cast`.
 */
class Entero : public Numero {
private:
    int value;  ///< Valor entero almacenado

public:
    /**
     * @brief Constructor que inicializa el número entero con el valor dado.
     * @param v Valor entero inicial.
     */
    explicit Entero(int v);

    /**
     * @brief Devuelve el valor entero almacenado.
     * @return Valor entero.
     */
    int get_value() const;

    /**
     * @brief Suma polimórfica entre este número entero y otro número.
     * @param otro Referencia a otro objeto Numero.
     * @return Puntero único al resultado como nuevo objeto Numero.
     */
    std::unique_ptr<Numero> operator+(const Numero& otro) const override;

    /**
     * @brief Resta polimórfica entre este número entero y otro número.
     * @param otro Referencia a otro objeto Numero.
     * @return Puntero único al resultado como nuevo objeto Numero.
     */
    std::unique_ptr<Numero> operator-(const Numero& otro) const override;

    /**
     * @brief Multiplicación polimórfica entre este número entero y otro número.
     * @param otro Referencia a otro objeto Numero.
     * @return Puntero único al resultado como nuevo objeto Numero.
     */
    std::unique_ptr<Numero> operator*(const Numero& otro) const override;

    /**
     * @brief División polimórfica entre este número entero y otro número.
     * @param otro Referencia a otro objeto Numero.
     * @return Puntero único al resultado como nuevo objeto Numero.
     */
    std::unique_ptr<Numero> operator/(const Numero& otro) const override;

    /**
     * @brief Devuelve una representación en cadena del número entero.
     * @return String con el valor entero.
     */
    std::string toString() const override;
};