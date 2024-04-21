#include <iostream>
using namespace std;
int helper(int num, int digits)
{
    
    //we can use any of the two condtion below
    // if(num==0) //this condition will occur only one time
    //     return 0;
    //OR
    if(num%10 == num) // this condition will also occur only one time
        return num;
    int rem = num%10;
    //we don't need this line
    // int ans = ans + rem*pow(10,digits-1);
    //concept
    return rem*pow(10,digits-1) + helper(num/10,digits-1); 
}
int rev(int num)
{
    int n = num;
    int numOfDigits = 0;
    while(n!=0)
    {
        numOfDigits++;
        n/=10;
    }
    return helper(num,numOfDigits);
}
int main()
{   
    int num = 46233;   
    cout << rev(num) << endl;
}