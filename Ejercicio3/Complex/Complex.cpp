#include "Complex.hpp"
#include "../Integer/Integer.hpp"
#include "../Real/Real.hpp"

#include <stdexcept>
#include <memory>
#include <string>

using namespace std;

Complejo::Complejo(double r, double i) : Re(r), Im(i) {}

double Complejo::get_real() const {
    return Re;
}

double Complejo::get_imag() const {
    return Im;
}

unique_ptr<Numero> Complejo::operator+(const Numero& num) const {
    if (const Entero* temp = dynamic_cast<const Entero*>(&num)) {
        return make_unique<Complejo>(Re + temp->get_value(), Im);
    } else if (const Real* temp = dynamic_cast<const Real*>(&num)) {
        return make_unique<Complejo>(Re + temp->get_value(), Im);
    } else if (const Complejo* temp = dynamic_cast<const Complejo*>(&num)) {
        return make_unique<Complejo>(Re + temp->Re, Im + temp->Im);
    }
    throw runtime_error("Suma inválida entre tipos incompatibles");
}

unique_ptr<Numero> Complejo::operator-(const Numero& num) const {
    if (const Entero* temp = dynamic_cast<const Entero*>(&num)) {
        return make_unique<Complejo>(Re - temp->get_value(), Im);
    } else if (const Real* temp = dynamic_cast<const Real*>(&num)) {
        return make_unique<Complejo>(Re - temp->get_value(), Im);
    } else if (const Complejo* temp = dynamic_cast<const Complejo*>(&num)) {
        return make_unique<Complejo>(Re - temp->Re, Im - temp->Im);
    }
    throw runtime_error("Resta inválida entre tipos incompatibles");
}

unique_ptr<Numero> Complejo::operator*(const Numero& num) const {
    if (const Entero* temp = dynamic_cast<const Entero*>(&num)) {
        return make_unique<Complejo>(Re * temp->get_value(), Im * temp->get_value());
    } else if (const Real* temp = dynamic_cast<const Real*>(&num)) {
        return make_unique<Complejo>(Re * temp->get_value(), Im * temp->get_value());
    } else if (const Complejo* temp = dynamic_cast<const Complejo*>(&num)) {
        double real = Re * temp->Re - Im * temp->Im;
        double imag = Re * temp->Im + Im * temp->Re;
        return make_unique<Complejo>(real, imag);
    }
    throw runtime_error("Multiplicación inválida entre tipos incompatibles");
}

unique_ptr<Numero> Complejo::operator/(const Numero& num) const {
    if (const Entero* temp = dynamic_cast<const Entero*>(&num)) {
        if (temp->get_value() == 0) throw runtime_error("División por cero");
        return make_unique<Complejo>(Re / temp->get_value(), Im / temp->get_value());
    } else if (const Real* temp = dynamic_cast<const Real*>(&num)) {
        if (temp->get_value() == 0) throw runtime_error("División por cero");
        return make_unique<Complejo>(Re / temp->get_value(), Im / temp->get_value());
    } else if (const Complejo* temp = dynamic_cast<const Complejo*>(&num)) {
        if (temp->Re == 0 && temp->Im == 0) throw runtime_error("División por cero");
        double denom = temp->Re * temp->Re + temp->Im * temp->Im;
        double real = (Re * temp->Re + Im * temp->Im) / denom;
        double imag = (Im * temp->Re - Re * temp->Im) / denom;
        return make_unique<Complejo>(real, imag);
    }
    throw runtime_error("División inválida entre tipos incompatibles");
}

string Complejo::toString() const {
    return to_string(Re) + " + " + to_string(Im) + "i";
}
