#pragma once
#include "../Number/Number.hpp"

class Real : public Numero {
private:
    double value;

public:
    Real(double value);

    double get_value() const;

    std::unique_ptr<Numero> operator+(const Numero& otro) const override;
    std::unique_ptr<Numero> operator-(const Numero& otro) const override;
    std::unique_ptr<Numero> operator*(const Numero& otro) const override;
    std::unique_ptr<Numero> operator/(const Numero& otro) const override;

    std::string toString() const override;
};

