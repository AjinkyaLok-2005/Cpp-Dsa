#include<iostream>

using namespace std;

int modularExponentation(int x, int n, int m)
{
    int res = 1;

    while(n>0)
    {
        if(n&1)
        {
            //odd
            res = (1LL * (res) * (x)%m)%m;
        }
        x = (1LL * (x)%m * (x)%m)%m;
        n = n>>1; //dividing n by 2 (right shift)
    }
    return res;
}

int main()
{
    int x = 3;
    int n = 1;
    int m = 2;

    int ans = modularExponentation(3,1,2);

    cout << "answer = " << ans << endl; 

    return 0;
}