#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for(auto i : s)
    //auto: The compiler will automatically determine the data type of "i" 
    //based on the elements in the container s
    {
        cout << i << endl;
    }
    cout << endl;

set<int>:: iterator it = s.begin();
it++;
//:: iterator it :- Declares an iterator named it that can be used to traverse the set.
//= s.begin(); :- Assigns the iterator it to point to the beginning of the set s.

    s.erase(it);

    for(auto i : s)
    {
        cout << i << endl;
    }

cout << endl;
cout << "5 is present or not -> " << s.count(5) << endl;

    set<int>::iterator itr = s.find(5);

    for(auto it = itr; it != s.end(); it++)
    //auto it = itr initializes an iterator 'it' with the value of 'itr' 
    //(which points to the element 5 or the end of the set).


    //The loop continues as long as it is not equal to s.end(), 
    //which represents the end of the set.
    {
        cout << *it << " ";
        //Inside the loop, the value of the current element 
        //pointed to by 'it' is printed followed by a space.
    }
    cout << endl;

    return 0;

}

//insert, find, erase, count all have time complexity O(log N)
// size, begin, end, empty all have time complexity O(1)