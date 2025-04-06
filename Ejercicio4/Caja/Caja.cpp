#include "Caja.hpp"
#include <iostream>

CajaDeAhorro::CajaDeAhorro(std::string titular, double bal): Cuenta(titular, bal), contadorVistas(0) {}

double CajaDeAhorro::getBalance() const {return balance;}

void CajaDeAhorro::retirar(double cantidad) {
    if (cantidad < 0) {
        std::cout << "Cantidad inválida.\n";
    } else if (cantidad > balance) {
        std::cout << "Fondos insuficientes para retirar.\n";
    } else {
        balance -= cantidad;
    }
}

void CajaDeAhorro::mostrarInfo() {
    contadorVistas++;

    if (contadorVistas > 2) {
        if (balance < 20) {
            std::cout << "No cuenta con saldo suficiente para visualizar su información.\n";
            std::cout << "Añada fondos a su cuenta y vuelva a intentarlo.\n";
            return;
        } 
        else {
            balance -= 20;
            std::cout << "Descuento de $20 por mostrar información más de 2 veces.\n";
        }
    }

    std::cout << "Tipo de cuenta: Caja de Ahorro\n"<< "Titular: " << this->get_titular() << "\n"<< "Balance: $" << balance << std::endl;
}
