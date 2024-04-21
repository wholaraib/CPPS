    #include <iostream>
#include <vector>
using namespace std;
int main()
{
    //Declaration of  a vector
    vector <int> v;
    //Inserting elements in a vector using push_back.
    int x;
    int num_of_elements = 5;
    cout << "Enter " << num_of_elements << " vector elements: ";
    for(int i = 0; i < num_of_elements; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cout << "Printing vector elements: \n";


    // METHOD 1
    //printing vector elements using for loop
    cout << "Using proper for loop: ";
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // METHOD 2
    //We can also print vector using range based loop like this but it gives a warning: 
    //Range based loop can be used in all of the containers.

    cout << "Using range based loop : ";
    for(int i : v)
    {
        cout << i <<  " ";
    }
    cout << endl;


    // METHOD 3
    
    /*Printing elements using iterator 
    iterator behaves just like pointers*/

    //Declaration a iterator
    vector<int>::iterator it;
    //running for loop for iterating through the elements
    //v.begin() points towards the first value and and similarly v.end points towards the value block(which is empty) next to last element 

    cout << "Using iterators : ";
    for(it = v.begin(); it!=v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;


    // METHOD 4
    //Using auto keyword ... auto keyword automatically detects whether the data type. In this case it is int and then we print it. It is quite similar to our METHOD 2. 
    //Auto keyword also gives warning.
    cout << "Using auto keyword: ";
    for(auto i : v)
    {
        cout << i << " ";
    }
      cout << endl;

    //IMPORTANT
    /*In Method 3 while using iterators when we declare a iterator using this 
    statement --> vector<int>::iterator it;
    Instead of using this long statement we can use auto keyword.
    Auto keyword automatically idtentifies the type of the iterator i.e it will automatically identify that iterator is being used for which container like in vectors, pairs, vector of pairs etc.
    BELOW WE WILL SEE HOW TO USE auto KEYWORD IN THIS CASE:
    */

   cout << "Using iterators but with auto keyword : ";
    for(auto it = v.begin(); it!=v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl << endl;



    // sorting vector elements
    cout << "Here we have sorted the vector elements: " << endl;
    sort(v.begin(),v.end());

    cout << "Sorted vector elements are: ";
    for(auto element : v)
    {
        cout << element << " ";
    }   
    cout << endl;
   

    



}