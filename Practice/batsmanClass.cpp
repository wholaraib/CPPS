#include <iostream>
#include <string>
using namespace std;
class Batsman
{
	int bcode;
	string bname;
	int innings;
	int noutout;
	int runs;
	float batavg;
	
	public:
		void readData();
		void displayData();
		void calAvg(){
			batavg = runs/(innings - noutout);
		}
};
void Batsman::readData()
{
	cout << "Enter Batsman code : ";
	cin >> bcode;
	cout << "Enter Batsman name : ";
	cin.ignore();
	getline(cin,bname);
	cout << "Enter the number of innings : " ;
	cin >> innings;
	cout << "Enter the number of notout innings : ";
	cin >> noutout;
	cout << "Enter the total runs : ";
	cin >> runs;
	calAvg();
}
void Batsman::displayData()
{
	cout << "Batsman Code : " << bcode << endl;
	cout << "Batsman Name : " << bname << endl;
	cout << "Total Innings : " << innings << endl;
	cout << "Total NotOut Innings : " << noutout << endl;
	cout << "Total runs : " << runs << endl;
	cout << "Batting average : " << batavg << endl;
}
int main()
{   
	Batsman b1;
	b1.readData();
	b1.displayData();
	return 0;
}