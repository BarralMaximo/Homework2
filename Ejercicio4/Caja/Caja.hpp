#pragma once

#include "../Cuenta/Cuenta.hpp"

class CajaDeAhorro : public Cuenta {
private:
    int contadorVistas;
    friend class CuentaCorriente;
    
public:
    CajaDeAhorro(std::string titular, double bal = 0.0);

    double getBalance() const;
    void retirar(double cantidad) override;
    void mostrarInfo() override;
};