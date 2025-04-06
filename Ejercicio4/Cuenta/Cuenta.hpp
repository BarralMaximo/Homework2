#pragma once

#include <string>

/**
 * @class Cuenta
 * @brief Clase abstracta base que representa una cuenta bancaria genérica.
 *
 * Define una interfaz común para distintos tipos de cuentas bancarias como CajaDeAhorro y CuentaCorriente.
 * Incluye operaciones básicas como depositar, retirar (abstracta) y mostrar información (abstracta).
 */
class Cuenta {
protected:
    double balance; ///< Saldo actual de la cuenta.

private:
    std::string titularCuenta; ///< Nombre del titular de la cuenta.

public:
    /**
     * @brief Constructor que inicializa el titular y el saldo de la cuenta.
     * @param titular Nombre del titular.
     * @param bal Saldo inicial. Por defecto es 0.0.
     */
    Cuenta(std::string titular, double bal = 0.0);

    /**
     * @brief Devuelve el nombre del titular de la cuenta.
     * @return String con el nombre del titular.
     */
    std::string get_titular();

    /**
     * @brief Deposita una cantidad de dinero en la cuenta.
     * @param cantidad Monto a depositar.
     */
    virtual void depositar(double cantidad);

    /**
     * @brief Retira una cantidad de dinero de la cuenta.
     *
     * Método puramente virtual. Debe ser implementado por las clases derivadas.
     *
     * @param cantidad Monto a retirar.
     */
    virtual void retirar(double cantidad) = 0;

    /**
     * @brief Muestra información de la cuenta (titular, tipo, saldo, etc.).
     *
     * Método puramente virtual. Debe ser implementado por las clases derivadas.
     */
    virtual void mostrarInfo() = 0;

    /**
     * @brief Destructor virtual para permitir destrucción correcta de objetos derivados.
     */
    virtual ~Cuenta() = default;
};