#include <iostream>
using namespace std;
//if u want true or false;
bool linearSearch(int arr[],int size,int target,int i)
{   
    if(i == size)
        return false;
    return (arr[i] == target || linearSearch(arr,size,target,i+1));
}

//if u want index
// int linearSearch(int arr[],int size,int target,int i)
// {   
//     if(i == size)
//         return -1;
//     if(arr[i] == target)
//         return i;
//     return linearSearch(arr,size,target,i+1);
// }

int main()
{   
    int arr[] = {1,3,6,5,4};
    int size = sizeof(arr)/sizeof(int);
    int target = 3;
    cout << linearSearch(arr,size,target,0) << endl;
}