/*In this question we will find total occurrence of a number using binary search*/
#include <iostream>
using namespace std;
/*First and last occurrence logic is present in firstandlast.cpp file 
Here everything is same as first and last occ question except (go below)*/
int firstocc(int arr[],int n,int key)
{
    int s = 0, e = n - 1;
    int ans = -1;
    while(s<=e)
    {
        int mid = s + (e - s)/2;
        if(arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid])
        {
            s = mid + 1;
        }
        else
        e = mid - 1;
    }
    return ans;
}
int lastocc(int arr[],int n,int key)
{
    int s = 0, e = n - 1;
    int ans = -1;
    while(s<=e)
    {
        int mid = s + (e - s)/2;
        if(arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid])
        {
            s = mid + 1;
        }
        else
        e = mid - 1;
    }
    return ans;
}
int main()
{
    int arr[] = {1,2,2,3,3,3,3,3,3,3,3,4},key;
    int n = sizeof(arr)/sizeof(int);
    key = 3;
    int l = firstocc(arr,n,key);
    int r = lastocc(arr,n,key);
    /*Here we are finding the total occurrence of a number in the array.
    Formula is : rightmost/last occ - leftmost/first occ + 1 try this formula in copy you will understand*/
    int total = r - l + 1;
    cout << "Total occurrence of " << key << " is " << total << endl;


}