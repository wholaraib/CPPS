#include <iostream>
// #include <string>
using namespace std;
struct candidates{
    char *name;
    int age;
    int height;
    float weight;
};
typedef struct candidates check;

int doc()
{
    check dr;
    dr.age = 45;
    if(dr.age > 29)
    return 12000;

    else
    return 0;
}
int main()
{   
    // can1.name = "laraib";
    check can1;
    check can2;
    can1.age = 21;
    can1.height = 185;
    can1.weight = 56;

    cout << doc() << endl;
}