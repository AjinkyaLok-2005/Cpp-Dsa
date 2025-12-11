#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int>& num, int x)
{
    if (x == 0) return 0;
    if (x < 0) return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveRec(num, x - num[i]);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    return mini;
}

int solveMem(vector<int>& num, int x, vector<int>& dp)
{
    if (x == 0) return 0;
    if (x < 0) return INT_MAX;

    if (dp[x] != -1) return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveMem(num, x - num[i], dp);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }

    return dp[x] = mini;
}

int solveTab(vector<int>& num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    return dp[x] == INT_MAX ? -1 : dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    return solveTab(num, x);  // Using the bottom-up DP
}

int main()
{
    int N, X;
    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> num(N);
    cout << "Enter the elements:\n";
    for (int i = 0; i < N; i++)
        cin >> num[i];

    cout << "Enter target sum X: ";
    cin >> X;

    int result = minimumElements(num, X);

    if (result == -1)
        cout << "It is not possible to reach the target sum.\n";
    else
        cout << "Minimum elements required: " << result << "\n";

    return 0;
}
