/*
Write a C++ program to create a class called STUDENT with data members USN, Name and Age. 
Using Inheritance, create the classes. UGSTUDENT and PGSTUDENT having fields as Semester, Fees and Stipend. 
Enter the data for at least 5 students and validate the semester.
Find the semester wise average age for all UG and PG students separately.
*/
#include <iostream>
using namespace std;
class Student
{

    char name[30];
    int usn;
protected:
    int age;
public:
    void get_data()
    {
        cout << "\nEnter Name, USN and Age of the Student:\n";
        cin >> name >> usn >> age;
    }
    void display()
    {
        cout << name << "\t\t" << usn << "\t\t" << age << "\t\t";
    }
};
class ug : public Student
{
    float fees, stipend;
protected:
    int sem;
public:
    void get_data()
    {
        Student :: get_data();
        cout << "\nEnter Sem, Fee and Stipend of the Student:\n";
        cin >> sem >> fees >> stipend;
    }
    void show()
    {
        Student :: display();
        cout << sem << "\t\t" << fees << "\t\t" << stipend;
    }
    friend void average_age(ug a[], int n);
};
void average_age(ug a[], int n)
{
    int avg;
    for (int i = 0; i < 8; i++)
    {
        int no = 0;
        avg = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j].sem == i)
            {
                no++;
                avg += a[j].age;
            }
        }
        if (avg != 0)
        {
            avg = avg / no;
            cout << i << " Sem UG student average = " << avg << endl;
        }
    }
}
class pg : public Student
{
    float fees, stipend;

protected:
    int sem;

public:
    void get_data()
    {
        Student ::get_data();
        cout << "\nEnter Sem, Fee and Stipend of the Student:\n";
        cin >> sem >> fees >> stipend;
    }
    void show()
    {
        Student ::display();
        cout << sem << "\t\t" << fees << "\t\t" << stipend;
    }
    friend void average_age(pg b[], int n);
};
void average_age(pg b[], int n)
{
    int avg;
    for (int i = 0; i < 8; i++)
    {
        int no = 0;
        avg = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[j].sem == i)
            {
                no++;
                avg += b[j].age;
            }
        }
        if (avg != 0)
        {
            avg = avg / no;
            cout << i << " Sem PG student average = " << avg << endl;
        }
    }
}
int main()
{
    int n1, n2;
    cout << "Enter the no. of UG students: ";
    cin >> n1;
    cout << "Enter the no. of PG students: ";
    cin >> n2;
    cout << endl;
    ug a[n1];
    pg b[n2];
    if (n1 != 0)
    {
        cout << "Enter details of " << n1 << " UG students: ";
        cout << endl;
        for (int i = 0; i < n1; i++)
        {
            a[i].get_data();
        }
        cout << endl;
    }
    if (n2 != 0)
    {
        cout << "\nEnter details of " << n2 << " PG students: \n";
        for (int i = 0; i < n2; i++)
        {
            b[i].get_data();
        }
        cout << "\n\n\n";
    }
    if (n1 != 0)
    {
        cout << "UG student details: " << endl;
        cout << "\nName\t\tUSN\t\tAge\t\tSem\t\tFees\t\tStipend" << endl;
        for (int i = 0; i < n1; i++)
        {
            a[i].show();
        }
        cout << "\n\n";
        average_age(a, n1);
        cout << "\n\n";
    }
    if (n2 != 0)
    {
        cout << "PG student details: " << endl;
        cout << "\nName\t\tUSN\t\tAge\t\tSem\t\tFees\t\tStipend" << endl;
        for (int i = 0; i < n2; i++)
        {
            b[i].show();
        }
        cout << "\n\n";
        average_age(b, n2);
        cout << "\n\n";
    }
    return 0;
}