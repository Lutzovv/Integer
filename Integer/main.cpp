#include "rational.hpp"

int main() {
    system("chcp 1251>NUL");
    
    Integer a = 5;
    Integer b = 3;
    Integer c = -2;
    Integer d = -4;
    Integer tt = -1;

    std::cout << 5 % 3 << "\n";
    std::cout << -2 % -4 << "\n";
    std::cout << -2 % 5 << "\n";
    std::cout << -2 % -2 << "\n";
    std::cout << -4 % 5 << "\n";
    std::cout << 3 % -4 << "\n";
    std::cout << "-----------------\n";
    std::cout << a % b << "\n";
    std::cout << c % d << "\n";
    std::cout << c % a << "\n";
    std::cout << c % c << "\n";
    std::cout << d % a << "\n";
    std::cout << b % d << "\n";
    a += b;
    std::cout << "\n\n\n" << a;
}
