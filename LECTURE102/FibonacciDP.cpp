#include <iostream>
#include <vector>
using namespace std;

// Recursive function with memoization
int fib(int n, vector<int> &dp)
{
    // Base case
    if (n <= 1)
        return n;

    // If already computed, return stored value
    if (dp[n] != -1)
        return dp[n];

    // Recursive relation
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the position (n) to find the Fibonacci number: ";
    cin >> n;

    // Create a DP array initialized with -1
    vector<int> dp(n + 1, -1);

    // Compute Fibonacci number
    int result = fib(n, dp);

    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    // Example: show full series up to n
    cout << "Fibonacci series up to " << n << " terms: ";
    for (int i = 0; i <= n; i++)
        cout << fib(i, dp) << " ";
    cout << endl;

    return 0;
}
