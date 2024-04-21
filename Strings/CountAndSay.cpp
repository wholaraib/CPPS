//https://leetcode.com/problems/count-and-say/
#include <iostream>
#include <string>
using namespace std;

int getCount(int n)
{

}
int main()
{      
    int n = 4;
    string ans = "";
    int N = n/n;
    while(N<=n)
    {
        int value = N;
        int count = getCount(N);
        string Value = to_string(value);
        string Count = to_string(count);
        ans = Value + Count;


    }
    
    // cout << countAndSay(n) << endl;
}