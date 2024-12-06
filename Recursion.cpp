#include<iostream>
using namespace std;

int power(int n)
{

    //base case
    if(n == 0)
    {
        return 1;
    }

    //recursive relation
    // int smallerProblem = power(n-1);
    //int biggerProblem = 2 * smallerProblem;

    return 2 * power(n-1);
}

void print(int n) //2^n wala question
{
    //base case
    if(n == 0)
    {
        return ;
    }

    cout << n << endl;

    //recursive relation
    print(n-1);
}

int main()
{
    int n; 
    cin >> n;

    // int ans = power(n);

    // cout << ans << endl;

    cout << endl;
    print(n);

    return 0;
}