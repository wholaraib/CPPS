#include <iostream>
#include <vector>
using namespace std;
vector <int> findAllIndices(int arr[], int target, int i, vector <int> ans, int n)
{
    if(i == n)
        return ans;
    if(arr[i] == target){
         ans.push_back(i);
    }
    return findAllIndices(arr,target,i+1,ans,n);
}
int main()
{   
    vector <int> ans;
    vector <int> ans1;
    int arr[] = {1,5,6,4,4,7};
    int n = sizeof(arr)/sizeof(int);
    int target = 4;
    int i = 0;
    ans1 = findAllIndices(arr,target,i,ans,n);
    for(int i = 0; i < ans1.size();i++)
        cout << ans[i] << " ";
    return 0;

}