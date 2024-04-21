#include <iostream>
using namespace std;
/*Program to find the first and last occurrence of a element in the array*/ 
/*---------------------------------------------------------------------------------------*/
/*First we will be finding the first occurrece of our key element in the array or we can say the first occurrence of our key element will be the left most occurrence of that element in the array. For eg: {0,1,2,2,3,3,3,4,5}, In this array the first occurrence of 3 (say 3 is a key) is also the left most occurrence of 3 in that array.*/
int firstocc(int arr[],int n, int key)
{

    /*Logic is same as Binary search only this (marked below with * *) condition is changed i.e if our key matches with our mid index element then we will store that index in a variable and since we are finding the first/left occurrence of our key element therefore we need to search for the key element in left part of the array that if there is any other element that is equal to our key that is present is the left part of the array . If it is present then it will become the left most element our the first occurrence of our key element*/

    int s = 0, e = n - 1;
    int ans = -1;
    
    while(s <= e)
    {   
        int mid = s + (e - s)/2;
        if(arr[mid] == key)
        {
            //*This conditon*
        ans = mid;
        //Since searching the first occurrence therefore to go on the left side of the array we updated our end (e) with mid - 1 therefore now we will be searching in the left most part of the array 
        e = mid - 1;
        //*till here*
        }

        else if(key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int lastocc(int arr[],int n,int key)
{
    /*Similarly like first/left-most occurrence the logic of last/right-most occurrence is. Understand it */
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
        {
            e = mid - 1;
        }
     }
     return ans;
}

int main()
{
    int arr[] = {0,1,2,2,3,3,3,4};
    int n = sizeof(arr)/sizeof(int);
    int key = 2;
    cout << "The first occurrence of " << key  << " " << firstocc(arr,n,key) << endl;
    cout << "The last occurrence of " << key  << " " << lastocc(arr,n,key) << endl;
}
    