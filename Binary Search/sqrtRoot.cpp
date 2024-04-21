#include <iostream>
using namespace std;
float sqrtBinSearch(int n)
{
    int s = 0;
    int e = n - 1;
    int m = s + (e - s)/2;
    int ans;
    while(s <= e)
    {
        m = s + (e - s)/2;
        if(m*m == n)
        {
            return m;
        }
        else if(m*m < n)
        {
            ans = m;
            s = m + 1;
        }
        else 
            e = m - 1;
    }
    return ans;
}
int main()
{   
    int n = 5;
    cout << sqrtBinSearch(n) << endl;
}