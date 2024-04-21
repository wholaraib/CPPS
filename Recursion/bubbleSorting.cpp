// this programs does bubble sorting
#include <iostream>
#include <cstdlib>
using namespace std;
void bubbleSort(int *arr, int n)
{
    if (n == 0 || n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSort(arr, n - 1);
}
int main()
{
    int arr[] = {10, 7, 9, 3, 14, 1};
    int n = 6;
    int i = 0;
    bubbleSort(arr, n);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
}