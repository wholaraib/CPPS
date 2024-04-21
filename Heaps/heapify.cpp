#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(arr[largest] < arr[left])
    {
        largest = left;
    }
    if(arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void print(int arr[], int n)
{
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
int main()
{       
    int arr[5] = {54,53,55,52,50};
    int n = 5;
    cout << "Before heapifying:\n";
    print(arr,n);
    for(int i = 0; i < n/2-1; i++)
    {
        heapify(arr,n,i);
    }
    cout << "After heapifying:\n";
    print(arr,n);
}