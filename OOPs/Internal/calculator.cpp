#include <iostream>
using namespace std;
enum Operations
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};
class Calculator
{
private:
    int a, b;
public:
    Calculator(int x, int y)
    {
        a = x;
        b = y;
    }
    inline int add()
    {
        return a + b;
    }
    inline int sub()
    {
        return a - b;
    }
    inline int mul()
    {
        return a * b;
    }
    inline int div()
    {
        return a / b;
    }
};

int main()
{
    int x, y;
    Operations op;
    cout << "Enter two numbers" << endl;
    cout << "1st number : ";
    cin >> x;
    cout << "2nd number : ";
    cin >> y;
    cout << "Enter operation (0: add, 1: subtract, 2: multiply, 3: divide): "; 
            cin >> (int &)op;
    Calculator calc(x, y);
    switch (op)
    {
    case ADD:
        cout << "Result : " << calc.add();
        break;
    case SUBTRACT:
        cout << "Result : " << calc.sub();
        break;
    case MULTIPLY:
        cout << "Result : " << calc.mul();
        break;
    case DIVIDE:
        cout << "Result : " << calc.div();
        break;
    default:
        cout << "Invalid ";
        break;
    }
    return 0;
}
