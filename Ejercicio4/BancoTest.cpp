#include <iostream>
#include "CuentaCorriente/CuentaCorriente.hpp"
#include "Caja/Caja.hpp"

using namespace std;

void separador() {
    cout << "--------------------------------------------------" << endl;
}

int main() {
    // CREACIÓN DE CAJA DE AHORRO
    separador();
    cout << "[TEST] Crear Caja de Ahorro con $500" << endl;
    CajaDeAhorro caja("Juan Pérez", 500);
    caja.mostrarInfo();
    cout << endl;

    // MOSTRAR INFO VARIAS VECES
    separador();
    cout << "[TEST] Mostrar info por segunda vez (sin costo)" << endl;
    caja.mostrarInfo();
    cout << endl;

    separador();
    cout << "[TEST] Mostrar info por tercera vez (debería descontar $20)" << endl;
    caja.mostrarInfo();
    cout << endl;

    // RETIRO EXITOSO
    separador();
    cout << "[TEST] Retirar $200 de la caja de ahorro" << endl;
    caja.retirar(200);
    caja.mostrarInfo();
    cout << endl;

    // RETIRO EXCEDIDO
    separador();
    cout << "[TEST] Intentar retirar $400 (excede el saldo)" << endl;
    caja.retirar(400);
    caja.mostrarInfo();
    cout << endl;

    // CREACIÓN DE CUENTA CORRIENTE
    separador();
    cout << "[TEST] Crear Cuenta Corriente con $300 y caja de ahorro como respaldo" << endl;
    CuentaCorriente corriente("Ana Gómez", 300, &caja);
    corriente.mostrarInfo();
    cout << endl;

    // RETIRO EXITOSO
    separador();
    cout << "[TEST] Retirar $200 de la cuenta corriente (debería alcanzar)" << endl;
    corriente.retirar(200);
    corriente.mostrarInfo();
    cout << endl;

    // USO DE CAJA DE AHORRO COMO RESPALDO
    separador();
    cout << "[TEST] Retirar $200 más (requiere $100 extra del respaldo)" << endl;
    corriente.retirar(200);
    corriente.mostrarInfo();
    cout << endl;
    cout << "[Caja de Ahorro - Estado actual]" << endl;
    caja.mostrarInfo();
    cout << endl;

    // SIN FONDOS EN AMBAS
    separador();
    cout << "[TEST] Intentar retirar $1000 (sin fondos en ninguna cuenta)" << endl;
    corriente.retirar(1000);
    corriente.mostrarInfo();
    cout << endl;
    cout << "[Caja de Ahorro - Estado actual]" << endl;
    caja.mostrarInfo();
    cout << endl;

    separador();
    cout << "[TEST] Crear caja de ahorro con saldo $20 y mostrar info tres veces" << endl;
    CajaDeAhorro caja20("Pedro Test", 20);
    caja20.mostrarInfo();
    cout << endl;
    caja20.mostrarInfo();
    cout << endl;
    caja20.mostrarInfo();  // debería descontar y dejar saldo en 0
    cout << endl;
    caja20.mostrarInfo();  // ahora no debería permitir mostrar info
    cout << endl;

    separador();
    cout << "[TEST] Crear caja de ahorro con saldo $15 y mostrar info tres veces" << endl;
    CajaDeAhorro caja15("Laura Test", 15);
    caja15.mostrarInfo();
    cout << endl;
    caja15.mostrarInfo();
    cout << endl;
    caja15.mostrarInfo(); // NO debería permitir mostrar ni descontar, debería avisar
    cout << endl;  
    caja15.mostrarInfo();  // tampoco
    cout << endl;

    return 0;
}

