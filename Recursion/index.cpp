#include <iostream>
using namespace std;
void fun(int &a)
{
    a = 4;
    cout << "Hello Again " << endl;
}
int main()
{   
    cout << "Hello World" << endl;
    int a = 3;
    int b = 4;
    int c = 9;
    fun(a);
    fun(b);
    fun(c);
}