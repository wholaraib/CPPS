#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
void swaps(string str,int s, int e)
{
     char temp = str[s];
     str[s] = str[e];
     str[e] = temp;
}

bool isSymbol(char ch)
{
     if(ch >= 32 && ch <= 47 || ch >= 58 && ch <= 64 || ch >= 91 && ch <= 96 || ch >= 123 && ch <= 127)
          return 1;
     return 0;
}
bool isValid(char ch)
{
     if((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')||(ch >= '0' && ch <= '9'))
          return 1;
     return 0;
}
void reverse(string str, int len)
{
     int s = 0;
     int e = len - 1;
     while(s<e)
          swaps(str,s++,e--);
}
char tolowercase(char ch)
 {
        if(ch >= 'a' && ch <= 'z')
          return ch;
      return (ch + 32);
}
int length(string str)
{
     int count = 0;
     for(int i = 0; str[i]!='\0'; i++)
          count++;
     return count;
}
bool checkPallindrome(string str,int len)
{
     int s = 0,e = len - 1;
     while(s<e)
     {
          if(isSymbol(str[s]))
               s++;
          if(isSymbol(str[e]))
               e--;
          else if(tolowercase(str[s]) != tolowercase(str[e]))
               return 0;
          else{
               s++;
               e--;
          }
     }
     return 1;
}
int main()
{
     string str = "racecar";
     int len;
     bool ans;
     // cout << "Enter a string to check if its Pallindrome or not: " ;
     // cin >> str;
     len = length(str);
     reverse(str,len);
     cout << str << endl;
     ans = checkPallindrome(str,len);
     if(ans == 1)
     {
          cout << "Pallindrome string" << endl;
          cout << str.size();
          exit(0);
     }
      cout << "Not a Pallindrome string" << endl;

     
}