#include <iostream>
#include <map>

using namespace std;
void print(map<int, string> &m)
{
    map<int, string>::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
}
/*!!!!!!!!  KEEP IN MIND  !!!!!!!!!*/
// "m" is the name of the map and therefore it can be anything
// all the functions use below use "m" like m.begin, m.end etc so keep in mind that it is just the name of the map

int main()
{ // map declaration
    map<int, string> m;

    // inserting values in map
    m[3] = "Laraib";
    m[4] = "Fuzail";
    m[1] = "Huzaifa";
    m[2] = "Zohaib";

    // another way of inserting values in maps, here idea is to insert a pair inside the map
    //  m.insert({5,"Mohammad"}); --> this doesn't work here but it is also a way to insert values in maps
    //  we can also do it by using make_pair command
    m.insert(make_pair(5, "hello"));

    // PRINTING MAP VALUES

    // with the help of the iterator

    map<int, string>::iterator it; // <--declaring the iterator
    // using for loop to print map values
    //  m.begin will point at the first element of the map and m.end is the iterator next to the iterator of the last element
    cout << "Printing with the help of iterator : " << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        // now since maps are storing a pair, there are two methods to print a pair
        cout << (*it).first << " " << it->second << endl;
        // OR we can print it like this
        //  cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    // Now instead of using this iterator we can also print map elements with the help of auto keyword in for loop
    cout << "Printing with the help of auto keyword : " << endl;
    for (auto &pair : m)
    /* "pair" is variable given by user, we can name it anything and "m" is the name of the map
    also, we have used "ampercent" pair i.e &pair so that a copy of pair is not created everytime we run our code
    */
    {
        cout << pair.first << " " << pair.second << endl;
    }

    cout << endl;

    // SIZE of MAP function
    cout << "Size of map is " << m.size() << endl;

    cout << endl;

    // FINDING VALUES WITH THE HELP OF THE KEY

    // To find a value in a map with the help of the key we use m.find(key) fucntion and this function takes the key in input and returns the iterator pointing towards the value stored in the that particular key

    // suppose there is no value with reference to the key in our map then this function will return m.end i.e the iterator next to the iterator of the last element

    /*
        METHOD 1

        auto it1 = m.find(3);
        if(it1 == m.end())
            cout << "No value with respect to this key" << endl;
        else
            cout << (*it1).first << " " << (*it1).second << endl;

    */
    // METHOD 2

    // instead of using auto keyword we can also declare the iterator and then use m.find() fucntion
    cout << "USING FIND FUNCTION : " << endl;
    map<int, string>::iterator it1;
    it1 = m.find(5);
    if (it1 == m.end())
        cout << "No value with respect to this key" << endl;
    else
        cout << (*it1).first << " " << (*it1).second << endl;

    cout << endl;
    // ERASING VALUES

    // We can erase values with the help of m.erase function
    // this fucntion takes two kinds of input :
    //   i) the value of key
    //  ii)  the iterator

    // erasing with the help of the key
    cout << "ERASING with the help of the key: " << endl;

    m.erase(3);
    print(m);

    cout << "ERASING with the help of the iterator: " << endl;

    // erasing with the help of the iterator

    it1 = m.find(2); // this iterator was previously declared in this code

    // suppose we try to delete a value with the help of the key which is not present in our map then a segmentation fault will occur so it's better to use if condition while erasing i.e if our iterator is not pointing towards m.end() the only erase:

    if (it1 != m.end()) m.erase(it1);
    
    print(m);

    // CLEARING
    // m.clear will clear whole map
}