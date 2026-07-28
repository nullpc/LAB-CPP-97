#include <iostream>
int main() 
{
int n;
int i = 2;
bool isPrime = true;
std::cout << "Enter a Number: ";
std::cin >> n;
if (n <= 1) {
isPrime = false;
} else 
{
while (i <= n / 2) 
{
if (n % i == 0) 
{
isPrime = false;
break;           
}
i++;
}
}
if (isPrime) {
std::cout << n << " is a prime number." << std::endl;
} else {
std::cout << n << " is not a prime number." << std::endl;
}
return 0;
}