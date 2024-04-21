#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int sqr = sqrt(num);
    if(sqr * sqr == num)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

} 