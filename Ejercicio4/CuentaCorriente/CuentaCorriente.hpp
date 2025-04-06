#pragma once

#include "../Cuenta/Cuenta.hpp"
#include "../Caja/Caja.hpp"

/**
 * @class CuentaCorriente
 * @brief Representa una cuenta corriente que puede contar con una caja de ahorro de respaldo.
 *
 * La cuenta corriente permite retirar dinero, y si el saldo es insuficiente,
 * puede complementar el retiro utilizando fondos de una CajaDeAhorro asociada.
 */
class CuentaCorriente : public Cuenta {
private:
    CajaDeAhorro* respaldo; ///< Puntero a una CajaDeAhorro utilizada como respaldo en caso de fondos insuficientes.

public:
    /**
     * @brief Constructor de CuentaCorriente.
     * @param titular Nombre del titular de la cuenta.
     * @param bal Saldo inicial de la cuenta corriente.
     * @param respaldo Puntero a una CajaDeAhorro utilizada como respaldo.
     */
    CuentaCorriente(std::string titular, double bal, CajaDeAhorro* respaldo);

    /**
     * @brief Retira una cantidad de dinero de la cuenta corriente.
     *
     * Si el saldo es insuficiente, intenta usar fondos de la CajaDeAhorro de respaldo.
     * @param cantidad Monto a retirar.
     */
    void retirar(double cantidad) override;

    /**
     * @brief Muestra la información de la cuenta corriente.
     */
    void mostrarInfo() override;
};
