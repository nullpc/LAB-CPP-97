#include <iostream>
int main() {
    int a, b, c;
    std::cout << "Enter three numbers: ";
    std::cin >> a >> b >> c;
    if (a >= b && a >= c) {
        std::cout << "Largest number is: " << a << std::endl;
    } else if (b >= a && b >= c) {
        std::cout << "Largest number is: " << b << std::endl;
    } else {
        std::cout << "Largest number is: " << c << std::endl;
    }
    return 0;
}