/*
Write a C++ program to create a class called STRING and implement the following operations by writing an appropriate constructor
an overloaded operator'+' and '>='and illustrate the use of friend function in operator overloading.
*/
#include <iomanip>
#include <iostream>
#include <stdlib.h>
using namespace std;
class String
{
    string s;
public:
    void read()
    {
        cout << "Enter A String\n";
        cin >> s;
    }
    void display()
    {
        cout << s; 
    }
    friend String operator+(String s1, String s2);
    friend bool operator>=(String s1, String s2);
};
String operator+(String s1, String s2)
{
    String t;
    t.s = s1.s + s2.s;
    return t;
}
bool operator>=(String s1, String s2)
{
    if ((s1.s).length() >= (s2.s).length())
        return true;
    return false;
}
int main()
{
    String s1, s2, s3;
    s1.read();
    s2.read();
    s3 = s1 + s2;
    cout << "String 1 = ";
    s1.display();
    cout << endl;
    cout << "String 2 = ";
    s2.display();
    cout << endl;
    cout << "Concatenated String = ";
    s3.display();
    cout << endl;
    if (s1 >= s2)
        cout << "String 1 is Greater";
    else
        cout << "String 2 is Greater";
}