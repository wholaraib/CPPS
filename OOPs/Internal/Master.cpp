/*
Consider a class diagram below. The class Master derives information from both Account and Admin classes which in turn derive information from the class person.
Define all the four classes and write a program to create, update and display the information contained in Master objects.
And also print appropriate messages if record is not present.
*/
#include <iostream>
using namespace std;
class person
{
protected:
    char name[30];
    int code;

public:
    friend void update();
    void getcode()
    {
        cout << "Enter the code: ";
        cin >> code;
    }
    int rcode()
    {
        return code;
    }
    void getname()
    {
        cout << "\nEnter the name: ";
        cin >> name;
    }
};
class account : virtual public person
{
protected:
    int pay;

public:
    void getpay()
    {
        cout << "\nEnter payment: ";
        cin >> pay;
    }
};
class admin : virtual public person
{
protected:
    int exp;

public:
    void getexp()
    {
        cout << "\nEnter experience: ";
        cin >> exp;
    }
};
class master : public account, public admin
{
public:
    friend void update(int count);
    void create()
    {
        getcode();
        getname();
        getpay();
        getexp();
    }
    void display()
    {
        cout << code << "\t\t" << name << "\t\t" << pay << "\t\t" << exp << endl;
    }
};
master m[20];
void update(int count)
{
    int c, ch, i, flag = 0;
    cout << "Enter code: ";
    cin >> c;
    for (i = 0; i < count; i++)
    {
        if (c == m[i].rcode())
        {
            flag = 1;
            cout << "\n1. Payment\n2. Experience\n3. Display\n4. Exit";
            cout << "\nEnter your choice: " << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                m[i].getpay();
                break;
            case 2:
                m[i].getexp();
                break;
            case 3:
                return;
            default:
                cout << "\nInvalid Entry!\n";
            }
            break;
        }
    }
    if (!flag)
    {
        cout << "\nCode not found!\n";
    }
}

int main()
{
   int ch, count = 0, i = 0;
    while (1)
    {
        cout << "1. Create\n2. Update\n3. Display\n4. Exit";
        cout << "\nEnter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            m[i].create();
            count++;
            break;
        case 2: 
            update(count);
            break;
        case 3:
            cout << "Code"
                 << "\t\t"
                 << "Name"
                 << "\t\t"
                 << "Payment"
                 << "\t\t"
                 << "Experience" << endl;
            for (int i = 0; i < count; i++)
            {
                m[i].display();
            }
            break;
        case 4:
            exit(0);
        default:
            cout << "\nInvalid Entry!\n";
            break;
        }
        i++;
    }
    return 0;
}
