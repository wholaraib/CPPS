#include <iostream>
using namespace std;
void rectangle(int m, int n)
{
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i==1||i==m||j==1||j==n)
            {
                cout << "*";

            }
            else
            {
                cout << " ";
            }

        }
        cout << endl;
    }
}
int main()
{
    int row,col;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;
    // int row =6, col = 20;
    rectangle(row,col);
    return 0;

}
