#include <iostream>
#include <vector>
using namespace std;

void printVector(vector <int> &ans)
{
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*Code Ques Link : https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_6&leftPanelTab=0*/

int main()
{   
    int arr[3][4] = {{6,5,3,2},{9,11,1,4},{8,10,7,15}};
    int nrows = 3; // Number of rows
    int ncols = 4; //Number of columns
    vector <int> ans;
    //this for loop is for accessing one by one column
    for(int col = 0; col < ncols; col++)
    {
        //Draw the 2D array in a copy and you will observe for odd column number we are printing the elements from bottom to top and for even col number we are printing the element from top to bottom

        if(col&1) // for odd index --> since an odd number in binary form has 1 at its end therefore this "IF" condition is true for odd numbers and for odd numbers we will print the elements from bottom to top.
        {
            for(int c = nrows - 1; c >= 0; c--)
            {
                ans.push_back(arr[c][col]);
            }
        }
        else // for even index --> as all even numbers have 0 at the end in their binary form so for even number column the above IF condition won't satisfy i.e (col&1) will give 0 as {0 & 0 = 0} therefore for even column number we will print from top to bottom.
        //as column 0 is neither odd nor even therefore it will also be printed in this odd condition
        {
            for(int r = 0; r <= nrows - 1; r++)
            {
                ans.push_back(arr[r][col]);
            }
        }
    }
    printVector(ans);
}