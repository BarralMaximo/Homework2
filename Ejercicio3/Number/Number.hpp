#pragma once
#include <memory>
#include <string>

class Numero {
public:
    virtual ~Numero() = default;

    virtual std::unique_ptr<Numero> operator+(const Numero& otro) const = 0;
    virtual std::unique_ptr<Numero> operator-(const Numero& otro) const = 0;
    virtual std::unique_ptr<Numero> operator*(const Numero& otro) const = 0;
    virtual std::unique_ptr<Numero> operator/(const Numero& otro) const = 0;

    virtual std::string toString() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Numero& num);