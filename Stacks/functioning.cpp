#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{   
    stack <char> st;
    st.push('a');
    st.push('b');
    st.push('b');
    st.push('a');
    st.push('c');
    st.push('a');
    string ans;
    while(!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}