#include <iostream>
using namespace std;
//power function
int power(int a, int b)
{
    int ans = 1;
    for(int i = 1; i<=b; i++)
    {
        ans = 2*ans;
    }
    return ans;
}
/*
below we have 2 methods for a program..
a program to check whether a number can be represented as 2 raise to some power x(say).
for eg : 
8 can be represented as 2 raise to the power 3
and
64 can represented as 2 raise to the power 6  

if YES then the output will be Yes
else
the output will be No
*/

int main()
{
    int n,flag = 0;
    cout << "Enter a number: ";
    cin >> n;
    //making a copy of n for second method
    int temp = n;
    //Method 1 : 
    for(int i = 1; i <= n; i++)
    {
        if(power(2,i) == n){
        flag = 1;
        break;
        }
    }

    if (flag == 1)
    {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }    


    //Method 2:
    int bit,count = 0;
    while(temp!=0)
    {
        if(temp&1)
        {
            count++;
        }
        temp = temp >> 1;
    }
    if(count == 1)
    cout << "Yes" << endl;

    else
    cout << "No" << endl;
}