#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <char> reverseWord(string str)
{
    vector <char> temp;
    for(int i = str.length() - 1; i >= 0 ; i--)
    {
            temp.push_back(str[i]);
    }
    return temp;
}
int main()
{   
    string str = "Hello everyone, my name is Mohammad Laraib's";   
    vector <char> temp =  reverseWord(str);
    for(int i = 0; i < temp.size(); i++)
        cout << temp[i];

}