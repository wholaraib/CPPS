//bubble sort
#include <iostream>
#include <vector>
using namespace std;
vector <int> bubbleSort(vector <int> arr)
{
    for(int i = 0; i < arr.size() - 1; i++)
    {
        for(int j = 0; j < arr.size() - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    return arr;
}
int main()
{   
    vector <int> arr;
    vector <int> resultantArr;
    arr.push_back(11);
    arr.push_back(6);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(56);
    arr.push_back(4);
    resultantArr = bubbleSort(arr);

    for(int i = 0; i < arr.size(); i++)
        cout << resultantArr[i] << " ";

    return 0;
}