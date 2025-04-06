#pragma once

#include "../Cuenta/Cuenta.hpp"
#include "../Caja/Caja.hpp"

class CuentaCorriente : public Cuenta {
private:
    CajaDeAhorro* respaldo;

public:
    CuentaCorriente(std::string titular, double bal, CajaDeAhorro* respaldo);

    void retirar(double cantidad) override;
    void mostrarInfo() override;
};