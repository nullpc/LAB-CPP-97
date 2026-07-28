#include <iostream>
int main() {
    int n;
    int factorial = 1;
    std::cout << "Enter a number: ";
    std::cin >> n;
    if (n < 0) {
std::cout << "Factorial is not defined for negative numbers." << std::endl;
} else 
{
for (int i = 1; i <= n; i++) 
{
 factorial = factorial * i;
}
std::cout << "Factorial of " << n << " = " << factorial << std::endl;
}
return 0;
}