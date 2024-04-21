#include <iostream>
#include <string>
using namespace std;
int main()
{   
    string str;
    cout << "Enter string : ";
    getline(cin, str, 'h'); //it will take input until it encounter 'h' in a sentence
    cout << str << endl;
    
}