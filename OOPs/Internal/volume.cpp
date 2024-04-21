#include <iostream>
#include <cmath>
using namespace std;
class VOLUME
{
private:
    static int count;
    double length = 0, width = 0, height = 0, radius = 0, side = 0;
public:
    VOLUME()
    {
        count++;
    }
    VOLUME(double s)
    {
        count++;
        side = s;
    }
    VOLUME(double l, double w, double h)
    {
        count++;
        length = l;
        width = w;
        height = h;
    }
    VOLUME(double r, char c)
    {
        count++;
        if (c == 's')
        {
            side = r;
        }
        else if (c == 'r')
        {
            radius = r;
        }
    }
    VOLUME(double r, double h, char c)
    {
        count++;
        radius = r;
        height = h;
    }
    static int get_count()
    {
        return count;
    }
    ~VOLUME()
    {
        count--;
    }
    friend double compute(VOLUME v);
};
int VOLUME::count = 0;
double compute(VOLUME v)
{
    double volume;
    if (v.side > 0)
    {
        volume = pow(v.side, 3);
    }
    else if (v.length > 0 && v.width > 0 && v.height > 0)
    {
        volume = v.length * v.width * v.height;
    }
    else if (v.radius > 0)
    {
        if (v.height > 0)
        {
            volume =  M_PI * pow(v.radius, 2) * v.height / 3.0;
        }
        else
        {
            volume = 4.0 / 3.0 * M_PI * pow(v.radius, 3);
        }
    }
    return volume;
}
int main()
{
    VOLUME v1;
    VOLUME v2(2.0);
    VOLUME v3(1.0, 2.0, 1.0);
    VOLUME v4(3.0, 'r');
    VOLUME v5(1.0, 2.0, 'r');
    cout << "Number of objects created: " << VOLUME::get_count() << endl;
    double volume1 = compute(v1);
    double volume2 = compute(v2);
    double volume3 = compute(v3);
    double volume4 = compute(v4);
    double volume5 = compute(v5);
    cout << "Volume of cube with side 3: " << volume2 << endl;
    cout << "Volume of cuboid with length 2, width 4, and height 6: " << volume3 << endl;
    cout << "Volume of sphere with radius 5: " << volume4 << endl;
    cout << "Volume of cone with radius 4 and height 7: " << volume5 << endl;
    cout << "Number of objects remaining: " << VOLUME::get_count() << endl;
    return 0;
}