#include <iostream>
#include <vector>
using namespace std;
int main()
{   
    //Number of rows of 2d vector
    // int numofrow = matrix.size();
    //Numbber of columns of 2d vector
    // int numofcol = matrix[0].size();

    int r;
    int num;
    cout << "Enter number of vector rows : " ;
    cin >> r;

    //Inputting values in a 2d vector
    vector < vector <int> > matrix;

    for(int i = 0; i < r; i++)
    {
        cout << "Enter number of elements for row " << i+1 <<  " : "; 
        cin >> num;
        vector <int> temp;
        cout << "Enter " << num << " elements : ";
        for(int j = 0; j < num; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    //calculating rows and cols
    int numofcol = matrix[0].size();
    int numofrow = matrix.size();
    cout << "Number of Columns are " << numofcol << endl;
    cout << "Number of Rows are " << numofrow << endl;

    //printing vector elements
    for(int i = 0; i < numofrow; i++)
    {
        for(int j = 0; j < numofcol; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Reverse Matrix : " << endl;
    reverse(matrix.begin(),matrix.end());
    for(int i = 0; i < numofrow; i++)
    {
        for(int j = 0; j < numofcol; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "Col Reverse Matrix : " << endl;
    reverse(matrix[0].begin(),matrix[0].end());
    for(int i = 0; i < numofrow; i++)
    {
        for(int j = 0; j < numofcol; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}