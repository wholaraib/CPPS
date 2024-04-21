#include <iostream>
#include <string>
using namespace std;
char maxOccChar(string str)
{
    int number;
    int arr[26] = {0};
    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch >= 'a' && ch <= 'z')
            number = ch - 'a';
        else
            number = ch - 'A';
        
        arr[number]++;
    }
    int maxi = -1;
    char ans;
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] > maxi){
            maxi = arr[i];
            ans = i;
        }
    }
    return (ans + 'a');
}
int main()
{
    string str;
    char ans;
    cout << "Enter a string : ";
    cin >> str;
    ans = maxOccChar(str);
    cout << "The maximum occurring character is : " << ans << endl;
}