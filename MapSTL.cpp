#include<iostream>
#include<map>
using namespace std;

// Data is stored in key and value pair
//Every key is unique
//same key can not point to two different values
//values can be same

int main()
{
    map<int, string> m;

    m[1] = "Ajinkya";
    m[2] = "BMW";
    m[3] = "1350 GS";
    m[13] = "Z4";

    m.insert({5, "GT3 RS"});


    cout << "before erase" << endl;


    for(auto i : m)
    {
        cout << i.first << " " << i.second << endl;;
    }

    cout << "finding 13 -> " << m.count(13) << endl;
    cout << "finding -13 -> " << m.count(-13) << endl;

    m.erase(13);
    cout << "After Erase " << endl;

    for(auto i : m)
    {
        cout << i.first << " " << i.second << endl;;
    }

    auto it = m.find(5);

    for(auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << endl;
    }

    return 0;
}