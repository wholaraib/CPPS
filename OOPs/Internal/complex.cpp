/*
Write a C++ program to create a class called complex. Implement the following operations by overloading the operators+, and *.
Read and display complex number by overloading the operator >> and << respectively.
*/

#include <iostream>
using namespace std;
class complex
{
private:
    double real;
    double imag;
public:  
    complex()
    {
        real = 0;
        imag = 0;
    }
    complex(double r, double i)
    {
        real = r;
        imag = i;
    }
    complex operator+(complex const &obj)
    {
        complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    complex operator-(complex const &obj)
    {
        complex res;
        res.real = real - obj.real;
        res.imag = imag - obj.imag;
        return res;
    }
    complex operator*(complex const &obj)
    {
        complex res;
        res.real = real * obj.real - imag * obj.imag;
        res.imag = imag * obj.real + real * obj.imag;
        return res;
    }
    friend ostream &operator<<(ostream &os, const complex &c)
    {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
    friend istream &operator>>(istream &is, complex &c)
    {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};
int main()
{
    complex c1, c2, c3;
    cout << "Enter the first complex number: " << endl;
    cin >> c1;
    cout << "Enter the second complex number: " << endl;
    cin >> c2;
    c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;
    c3 = c1 - c2;
    cout << "c1 - c2 = " << c3 << endl;
    c3 = c1 * c2;
    cout << "c1 * c2 = " << c3 << endl;
    return 0;
}