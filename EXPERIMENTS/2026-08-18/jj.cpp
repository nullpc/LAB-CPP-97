#include <iostream> 
using namespace std; 

class Complex { 
private: 
    int real, imag; 

public: 
    // Constructor with default arguments
    Complex(int r = 0, int i = 0) : real(r), imag(i) { } 

    // Modifies the current object by adding c
    void add(const Complex &c) { 
        real = real + c.real; 
        imag = imag + c.imag; 
    } 

    // Returns a new Complex object representing (this - c)
    Complex subtract(const Complex &c) { 
        return Complex(real - c.real, imag - c.imag); 
    } 

    // Displays the complex number
    void display() const { 
        cout << real << " + i" << imag << endl; 
    } 
}; 

int main() { 
    Complex c1(4, 5); 
    Complex c2(8, 9); 

    // 1. Line below modifies c1: c1 becomes (4+8) + i(5+9) = 12 + i14
    c1.add(c2); 

    // 2. Line below calculates (c2 - c1) based on current values:
    // (8 - 12) + i(9 - 14) = -4 + i-5.
    // Note: The result is returned but NOT saved anywhere, so c2 remains unchanged.
    c2.subtract(c1); 

    cout << "First Complex Number: "; 
    c1.display(); // Outputs modified c1

    cout << "Second Complex Number: "; 
    c2.display(); // Outputs original c2

    // Fixed: Created a dedicated object to hold and display the subtraction result
    Complex c3(4, 5); // Reset to original c1 values for standard addition demo
    Complex c4(8, 9);
    
    cout << "Addition: ";
    c3.add(c4);
    c3.display();

    cout << "Subtraction: "; 
    Complex diff = c4.subtract(c3); // (8 - 12) + i(9 - 14)
    diff.display(); 

    return 0; 
}
