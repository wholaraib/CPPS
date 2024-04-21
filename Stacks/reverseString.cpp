#include <iostream>
#include <stack>
using namespace std;
string reverse(string str)
{
    stack<char> s;
    for(int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string ans = "";

    while(!s.empty())
    {

        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{  
    string str = "laraib";
    cout << reverse(str) << endl;
}