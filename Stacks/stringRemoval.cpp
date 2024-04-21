#include <iostream>
#include <string>
#include <stack>
using namespace std;
//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 string removeDuplicates(string s) 
    {
        stack <char>  st;
        string ans;
        for(int i = 0; i < s.size(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }   
            else
            {
                if(st.top()  == s[i])
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty())
        {
            ans+=st.top(); 
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main()
{   
       string s = "azxxzy";
       cout << removeDuplicates(s) << endl;
}