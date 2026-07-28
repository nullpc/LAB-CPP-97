#include <iostream>
int main() {
int n;
int i = 1;
std::cout << "Enter a number (n): ";
std::cin >> n;
std::cout << "Natural numbers up to " << n << ":" << std::endl;
while (i <= n) {
std::cout << i << " ";
i++;
}
std::cout << std::endl;return 0;
}