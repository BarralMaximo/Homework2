#pragma once
#include <memory>
#include <string>

/**
 * @class Numero
 * @brief Clase base abstracta para representar números de distintos tipos (Entero, Real, Complejo).
 *
 * Esta clase define una interfaz común para realizar operaciones aritméticas polimórficas entre números.
 * Las subclases deben implementar las operaciones básicas y una conversión a string.
 */
class Numero {
public:
    /**
     * @brief Destructor virtual por defecto.
     */
    virtual ~Numero() = default;

    /**
     * @brief Suma polimórfica.
     * @param otro Otro número con el que se realiza la suma.
     * @return Resultado de la suma como puntero único a un nuevo objeto Numero.
     */
    virtual std::unique_ptr<Numero> operator+(const Numero& otro) const = 0;

    /**
     * @brief Resta polimórfica.
     * @param otro Otro número con el que se realiza la resta.
     * @return Resultado de la resta como puntero único a un nuevo objeto Numero.
     */
    virtual std::unique_ptr<Numero> operator-(const Numero& otro) const = 0;

    /**
     * @brief Multiplicación polimórfica.
     * @param otro Otro número con el que se realiza la multiplicación.
     * @return Resultado de la multiplicación como puntero único a un nuevo objeto Numero.
     */
    virtual std::unique_ptr<Numero> operator*(const Numero& otro) const = 0;

    /**
     * @brief División polimórfica.
     * @param otro Otro número con el que se realiza la división.
     * @return Resultado de la división como puntero único a un nuevo objeto Numero.
     */
    virtual std::unique_ptr<Numero> operator/(const Numero& otro) const = 0;

    /**
     * @brief Devuelve una representación en cadena del número.
     * @return Cadena que representa el valor del número.
     */
    virtual std::string toString() const = 0;
};

/**
 * @brief Sobrecarga del operador de salida para imprimir objetos Numero.
 * @param os Flujo de salida.
 * @param num Número a imprimir.
 * @return Referencia al flujo de salida modificado.
 */
std::ostream& operator<<(std::ostream& os, const Numero& num);
