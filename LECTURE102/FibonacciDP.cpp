#include <iostream>
#include <vector>
using namespace std;

// Recursive function with memoization
// int fib(int n, vector<int> &dp)
// {
//     // Base case
//     if (n <= 1)
//         return n;

//     // If already computed, return stored value
//     if (dp[n] != -1)
//         return dp[n];

//     // Recursive relation
//     dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
//     return dp[n];
// }

// int main()
// {
//     int n;
//     cout << "Enter the position (n) to find the Fibonacci number: ";
//     cin >> n;

//     // Create a DP array initialized with -1
//     vector<int> dp(n + 1, -1);

//     // Compute Fibonacci number
//     int result = fib(n, dp);

//     cout << "The " << n << "th Fibonacci number is: " << result << endl;

//     // Example: show full series up to n
//     cout << "Fibonacci series up to " << n << " terms: ";
//     for (int i = 0; i <= n; i++)
//         cout << fib(i, dp) << " ";
//     cout << endl;

//     return 0;
// }


//TABULAR METHOD

int main()
// {   
//     int n;
//     cin >> n;

//     //step1 
//     vector<int> dp(n+1);

//     //step2
//     dp[1] = 1;
//     dp[0] = 0;

//     //step3
//     for(int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     cout << dp[n] << endl;

//     return 0;
// }


//SPACE OPTIMISATION

int main()
{
    int n;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;

    if(n == 0)
    {
        return prev2;
    }

    for(int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        //shift logic
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;

    return 0;
}