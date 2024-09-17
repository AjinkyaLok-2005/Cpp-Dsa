#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> a(5,1);
//If we know the size of the vector that we want to create then we 
//can do it like this
//(size, no.with which the vector is to be initialized)
//by default it id initialized with zero, i.e, all elements are equal to zero 

    vector<int> last(a);
    //If we want to copy a in another vector

    cout << "print a " << endl;
    for (int i:a)
    {
        cout << i << " ";
    }
    cout << endl;


    vector<int> v;
    cout << "Capacity -> " << v.capacity() << endl;

    v.push_back(1);
    cout << "Capacity -> " << v.capacity() << endl;

    
    v.push_back(2);
    cout << "Capacity -> " << v.capacity() << endl;

    v.push_back(3);
    cout << "Capacity -> " << v.capacity() << endl;
    //At each insertion the size of the vector gets doubled
    cout << "Size -> " << v.size() << endl;

    cout << "element at 2nd index  " << v.at(2) << endl;

    cout << "front " << v.front() << endl;
    cout << "back " << v.back() << endl;

    cout << "before pop " << endl;
    for (int i:v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

    cout << "after pop " << endl;
    for (int i:v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "before clear size " << v.size() << endl;
    v.clear();
    cout << "after clear size " << v.size() << endl;





    vector<int> numbers = {1, 2, 3, 4, 5};
    // Using iterator to print elements
    vector<int>::iterator it;
    for (it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}