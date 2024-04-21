#include <iostream>
#include <map>
using namespace std;
int main()
{   
    map <string, int> m;
    int n;
    cout << "Enter number of strings you want to Enter : ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {   
        string s;
        cin >> s;
        m[s]++;
    }
    for(auto pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}