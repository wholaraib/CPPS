#include <iostream>
using namespace std;

class Time
{
    int d, h, m, s;
public:
    void readIp();
    void calc(Time t1, Time t2);
    void display();
};

void Time ::readIp()
{
    cout << "Enter Time in hh/mm/ss: ";
    cin >> h >> m >> s;
}
void Time :: calc(Time t1, Time t2)
{
    d = 0;
    s = t1.s + t2.s;
    m = t1.m + t2.m + s / 60;
    h = t1.h + t2.h + m / 60;
    if (h > 24)
    {

        d += h / 24;
    }
    s = s % 60;
    m = m % 60;
    h = h % 24;
    display();
}
void Time ::display()
{
    cout << "Resultant Time is (dd/hh/mm/ss): " << d << " : " << h << " : "<< m << " : " << s; 
}

int main()
{
    Time t1, t2, t3;
    t1.readIp();
    t2.readIp();
    t3.calc(t1, t2);
    return 0;
}
