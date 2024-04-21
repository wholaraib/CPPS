#include <iostream>
#include <vector>
using namespace std;
void printvector(vector <int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{   
    int N;
    
    cout << "Enter the number of vectors you want: ";
    cin >> N;
    //These are the number of vectors .. say N = 3 then it will create 3 vectors of zero size. i.e v[0] is vector in itself, v[1] is a vector in itself and similarly v[2].
    //declaration of array of vectors.
    vector <int> v[N];

    //first for loop is for inputting size of each vector one by one.
    for(int i = 0; i < N; i++)
    {
        //n is the size of each vector.
         int n;
         cout << "Enter the size of vector " << (i + 1) << " : ";
         cin >> n;
         //second for loop is for inputting 'n' elements in each vector
         for(int j = 0; j < n; j++)
         {
            //here we have to put (j)J'th value in (i)I'th vector

            //x is the one by one being inserted value in each vector
            int x;
            cout << "Enter " << (j + 1)  << " element of vector " << (i + 1) << " : ";
            cin >> x;
            v[i].push_back(x);
         }
    }
    //printing every vector using for loop as there are many vectors since it is an array of vectors


    for(int i = 0; i < N; i++)
    {
        printvector(v[i]);
    }

}