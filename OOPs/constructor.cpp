#include <iostream>
#include <string>
using namespace std;
/*
    Constructor in C++ is a special method that is invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally. The constructor in C++ has the same name as the class or structure. Constructor is invoked at the time of object creation. It constructs the values i.e. provides data for the object which is why it is known as constructors. Constructor does not have a return value, hence they do not have a return type.
*/
class student
{
    private : 
        int rollNum;
        string name;
        float fees;
    public :
        student()
        {
            cout << "Enter the Roll Number : ";
            cin >> rollNum;
            cout << "Enter the name of the student : ";
            cin >> name;
            cout << "Enter the total fees to be deposited : ";
            cin >> fees;
        }
    void display()
    {
        cout << "Roll Number : " << rollNum << endl;
        cout << "Name : " << name << endl;
        cout << "Fees  : " << fees << endl;
    }
};
int main()
{   
    student s1; // constructor gets called automatically when we create the object of the class
    s1.display(); //function calling
}