#pragma once
#include "../Number/Number.hpp"

class Entero : public Numero {
private:
    int value;

public:
    explicit Entero(int v);

    int get_value() const;

    std::unique_ptr<Numero> operator+(const Numero& otro) const override;
    std::unique_ptr<Numero> operator-(const Numero& otro) const override;
    std::unique_ptr<Numero> operator*(const Numero& otro) const override;
    std::unique_ptr<Numero> operator/(const Numero& otro) const override;

    std::string toString() const override;
};
