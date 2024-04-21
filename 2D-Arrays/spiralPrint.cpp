#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // Given Matrix

    // 1  2  3  4
    // 5  6  7  8
    // 9 10 11 12

    int rows = 3;
    int cols = 4;

    vector<int> ans;
    int count = 0;
    int total = rows * cols;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = rows - 1; // 2
    int endingCol = cols - 1; // 3

    while (count < total)
    {
        // printing first row
        for (int index = startingCol; count < total && index <= endingCol; index++)
        {
            ans.push_back(arr[startingRow][index]);
            // cout << arr[startingRow][index] << " ";
            count++;
        }
        startingRow++;

        // printing last column
        for (int index = startingRow; count < total && index <= endingRow; index++)
        {
            ans.push_back(arr[index][endingCol]);
            // cout << arr[index][endingCol] << " ";
            count++;
        }
        endingCol--;

        // printing last row
        for (int index = endingCol; count < total && index >= startingCol; index--)
        {
            ans.push_back(arr[endingRow][index]);
            // cout << arr[endingRow][index] << " ";
            count++;
        }
        endingRow--;

        // printing first column
        for (int index = endingRow; count < total && index >= startingRow; index--)
        {
            ans.push_back(arr[index][startingCol]);
            // cout << arr[index][startingCol] << " ";
            count++;
        }
        startingCol++;
    }
    printVec(ans);
}