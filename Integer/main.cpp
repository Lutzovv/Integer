#include "integer.hpp"

int main() {
    system("chcp 1251>NUL");
    
    Integer a = 5;
    Integer b = 3;
    Integer c = -2;
    Integer d = -4;

    std::cout << a - b << "\n";
    std::cout << c - d << "\n";
    std::cout << c - a << "\n";
    std::cout << c - c << "\n";
    std::cout << d - a << "\n";
    std::cout << b - d << "\n";
}