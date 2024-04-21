#include <iostream>
using namespace std;
enum choice
{
    a,
    s,
    m,
    d
};
class cal
{
    float a, b;
    char op;

public:
    inline void result()
    {
        cout << "Enter a and b : ";
        cin >> a >> b;
    }
    inline float add()
    {
        return a+b;
    }
    inline float sub()
    {
        return a-b;
    }
    inline float mul()
    {
        return a*b;
    }
    inline float div()
    {
        return a/b;
    }
};

int main()
{
    cal c;
    c.result();
    int op;
    cout << "Enter your choice : ";
    cin >> op;
    switch (op)
    {
    case a:
        cout << "Result : " << c.add() << endl;
        break;
    case s:
        cout << "Result : " << c.sub() << endl;
        break;
    case m:
        cout << "Result : " << c.mul() << endl;
        break;
    case d:
        cout << "Result : " << c.div() << endl;
        break;
    default : cout << "Invalid choice : ";
    }
    return 0;
}