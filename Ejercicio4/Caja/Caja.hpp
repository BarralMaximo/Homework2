#pragma once

#include "../Cuenta/Cuenta.hpp"

/**
 * @class CajaDeAhorro
 * @brief Representa una cuenta bancaria de tipo caja de ahorro.
 *
 * Hereda de la clase Cuenta y agrega una restricción para la cantidad de extracciones,
 * además de mantener un contador de vistas (operaciones permitidas).
 * Solo permite un número limitado de extracciones por período simulado.
 */
class CajaDeAhorro : public Cuenta {
private:
    int contadorVistas; ///< Cantidad de retiros realizados.
    friend class CuentaCorriente; ///< Permite a CuentaCorriente acceder a sus atributos.

public:
    /**
     * @brief Constructor que inicializa la cuenta con un titular y un saldo inicial opcional.
     * @param titular Nombre del titular de la cuenta.
     * @param bal Saldo inicial de la cuenta. Por defecto es 0.0.
     */
    CajaDeAhorro(std::string titular, double bal = 0.0);

    /**
     * @brief Devuelve el saldo actual de la cuenta.
     * @return Saldo como número de punto flotante.
     */
    double getBalance() const;

    /**
     * @brief Intenta retirar una cantidad de dinero de la cuenta.
     *
     * Tiene en cuenta el número de vistas permitidas y el saldo disponible.
     * Si se exceden las vistas o el saldo no alcanza, la operación falla.
     *
     * @param cantidad Cantidad de dinero a retirar.
     */
    void retirar(double cantidad) override;

    /**
     * @brief Muestra la información de la cuenta.
     *
     * Incluye nombre del titular, tipo de cuenta y saldo.
     */
    void mostrarInfo() override;
};
