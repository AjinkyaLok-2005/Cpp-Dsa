#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> max;

    //min heap
    priority_queue<int, vector<int>, greater<int> > min;

    max.push(1);
    max.push(4);
    max.push(2);
    max.push(0);
    max.push(5);

    cout << "Size -> " << max.size() << endl;
    int n = max.size();

    for(int i = 0; i < n; i++)
    {
        cout << max.top() << " ";
        max.pop();
    }
    cout << endl;

    min.push(6);
    min.push(4);
    min.push(1);
    min.push(2);
    min.push(3);

    int m = min.size();
    for(int i = 0; i < n; i++)
    {
        cout << min.top() << " ";
        min.pop();
    }
    cout << endl;

    cout << "Is empty " << min.empty() << endl;
    

    return 0;
}