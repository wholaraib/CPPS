#include <iostream>
using namespace std;
int helper(int arr[], int n, int target, int s, int e)
{
    int m = s + (e-s)/2;
    if(s > e)
        return -1;
    if(arr[m] == target)
        return m;
    else if(arr[m] > target)
    {
        return helper(arr,n,target,s,m-1);
    }   
    else{
        return helper(arr,n,target,m+1,e);
    }

}
int binarySearch(int arr[], int n, int target)
{
    int s = 0;
    int e = n - 1;
    return helper(arr,n,target,s,e);
}
int main()
{   
    int arr[] = {1,2,4,5,7,9,12};
    int target = 9; 
    int n = sizeof(arr)/sizeof(int);
    cout << binarySearch(arr,n,target) << endl;
}
