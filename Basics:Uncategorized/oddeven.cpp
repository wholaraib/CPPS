#include <iostream>
using namespace std;
int iseven(int n)
{   
    return (n&1);
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    iseven(n) ? cout << "Odd\n" : cout << "Even\n" ;
}