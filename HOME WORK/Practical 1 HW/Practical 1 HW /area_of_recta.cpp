#include <iostream>

int main() {
    double length, Breadth;

    std::cout << "Enter length: ";
    std::cin >> length;

    std::cout << "Enter Breadth: ";
    std::cin >> Breadth;

    double area = length * Breadth;
    double perimeter = 2 * (length + Breadth);

    std::cout << "Area = " << area << std::endl;
    std::cout << "Perimeter = " << perimeter << std::endl;

    return 0;
}