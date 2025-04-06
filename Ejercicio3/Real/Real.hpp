#pragma once
#include "../Number/Number.hpp"

/**
 * @class Real
 * @brief Representa un número real (punto flotante).
 *
 * Esta clase deriva de Numero y permite realizar operaciones aritméticas con números reales.
 * Implementa los métodos virtuales para operar de forma polimórfica con otros tipos de números.
 */
class Real : public Numero {
private:
    double value; ///< Valor numérico real.

public:
    /**
     * @brief Constructor que inicializa el número real.
     * @param value Valor real a almacenar.
     */
    Real(double value);

    /**
     * @brief Devuelve el valor real almacenado.
     * @return Valor como double.
     */
    double get_value() const;

    /**
     * @brief Suma este número real con otro número.
     * @param otro Referencia al otro número.
     * @return Resultado de la suma como puntero único a Numero.
     */
    std::unique_ptr<Numero> operator+(const Numero& otro) const override;

    /**
     * @brief Resta otro número de este número real.
     * @param otro Referencia al otro número.
     * @return Resultado de la resta como puntero único a Numero.
     */
    std::unique_ptr<Numero> operator-(const Numero& otro) const override;

    /**
     * @brief Multiplica este número real por otro número.
     * @param otro Referencia al otro número.
     * @return Resultado de la multiplicación como puntero único a Numero.
     */
    std::unique_ptr<Numero> operator*(const Numero& otro) const override;

    /**
     * @brief Divide este número real por otro número.
     * @param otro Referencia al otro número.
     * @return Resultado de la división como puntero único a Numero.
     */
    std::unique_ptr<Numero> operator/(const Numero& otro) const override;

    /**
     * @brief Devuelve una representación en cadena del número real.
     * @return Representación como string.
     */
    std::string toString() const override;
};