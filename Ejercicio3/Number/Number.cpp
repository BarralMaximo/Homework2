#include "Number.hpp"

std::ostream& operator<<(std::ostream& exit, const Numero& num){
    exit << num.toString();
    return exit;
}