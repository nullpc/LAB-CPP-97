#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
        : real(r), imag(i)
    { }
 void add(const Complex &c) 
 { 
    real = real + c.real;
    imag = imag + c.imag;
  }
    Complex subtract(const Complex &c)
    {
        return Complex(real - c.real, imag - c.imag);
    }
    void display() const
    {
        cout << real << " + i" << imag << endl;
    }
};

int main()
{
    Complex c1(4, 5);
    Complex c2(8, 9);

    c1.add(c2);
    c2.subtract(c1);

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Addition: \n";
    //display();

    cout << "Subtraction: \n";
    //display();

    return 0;
}