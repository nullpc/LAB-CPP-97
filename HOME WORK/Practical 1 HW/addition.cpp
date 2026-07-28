#include <iostream>
int main() {
    int firstNumber, secondNumber, sum;
    std::cout << "Enter first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter second number: ";
    std::cin >> secondNumber;
    sum = firstNumber + secondNumber;
    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}