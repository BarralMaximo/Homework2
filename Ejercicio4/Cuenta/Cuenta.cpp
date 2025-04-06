#include "Cuenta.hpp"
#include <stdexcept>

Cuenta::Cuenta(std::string titular, double bal) : titularCuenta(titular), balance(bal) {}

void Cuenta::depositar(double cantidad) {
    if (cantidad < 0) throw std::runtime_error("Entrada Inválida");
    balance += cantidad;
}

std::string Cuenta::get_titular(){return titularCuenta;}