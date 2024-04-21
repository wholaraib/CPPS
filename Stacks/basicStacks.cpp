#include <iostream>
#include <stack>
using namespace std;
int main()
{
    //creating stack
    stack <int> s;

    //pushing element in stack
    s.push(3);
    s.push(2);
    s.push(1);

    //poping element from stack
    s.pop();

    //size of the stack
    cout << s.size() << endl;
    //using empty() function to check whether the stack is empty or not.

    if(s.empty())
    {
        cout << "The stack is empty!" << endl;
    }
    else
        cout << "The stack is not empty!" << endl;

    //printing top most element of the stack
    cout << "The top most element in the stack is " << s.top() << endl;


}