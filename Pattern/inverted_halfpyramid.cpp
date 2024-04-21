#include <iostream>
using namespace std;
int print_pyramid(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = n; j >= i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0 ;
}
int main()
{
    int row;
    cout << "Enter number of rows: " ;
    cin >> row;
    print_pyramid(row);
}