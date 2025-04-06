#pragma once

#include <string>

class Cuenta {
protected:
    double balance;

private:
    std::string titularCuenta;

public:
    Cuenta(std::string titular, double bal = 0.0);
    std::string get_titular();

    virtual void depositar(double cantidad);
    virtual void retirar(double cantidad) = 0;
    virtual void mostrarInfo() = 0;
    virtual ~Cuenta() = default;
};