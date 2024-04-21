#include <iostream>
#include <vector>
using namespace std;
//Function to print vector of pairs
void printvec(vector<pair<int,int> > &v)
{
    //printing using iterators

    // also instead of *it.first we can also use (it->first). In the code just below we have used both (it->first) method as well as *it.first
    vector<pair<int,int> > :: iterator it;
    for(it = v.begin(); it != v.end(); ++it)
    {
        cout << (it->first)  << " " << (*it).second << endl;
    }

    //printing without any iterator

    // for(int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].first  << " " << v[i].second << endl;
    // }
    // cout << endl;
}

int main()
{   
    //declaration of vector of pairs
    vector<pair<int,int> > v;

    //storing values in vector of pairs

    //METHOD 0
    //vector<pair<int,int> > v = {{1,2},{3,4},{5,9}};
    //this method does not work in my system

    //METHOD 1 

    int n,x,y;
    cout << "Enter number of pairs you want to enter in the vector: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {   
        cout << "Enter " << i + 1 << " pair : ";
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    } 
    printvec(v);

    //swapping pairs
    // swap(v[1],v[3]);
    
    // printvec(v);

}   