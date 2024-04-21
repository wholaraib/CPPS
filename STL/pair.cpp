#include <iostream>
using namespace std;
int main()
{   
    //declaring a pair
    pair<int,int> p;

    //storing values in pairs

    //method 0
    // pair<int,int> p = {2,4};
    //This method doesn't work in my system
    
    //method 1
    p.first = 2;
    p.second = 3;
    //printing
    cout << p.first << " " << p.second << endl;

    //method 2
    p = make_pair(2,5);
    //printing
    cout << p.first << " " << p.second << endl;


}