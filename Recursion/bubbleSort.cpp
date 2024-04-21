//This program checks whether the array is sorted or not using bubble sort
#include <iostream>
using namespace std;
bool helper(int arr[], int size,int i)
{
    if(i == size - 1)
        return true;
    if(arr[i] > arr[i+1])
        return false;
    return helper(arr,size,i+1);
}
bool bubbleSort(int arr[],int size)
{
    return helper(arr,size,0);
}
int main()
{   
    // int arr[] = {2,1,3,4,7};
    // int arr[] = {1,2,3,4,5};
    int arr[] = {1,6,3,8,5};
    // int arr[] = {41,72,114,326,441};
    int size = sizeof(arr)/sizeof(int);
    if(bubbleSort(arr,size))
        cout << "The given array is SORTED" << endl;
    else   
        cout << "The given array is NOT SORTED" << endl;

}