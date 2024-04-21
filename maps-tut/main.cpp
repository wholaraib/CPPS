#include <iostream>
#include <iomanip>
using namespace std;
class batsman
{
private:
	int bcode;
	string bname;
	int innings;
	int notout;
	int runs;
	void calcAvg()
	{
		average = (float)runs / (innings - notout);
	}

public:
	float average;
	void getData()
	{
		cout << "Enter the batsman code : ";
		cin >> bcode;
		cout << "Enter the batsman name : ";
		cin >> bname;
		cout << "Enter the number of innings : ";
		cin >> innings;
		cout << "Enter the total notouts : ";
		cin >> notout;
		cout << "Enter the total runs : ";
		cin >> runs;
		calcAvg();
	}
	void show()
	{
		cout << left << setw(15) << "Code" << setw(20) << "Batsman name" << setw(15) << "Innings" << setw(15) << "Notout" << setw(15) << "Runs" << setw(15) << "Average" << setw(15) << endl;
		cout << left << setw(15) << bcode << setw(20) << bname << setw(15) << innings << setw(15) << notout << setw(15) << runs << setw(15) << average << setw(15) << endl;
	}
};
int main()
{
	int n;
	cout << "Enter the number of batsmen : ";
	cin >> n;
	batsman b[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the details of batsman " << i + 1 << ":\n";
		b[i].getData();
	}
	for (int i = 0; i < n; i++)
	{
		b[i].show();
	}
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b[i].average > b[index].average)
		{
			index = i;
		}
	}
	cout << "The best batsman is :\n";

	b[index].show();
	cout << endl;
}