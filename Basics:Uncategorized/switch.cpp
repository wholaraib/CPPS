#include <iostream>
using namespace std;
int main()
{
    int amt;
    cout << "Enter the amount: ";
    cin >> amt;
    int rs100,rs50,rs20,rs1;
    switch(1)
    {
        case 1 : rs100 = amt/100;
                    cout << "Rs 100 notes : " << rs100 << endl;

        case 2 : amt = amt - rs100*100;
                rs50 = amt/50;
                cout << "Rs 50 notes : " << rs50 << endl;

        case 3 : amt = amt - rs50*50;
                rs20 = amt/20;
                cout << "Rs 20 notes : " << rs20 << endl;

        case 4 : amt = amt - rs20*20;
                rs1 = amt/1;
                cout << "Rs 1 notes : " << rs1 << endl;
    }
}