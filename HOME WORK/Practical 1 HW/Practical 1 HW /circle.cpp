#include <iostream>
int main() {
    double radius;
    double pi = 3.14159;
    std::cout << "Enter radius: ";
    std::cin >> radius;
    double area = pi * radius * radius;
    double circumference = 2 * pi * radius;
    std::cout << "Area = " << area << std::endl;
    std::cout << "Circumference = " << circumference << std::endl;
    return 0;
}