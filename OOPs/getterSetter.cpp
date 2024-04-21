#include <iostream>
// #include "hero.cpp"
using namespace std;
class Hero
{
    private :
    char level;
    int power;
    int health;
    public :
    void setLevel(char lev)
    {   
        level = lev;
    }
    char getLevel()
    {
        return level;
    }
    void setHealth(int h)
    {
        health = h;
    }
    int getHealth()
    {
        return health;
    }

};
int main()
{   
    Hero h1;
    h1.setHealth(50);
    h1.setLevel('B');
    cout << h1.getHealth() << endl;
    cout << h1.getLevel() << endl;

} 