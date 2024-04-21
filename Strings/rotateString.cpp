#include <iostream>
#include <string>
// https://www.codingninjas.com/codestudio/problems/check-if-one-string-is-a-rotation-of-another-string_1115683?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0

// IT IS AN TIME LIMIT EXCEEDED SOLUTION
using namespace std;
int isCyclicRotation(string p, string q)
{
    string r = "";
    int k = p.size() - 1; // for rotating towards right
    // int k = 1;         //for rotating to left
    while (k > 0)    // in each iteration we are rotating the string by 1 step
    {
        for (int i = 0; i < p.size(); i++)
        {
            r.push_back(p[(i + k) % p.size()]);
        }
        int res = r.compare(q); // comparing each string with q
        if (res == 0)
            return 1;
        r.erase(); //after comparing we are erasing the array
        k--;
    }
    return 0;
}
int main()
{
    string p = "abcde";
    string q = "deabc";
    int ans = isCyclicRotation(p, q);
    cout << ans << endl;
}