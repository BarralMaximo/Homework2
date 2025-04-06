#include "CuentaCorriente.hpp"
#include <iostream>

CuentaCorriente::CuentaCorriente(std::string titular, double bal, CajaDeAhorro* respaldo): Cuenta(titular, bal), respaldo(respaldo) {}

void CuentaCorriente::retirar(double cantidad) {
    if (cantidad <= balance) {balance -= cantidad;} 
    else {
        double faltante = cantidad - balance;

        if (respaldo && respaldo->getBalance() >= faltante) {
            std::cout << "Fondos insuficientes en cuenta corriente. Retirando $" << faltante << " de caja de ahorro...\n";
            respaldo->retirar(faltante);
            balance = 0;
        } 
        else {
            std::cout << "Fondos insuficientes en cuenta corriente y también en la caja de ahorro.\n";
        }
    }
}

void CuentaCorriente::mostrarInfo() {std::cout << "Tipo de cuenta: Cuenta Corriente\nTitular: " << this->get_titular()<< "\nBalance: $" << balance << std::endl;}