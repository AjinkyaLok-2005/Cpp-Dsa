#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<string> s;

    s.push("ajinkya");
    s.push("nitin");
    s.push("lokhande");

    cout << "Top element -> " << s.top() << endl; 

    s.pop();
    cout << "Top Element -> " << s.top() << endl;

    cout << "size of stack " << s.size() << endl;

    cout << "Empty or not " << s.empty() << endl;

    return 0;
}