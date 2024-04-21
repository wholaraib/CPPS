#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int check(int n)
{
    int sqr = sqrt(n);
    {
         if(sqr * sqr == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    }
}
bool fib(int n)
{
    int plus = (5*n*n + 4);
    int sub = (5*n*n - 4);

    if(check(plus) || check(sub))
    {
        return true;
        exit(0);
    }
    return false;

}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << fib(num) << endl;
}