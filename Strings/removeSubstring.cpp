#include <iostream>
#include <string>
using namespace std;
//https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
string removeOccurrences(string s, string part)
{
    int i = 0;
    while(s.length()!=0 && s.find(part) < s.length())
    {
        s.erase(s.find(part),part.length());        
    }
        return s;   
}
int main()
{
    string str = "daabcbaabcbc";
    string part = "abc";
    int slen = str.length();
    int plen = part.length();
    cout << removeOccurrences(str,part) << endl;
    
}