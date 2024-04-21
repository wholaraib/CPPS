#include <iostream>
#include <cstdlib>
using namespace std;
class stack
{
public:
    int *arr;
    int size;
    int top;
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int ele)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = ele;
            cout << "Pushed " << ele << endl;
        }
        else
        {
            cout << "Stack overflow!" << endl;
            exit(0);
        }
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow!" << endl;
            exit(0);
        }
        else
            return arr[top--];
    }
    void display(int top)
    {
        int stackIndex = top;
        while (stackIndex > -1)
        {
            cout << arr[stackIndex--] << endl;
        }
        cout << endl;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
            return arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
};
int main()
{
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(2);  
    cout << "\nStack elements are : " << endl;
    s.display(s.top);

    cout << s.pop() << " Popped " << endl;

    cout << "Stack elements are : " << endl;
    s.display(s.top);

    cout << s.peek() << " is the top most element!" << endl;


    if (s.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;


    cout << s.pop() << " Popped " << endl;
    cout << s.pop() << " Popped " << endl;
    cout << s.pop() << " Popped " << endl;
    cout << s.pop() << " Popped " << endl;
    cout << s.pop() << " Popped " << endl;


    if (s.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}