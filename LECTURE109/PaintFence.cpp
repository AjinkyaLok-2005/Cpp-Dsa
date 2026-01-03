#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// helper function for addition with modulo
int add(int a, int b) {
    return ( (a % MOD) + (b % MOD) ) % MOD;
}

// helper function for multiplication with modulo
int mul(int a, int b) {
    return ( (long long)(a % MOD) * (b % MOD) ) % MOD;
}

int solveMem(int n, int k, vector<int>& dp)
{
    // base cases
    if(n == 1)
        return k;
    
    if(n == 2)
        return add(k, mul(k, k - 1));

    // memoization check
    if(dp[n] != -1)
        return dp[n];

    // recurrence relation
    dp[n] = add(
                mul(solveMem(n - 2, k, dp), k - 1),
                mul(solveMem(n - 1, k, dp), k - 1)
              );

    return dp[n];
}

int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solveMem(n, k, dp);
}

int main()
{
    int n, k;
    cout << "Enter number of posts (n): ";
    cin >> n;

    cout << "Enter number of colors (k): ";
    cin >> k;

    cout << "Number of ways: " << numberOfWays(n, k) << endl;

    return 0;
}
