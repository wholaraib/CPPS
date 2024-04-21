#include <iostream>
#include <string>
using namespace std;

// string sayDigits(int num)
// {   

// }
long long int reverse(int n)
{
    int rem;
    int temp = 0;
    while(n!=0)
    {
        rem = n%10;
        n/=10;
        temp = temp*10 + rem;
    }
    return temp;
}
int main()
{   
    string digits[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
    long long int num;
    cin >> num;
    int lastDigit;
    string ans;
    // sayDigits(num);
    long long int temp = reverse(num);
    while(temp!=0)
    {
        lastDigit = temp%10;
        temp/=10;
        ans.append(digits[lastDigit]);
    }
    cout << ans << endl;
}