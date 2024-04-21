#include <iostream>
#include <string>
#include <vector>
using namespace std;
// https://leetcode.com/problems/string-compression/
int compress(vector<char>& chars) 
    {
        int ansIndex = 0;
        int ans;
        int i = 0; //Iterating Index
        int stringSize = chars.size();
        while(i < stringSize)
        {
            int j = i + 1; //Sub iterating Index
            while(j < stringSize && chars[i] == chars[j])
            {
                j++;
            }
            chars[ansIndex++] = chars[i];
            int count = j - i;
            if(count > 1)
            {
                string cnt = to_string(count);
                for(char ch : cnt){
                    chars[ansIndex++] = ch;
                }
            }
            //moving to the new character
            i = j;
            
        }
        return ansIndex;
    }
int main()
{
    vector<char> s;
    s.push_back('a');
    s.push_back('a');
    s.push_back('b');
    s.push_back('b');
    s.push_back('c');
    s.push_back('c');
    s.push_back('c');
    cout << compress(s) << endl;

}