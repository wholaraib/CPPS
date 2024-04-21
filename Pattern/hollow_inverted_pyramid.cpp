#include <iostream>
using namespace std;
int main()
{
    int row,k;
    cout << "Enter the number of rows: ";
    cin >> row;

    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= row; j++)
        {
            if( j == row || j == i || i == 1){
            cout << "*";
            }
            else
            cout << " ";
        }
        cout << endl;
    }
}