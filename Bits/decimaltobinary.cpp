#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    //making alternate storages for num for different methods to solve this problem
    int temp = num;
    int flag = num;
    // Method 1 to convert from decimal to binary
    int rem,result = 0,j=0;
    cout << "Binary representation of " << num << " without using and(&) operator is : ";
    while(num!=0)
    {
        rem = num%2;
        num/=2;
        result = pow(10,j)*rem + result;
        j++;
    }
    cout << result;
    cout << endl;
    //Method 2 to convert from decimal to binary
    int bit,ans = 0, i = 0;
    cout << "Binary representation of " << temp << " using and(&) operator is : ";
    while(temp!=0)
    {
        bit = temp & 1;
        temp = temp >> 1;
        ans = pow(10,i)*bit + ans;
        i++;
    }
    cout << ans;
    cout << endl; 
}