#pragma once
#include "../Number/Number.hpp"

class Complejo : public Numero {
private:
    double Re;
    double Im;

public:
    Complejo(double real, double imaginaria);

    double get_real() const;
    double get_imag() const;

    std::unique_ptr<Numero> operator+(const Numero& otro) const override;
    std::unique_ptr<Numero> operator-(const Numero& otro) const override;
    std::unique_ptr<Numero> operator*(const Numero& otro) const override;
    std::unique_ptr<Numero> operator/(const Numero& otro) const override;

    std::string toString() const override;
};
