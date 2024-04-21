#include <iostream>
#include <iomanip>
using namespace std;
class Batsman
{
private:
    int code;
    string name;
    int innings;
    int notOut;
    int runs;

    void calcavg()
    {
        average = (float)runs / (innings - notOut);
    }
public:
    float average;
    void read()
    {
        cout << "Enter the batsman code: ";
        cin >> code;
        cout << "Enter the batsman name: ";
        cin >> name;
        cout << "Enter the number of innings played: ";
        cin >> innings;
        cout << "Enter the number of not-out innings: ";
        cin >> notOut;
        cout << "Enter the number of runs scored: ";
        cin >> runs;
        calcavg();
    }

    void display()
    {
        cout << left << setw(15) << "Code" << setw(20) << "Name" << setw(15) << "Innings"
             << setw(15) << "Not Out" << setw(15) << "Runs" << setw(15) << "Average"
             << endl;
        cout << left << setw(15) << code << setw(20) << name << setw(15) << innings << setw(15) << notOut << setw(15) << runs << setw(15) << average << endl;
    }
};
int main()
{
    int n;
    cout << "Enter the number of batsmen: ";
    cin >> n;
    Batsman batsman[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the details for batsman " << i + 1 << ": " << endl;
        batsman[i].read();
    }
    cout << "The details of the batsmen are: " << endl;
    for (int i = 0; i < n; i++)
    {
        batsman[i].display();
    }
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (batsman[i].average > batsman[maxIndex].average)
        {
            maxIndex = i;
        }
    }
    cout << "The best batsman is: " << endl;
    batsman[maxIndex].display();
    return 0;
}
