#include <iostream>
int main() {
    int a, b;
    std::cout << "Enter first number (a): ";
    std::cin >> a;
    std::cout << "Enter second number (b): ";
    std::cin >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    return 0;
}