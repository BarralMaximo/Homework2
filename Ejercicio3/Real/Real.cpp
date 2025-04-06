#include "Real.hpp"
#include "../Integer/Integer.hpp"
#include "../Complex/Complex.hpp"

#include <stdexcept>
#include <memory>
#include <string>

using namespace std;

Real::Real(double i) : value(i) {}

double Real::get_value() const {
    return value;
}

unique_ptr<Numero> Real::operator+(const Numero& num) const {
    if (const Entero* temp = dynamic_cast<const Entero*>(&num)) {
        return make_unique<Real>(value + temp->get_value());
    } else if (const Real* temp = dynamic_cast<const Real*>(&num)) {
        return make_unique<Real>(value + temp->value);
    } else if (const Complejo* temp = dynamic_cast<const Complejo*>(&num)) {
        return make_unique<Complejo>(value + temp->get_real(), temp->get_imag());
    }
    throw runtime_error("Suma inválida entre tipos incompatibles");
}

unique_ptr<Numero> Real::operator-(const Numero& num) const {
    if (const Entero* temp = dynamic_cast<const Entero*>(&num)) {
        return make_unique<Real>(value - temp->get_value());
    } else if (const Real* temp = dynamic_cast<const Real*>(&num)) {
        return make_unique<Real>(value - temp->value);
    } else if (const Complejo* temp = dynamic_cast<const Complejo*>(&num)) {
        return make_unique<Complejo>(value - temp->get_real(), -temp->get_imag());
    }
    throw runtime_error("Resta inválida entre tipos incompatibles");
}

unique_ptr<Numero> Real::operator*(const Numero& num) const {
    if (const Entero* temp = dynamic_cast<const Entero*>(&num)) {
        return make_unique<Real>(value * temp->get_value());
    } else if (const Real* temp = dynamic_cast<const Real*>(&num)) {
        return make_unique<Real>(value * temp->value);
    } else if (const Complejo* temp = dynamic_cast<const Complejo*>(&num)) {
        return make_unique<Complejo>(value * temp->get_real(), value * temp->get_imag());
    }
    throw runtime_error("Multiplicación inválida entre tipos incompatibles");
}

unique_ptr<Numero> Real::operator/(const Numero& num) const {
    if (const Entero* temp = dynamic_cast<const Entero*>(&num)) {
        if (temp->get_value() == 0) throw runtime_error("División por cero");
        return make_unique<Real>(value / temp->get_value());
    } else if (const Real* temp = dynamic_cast<const Real*>(&num)) {
        if (temp->value == 0) throw runtime_error("División por cero");
        return make_unique<Real>(value / temp->value);
    } else if (const Complejo* temp = dynamic_cast<const Complejo*>(&num)) {
        if (temp->get_real() == 0 && temp->get_imag() == 0) throw runtime_error("División por cero");
        double denom = temp->get_real() * temp->get_real() + temp->get_imag() * temp->get_imag();
        return make_unique<Complejo>((value * temp->get_real()) / denom, (-value * temp->get_imag()) / denom);
    }
    throw runtime_error("División inválida entre tipos incompatibles");
}

string Real::toString() const {
    return to_string(value);
}
