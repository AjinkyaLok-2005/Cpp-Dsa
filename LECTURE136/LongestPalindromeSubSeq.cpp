#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int solve(string& a, string& b, int i, int j)
    {
        //base case
        if(i == a.length())
            return 0;
        
        if(j == b.length())
            return 0;

        int ans = 0;
        if(a[i] == b[j])
        {
            ans = 1 + solve(a, b, i+1, j+1);
        }
        else
        {
            ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
        }
        return ans;
    }

    int solveMem(string& a, string& b, int i, int j, vector<vector<int>>& dp)
    {
        //base case
        if(i == a.length())
            return 0;
        
        if(j == b.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j])
        {
            ans = 1 + solveMem(a, b, i+1, j+1, dp);
        }
        else
        {
            ans = max(solveMem(a, b, i+1, j, dp), solveMem(a, b, i, j+1, dp));
        }
        return dp[i][j] = ans;
    }

    int solveTab(string& a, string& b)
    {
        //base case
        vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i = a.length()-1; i >= 0; i--)
        {
            for(int j = b.length()-1; j >= 0; j--)
            {
                int ans = 0;
                if(a[i] == b[j])
                {
                    ans = 1 + dp[i+1][j+1];
                }
                else
                {
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

     int solveTabSO(string a, string b)
    {
        // vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i = a.length()-1; i >= 0; i--)
        {
            for(int j = b.length()-1; j >= 0; j--)
            {
                int ans = 0;
                if(a[i] == b[j])
                {
                    ans = 1 + next[j+1];
                }
                else
                {
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());

        // return solve(s, s1, 0, 0);

        vector<vector<int>> dp(s.length(), vector<int>(s1.length(), -1));
        // return solveMem(s, s1, 0, 0, dp);

        // return solveTab(s, s1);

        return solveTabSO(s, s1);
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;
    cout << obj.longestPalindromeSubseq(s);

    return 0;
}
