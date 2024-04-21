#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // creating the new arrays of the respective lengths
    int *first = new int[len1];
    int *second = new int[len2];

    // copying the values of the array recieved in the function into our newly created array
    int mainArrayIndex = s; // first array starts from s
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1; // second array starts from mid + 1
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // now merging the two arrays into sorted order
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    /*the thing is that we have two pointers index1 and index2 pointing at their respective arrays but a point will come when one of the pointer will traverse it's array completely and this statement will become false "[ while (index1 < len1 && index2 < len2) ]" so it will come out of the while loop. But there may be a pointer among index1 and index2 that would have not traversed it's array completely and hence it's element would have not stored in our main array so to store those remaining element we have created two more while loops 
    1) "[ while (index1 < len1) ]"
    2)"[ while (index2 < len2) ]"
    after this first while loop i.e "[ while (index1 < len1 && index2 < len2) ]."
    */
    
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // if any array that has been divided are unequal in sizes then
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int m = s + (e - s) / 2; // mid value

    // we are only dividing the array one time and rest the recursion will handle for every division that will take place in each call of mergeSort function

    mergeSort(arr, s, m); // sorting the left part

    mergeSort(arr, m + 1, e); // sorting the right part

    merge(arr, s, e); // merging the two sorted arrays
}
int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}