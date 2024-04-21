#include <iostream>
#include <cstdlib>
using namespace std;
void search(int matrix[][4], int key)
{
    
    int n = 12;
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s)/2;
    int row = 3;
    int col = 4;
    int ele;

    while(s<=e)
    {
        ele = matrix[mid/col][mid%col];
        if(key == ele){
            cout << "Element found at index " << mid/col << mid%col << endl;
            exit(0);
        }
        else if(ele > key)
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e - s)/2;            
    }
    cout << "Element not found " << endl;
}
int main()
{   
    int matrix[3][4] = {{2,3,6,8},{11,12,14,17},{23,26,43,48}};
    int key;
    cout << "Enter the key element to be searched: " << endl;
    cin >> key;

    search(matrix,key);
}
