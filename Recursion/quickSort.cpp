// Quick Sort
#include <iostream>
using namespace std;
int partition(int arr[], int s, int e)
{
    int pivot = arr[s]; // finding the pivot element

    int cnt = 0;
    for (int i = s + 1; i <= e; i++) // counting the number of elements less than pivot
    {
        if (arr[i] <= pivot) cnt++;
    }
    
    int pivotIndex = s + cnt; // finding the right position of the pivot element in the array such that all the elements on it's left will be less than pivot element and all the elements on it's right will be greater than pivot element

    swap(arr[pivotIndex], arr[s]); // placing the pivot element on it's right position

    int i = s, j = e; // making two pointers

    while (i < pivotIndex && j > pivotIndex) // checking each element apart from pivot element such that it follows the condition that all the elements on it's left will be less than pivot element and all the elements on it's right will be greater than pivot element
    {
        while (arr[i] < arr[pivotIndex])
            i++;
        while (arr[j] > arr[pivotIndex])
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}
void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    // partition of the array from the pivot element
    int p = partition(arr, s, e);

    // sorting the left part of the array
    quickSort(arr, s, p - 1);

    // sorting the right part of the array
    quickSort(arr, p + 1, e);
}
int main()
{
    // int arr[] = {-74,48,-20,2,10,-84,-5,-9,11,-24,-91,2,-71,64,63,80,28,-30,-58,-11,-44,-87,-22,54,-74,-10,-55,-28,-46,29,10,50,-72,34,26,25,8,51,13,30,35,-8,50,65,-6,16,-2,21,-78,35,-13,14,23,-3,26,-90,86,25,-56,91,-13,92,-25,37,57,-20,-69,98,95,45,47,29,86,-28,73,-44,-46,65,-84,-96,-24,-12,72,-68,93,57,92,52,-45,-2,85,-63,56,55,12,-85,77,-39};
    int arr[] = {2, 4, 1, 6, 9};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}