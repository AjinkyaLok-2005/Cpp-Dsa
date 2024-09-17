#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<string> q;

    q.push("ajinkya");
    q.push("lokhande");
    q.push("nitin");

    cout << "Size before pop " << q.size() << endl;

    cout << "First element " << q.front() << endl;

    q.pop();

    cout << " Size after pop " << q.size() << endl;
    
    cout << " First element " << q.front() << endl;

    return 0;
}