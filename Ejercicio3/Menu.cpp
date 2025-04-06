#include <iostream>
#include <memory>
#include <vector>

#include "Integer/Integer.hpp"
#include "Real/Real.hpp"
#include "Complex/Complex.hpp"

using namespace std;

int main() {
    int opcion;
    unique_ptr<Numero> a, b, resultado;

    while (true) {
        cout << "\n--- Menú de Pruebas ---\n";
        cout << "1. Crear Entero\n";
        cout << "2. Crear Real\n";
        cout << "3. Crear Complejo\n";
        cout << "4. Sumar\n";
        cout << "5. Restar\n";
        cout << "6. Multiplicar\n";
        cout << "7. Dividir\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 0) break;

        switch (opcion) {
            case 1: {
                int val;
                cout << "Ingrese valor entero: ";
                cin >> val;
                a = make_unique<Entero>(val);
                break;
            }
            case 2: {
                double val;
                cout << "Ingrese valor real: ";
                cin >> val;
                a = make_unique<Real>(val);
                break;
            }
            case 3: {
                double re, im;
                cout << "Parte real: ";
                cin >> re;
                cout << "Parte imaginaria: ";
                cin >> im;
                a = make_unique<Complejo>(re, im);
                break;
            }
            case 4: case 5: case 6: case 7: {
                if (!a) {
                    cout << "Primero creá un número con las opciones 1-3.\n";
                    break;
                }

                cout << "Creá el segundo número:\n";
                cout << "1. Entero  2. Real  3. Complejo\nOpción: ";
                int tipo;
                cin >> tipo;

                if (tipo == 1) {
                    int val;
                    cout << "Valor entero: ";
                    cin >> val;
                    b = make_unique<Entero>(val);
                } else if (tipo == 2) {
                    double val;
                    cout << "Valor real: ";
                    cin >> val;
                    b = make_unique<Real>(val);
                } else if (tipo == 3) {
                    double re, im;
                    cout << "Parte real: ";
                    cin >> re;
                    cout << "Parte imaginaria: ";
                    cin >> im;
                    b = make_unique<Complejo>(re, im);
                } else {
                    cout << "Tipo inválido.\n";
                    break;
                }

                try {
                    if (opcion == 4)
                        resultado = *a + *b;
                    else if (opcion == 5)
                        resultado = *a - *b;
                    else if (opcion == 6)
                        resultado = *a * *b;
                    else if (opcion == 7)
                        resultado = *a / *b;

                    cout << "Resultado: " << *resultado << endl;
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            default:
                cout << "Opción inválida.\n";
                break;
        }
    }

    return 0;
}