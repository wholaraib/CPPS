#include <iostream>
using namespace std;
class person
{
protected:
    char name[30];
    int code;
public:
    friend void update(int count);
    void getcode()
    {
        cout << "Enter the code : ";
        cin >> code;
    }
    int rcode()
    {
        return code;
    }
    void getname()
    {
        cout << "Enter the name : ";
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
            cout << "\nEnter the payment : ";
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
            cout << "\nEnter the experience : ";
            cin >> exp;
        }
};
class Master : public account, public admin
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
        cout << code << "\t\t" << name << "\t\t" << pay << "\t\t" << exp << "\t\t" << endl;    
    }
};
Master m[20];
void update(int count)
{
    int c, ch, flag = 0;
    for(int i = 0; i < count; i++)
    {
        if(c == m[i].rcode())
        {
            flag = 1;
            cout << "1.Payment\n2.Experience\n3.Display\n4.Exit\n";
            cout << "Enter your choice : ";
            cin >> ch;
            switch(ch)
            {
                case 1 : m[i].getpay();break;
                case 2 : m[i].getexp();break;
                case 3 : return;
                case 4 : exit(0); 
                default : cout << "Invalid Entry\n";
            }
        }
    }
    if(!flag)
    {
        cout << "Code not found\n";
    }
}
int main()
{   
    int choice;
    int i = 0;
    int count = 0;
    while(1)
    {   
        cout << "1.Create\n2.Update\n3.Display\n4.Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1 : 
                count++;
                m[i].create();
                break;
            case 2 :
                update(count);
                break;
            case 3 :
                cout << "code" << "\t\t" << "name" << "\t\t" << "pay" << "\t\t" << "exp" << "\t\t" << endl;   
                for(int i = 0; i < count; i++)
                    m[i].display();
                break;
            case 4 : exit(0);

            default : cout << "Invalid Entry\n"; break;
        }

        i++;
    }
        return 0;
}