#include <iostream>
#include <memory>
#include <cassert>

#include "Integer/Integer.hpp"
#include "Real/Real.hpp"
#include "Complex/Complex.hpp"

using namespace std;

void testEntero() {
    cout << "== Test Entero ==" << endl;
    Entero a(6), b(2);

    assert(a.toString() == "6");
    cout << "✔ toString OK" << endl;

    auto suma = a + b;
    cout << "6 + 2 = " << suma->toString() << endl;
    assert(suma->toString() == "8");

    auto resta = a - b;
    cout << "6 - 2 = " << resta->toString() << endl;
    assert(resta->toString() == "4");

    auto mult = a * b;
    cout << "6 * 2 = " << mult->toString() << endl;
    assert(mult->toString() == "12");

    auto div = a / b;
    cout << "6 / 2 = " << div->toString() << endl;
    assert(div->toString() == "3");

    Entero c(5), d(2);
    auto div2 = c / d;
    cout << "5 / 2 = " << div2->toString() << endl;
    assert(div2->toString() == "2.500000");
}

void testReal() {
    cout << "== Test Real ==" << endl;
    Real a(5.5), b(2.0);

    assert((a + b)->toString() == "7.500000");
    cout << "5.5 + 2.0 = " << (a + b)->toString() << endl;

    assert((a - b)->toString() == "3.500000");
    cout << "5.5 - 2.0 = " << (a - b)->toString() << endl;

    assert((a * b)->toString() == "11.000000");
    cout << "5.5 * 2.0 = " << (a * b)->toString() << endl;

    assert((a / b)->toString() == "2.750000");
    cout << "5.5 / 2.0 = " << (a / b)->toString() << endl;
}

void testComplejo() {
    cout << "== Test Complejo ==" << endl;
    Complejo a(3, 4), b(1, -2);

    auto suma = a + b;
    cout << "(3+4i) + (1-2i) = " << suma->toString() << endl;
    assert(suma->toString() == "4.000000 + 2.000000i");

    auto resta = a - b;
    cout << "(3+4i) - (1-2i) = " << resta->toString() << endl;
    assert(resta->toString() == "2.000000 + 6.000000i");

    auto mult = a * b;
    cout << "(3+4i) * (1-2i) = " << mult->toString() << endl;
    assert(mult->toString() == "11.000000 + -2.000000i");

    auto div = a / b;
    cout << "(3+4i) / (1-2i) = " << div->toString() << endl;
    assert(div->toString() == "-1.000000 + 2.000000i");
}

void testMixtos() {
    cout << "== Test Mixtos ==" << endl;
    Entero e(3);
    Real r(2.5);
    Complejo c(1, 1);

    assert((e + r)->toString() == "5.500000");
    cout << "3 + 2.5 = " << (e + r)->toString() << endl;

    assert((r + e)->toString() == "5.500000");
    cout << "2.5 + 3 = " << (r + e)->toString() << endl;

    assert((e + c)->toString() == "4.000000 + 1.000000i");
    cout << "3 + (1+i) = " << (e + c)->toString() << endl;

    assert((c + e)->toString() == "4.000000 + 1.000000i");
    cout << "(1+i) + 3 = " << (c + e)->toString() << endl;
}

void testDivisionPorCero() {
    cout << "== Test División por Cero ==" << endl;

    try {
        Entero e(5), cero(0);
        auto res = e / cero;
        assert(false); // No debería llegar
    } catch (const exception& e) {
        cout << "✔ División por cero detectada (Entero)\n";
    }

    try {
        Real r(5.0), z(0.0);
        auto res = r / z;
        assert(false);
    } catch (const exception& e) {
        cout << "✔ División por cero detectada (Real)\n";
    }

    try {
        Complejo c(3, 4), z(0, 0);
        auto res = c / z;
        assert(false);
    } catch (const exception& e) {
        cout << "✔ División por cero detectada (Complejo)\n";
    }
}

int main() {
    cout << "--- Iniciando tests ---\n\n";

    testEntero();
    cout << endl;

    testReal();
    cout << endl;

    testComplejo();
    cout << endl;

    testMixtos();
    cout << endl;

    testDivisionPorCero();
    cout << endl;

    cout << "--- Todos los tests pasaron correctamente ---\n";
    return 0;
}
