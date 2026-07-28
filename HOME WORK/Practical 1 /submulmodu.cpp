#include <iostream>
int main() {
    int num1, num2;
    std::cout << "Enter first integer: ";
    std::cin >> num1;
    std::cout << "Enter second integer: ";
    std::cin >> num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    std::cout << "Subtraction (Difference): " << difference << std::endl;
    std::cout << "Multiplication (Product): " << product << std::endl;
    if (num2 != 0) 
    {
        int remainder = num1 % num2;
        std::cout << "Modulus (Remainder): " << remainder << std::endl;
    } 
    else 
    {
        std::cout << "Modulus: Cannot calculate remainder when dividing by zero!" << std::endl;
    }
    return 0;
}