#pragma once

#include "../Cuenta/Cuenta.hpp"

class CajaDeAhorro : public Cuenta {
private:
    int contadorVistas;

public:
    CajaDeAhorro(std::string titular, double bal = 0.0);

    double getBalance() const;
    void retirar(double cantidad) override;
    void mostrarInfo() override;
};