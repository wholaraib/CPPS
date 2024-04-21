#include <iostream>
using namespace std;
/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
return true if target exist in the matrix 
else return false
*/

/*IDEA IS TO APPLY BINARY SEARCH IN EACH ROW*/
bool binSearch(int arr[][5],int m, int n, int target)
{   

    for(int i = 0; i < m; i++)
    {
        int s = 0;
        int e = n - 1;
        int mid = s + (e-s)/2;
        while(s<=e)
        {
            if(arr[i][mid] == target)
                return true;
            else if(arr[i][mid] < target)
            {
                s = mid + 1;
            }
            else
                e = mid - 1;

            mid = s + (e-s)/2;
        }
    }
    return false;
}

int main()
{   
    int arr[5][5] = {
                    {1,4,7,11,15},
                    {2,5,8,12,19},
                    {3,6,9,16,22},
                    {10,13,14,17,24},
                    {18,21,23,26,30}
                    }; 
    int rows = 5;
    int cols  = 5;
    int target = 16;
    int result = binSearch(arr,rows,cols,target);
    cout << result << endl;


}