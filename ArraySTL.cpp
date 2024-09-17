#include<iostream>
#include<array>

using namespace std;

int main()
{
    int basic[3] = {1,2,3};
    array<int, 4> arr = {1, 2, 3, 4};

    int size = arr.size();

    for(int i=0; i < size; i++)
    {
        cout << arr[i] << " ";

    }
    cout << endl;

    cout << " element at 2nd index " << arr.at(2) << endl;
    cout << " empty or not " << arr.empty() << endl; //bool value
    cout << " first element " << arr.front() << endl;
    cout << " last element" << arr.back() << endl;
    

    return 0;
}
