// https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// https://leetcode.com/problems/set-matrix-zeroes/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int> > mp;
    int nums[3][4] = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    int row = 3;
    int col = 4;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (nums[i][j] == 0)
                mp.push_back(make_pair(i, j));
        }
    }

    // for(int i = 0; i < mp.size(); i++)
     vector<pair<int,int> > :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        int j = 0;
        while(j < col)
        {
            nums[it->first][j] = 0;
            j++;
        }
        j = 0; 
        while(j < row)
        {
            nums[j][it->second] = 0;
            j++;
        }

    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

}