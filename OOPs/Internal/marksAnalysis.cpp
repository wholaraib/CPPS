/*
Write a C++ program to do student mark analysis using static data
member, default argument and friend function for class.
Define a class student with data members USN, total, ml, m2, m3, name,
grade, avg and static variable count.
Member functions: to read data, to calculate average and grade and to
display the data. Define one more class with name personal with
data members address and mobile number and member functions to read data
and to display. Include the following specification to the program,
Define function by name grade_point (to raise flag for pass) with default
value 50.
Define printline function (to print a line) with default value 70 for
range and "*" for line.
Make display function as friend for both classes.
Use static members to keep a count of passed students.
*/
#include <iostream>
#include <iomanip>
using namespace std;
// forward declaration
class Personal;
// student class
class Student
{
private:
    string usn, name;
    int m1, m2, m3, total;
    float avg;
    char grade;
    static int count;
public:
    void read_data();
    void calculate();
    void display();
    friend void display_data(Student s, Personal p);
    static int get_count() { return count; }
};
// personal class
class Personal
{
private:
    string address, mobile;
public:
    void read_data();
    void display();
    friend void display_data(Student s, Personal p);
};
// static member initialization
int Student::count = 0;
// function to calculate grade point based on marks and a default value
char grade_point(int marks, int pass_mark = 50)
{
    if (marks >= pass_mark)
    {
        return 'P';
    }
    else
    {
        return 'F';
    }
}
// function to print a line of given length and character
void printline(char c = '*', int length = 70)
{
    cout << setfill(c) << setw(length) << "" << setfill(' ') << endl;
}
// function to read student data
void Student::read_data()
{
    cout << "Enter USN: ";
    cin >> usn;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter marks in 3 subjects: ";
    cin >> m1 >> m2 >> m3;
}
// function to calculate average and grade for a student
void Student::calculate()
{
    total = m1 + m2 + m3;
    avg = total / 3.0;
    if (avg >= 90)
    {
        grade = 'S';
    }
    else if (avg >= 80)
    {
        grade = 'A';
    }
    else if (avg >= 70)
    {
        grade = 'B';
    }
    else if (avg >= 60)
    {
        grade = 'C';
    }
    else if (avg >= 50)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }
    if (grade_point(m1) == 'P' && grade_point(m2) == 'P' &&
        grade_point(m3) == 'P')
    {
        count++;
    }
}
// function to display student data
void Student::display()
{
    printline();
    cout << "USN: " << usn << endl;
    cout << "Name: " << name << endl;
    cout << "Marks: " << m1 << ", " << m2 << ", " << m3 << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << fixed << setprecision(2) << avg << endl;
    cout << "Grade: " << grade << endl;
    printline();
}
// function to read personal data
void Personal::read_data()
{
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter mobile number: ";
    cin >> mobile;
}
// function to display personal data
void Personal::display()
{
    printline();
    cout << "Address: " << address << endl;
    cout << "Mobile number: " << mobile << endl;
    printline();
}
// friend function to display student and personal data
void display_data(Student s, Personal p)
{
    s.display();
    p.display();
}
int main()
{
    Student s;
    Personal p;
    // read student and personal data
    int n;
    cout << "Enter number of students : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s.read_data();
        p.read_data();
        // calculate and display student data
        s.calculate();
        display_data(s, p);
    }
    // display count of passed students
    cout << "Number of passed students: " << Student::get_count() << endl;
    return 0;
}
