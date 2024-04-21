#include <iostream>
using namespace std;
bool isEven(int num)
{
    if(num%2 == 0)
        return true;
    return false;
}
bool isOdd(int num)
{
    if(num%2 == 0)
        return false;
    return true;
}
int helper(int num, int count)
{
    if(num == 0)
        return count;
    if(isEven(num))
    {
        return helper(num/2,count+1);
    }
    return helper(num-1,count+1);
}
int numberOfSteps(int num) 
{
    return helper(num,0);        
    
}
int main()
{   
    int num = 14;
    cout << numberOfSteps(num) << endl;

}