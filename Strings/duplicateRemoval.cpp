// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string removeDuplicates(string s)
{
    string ans = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else if (st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "abbaca";
    /*
    in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
    */
    cout << removeDuplicates(s) << endl;
}