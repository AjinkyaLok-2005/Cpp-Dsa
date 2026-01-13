#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& v, int i, int j)
    {
        //base case
        if(i+1 == j)
            return 0;

        int ans = INT_MAX;

        for(int k = i+1; k <= j; k++)
        {
            ans = min(ans, v[i]*v[j]*v[k] + solve(v, i, k) + solve(v, k, j));
        }
        return ans;
    }

    int solveMem(vector<int>& v, int i, int j, vector<vector<int>>& dp)
    {
        //base case
        if(i+1 == j)
            return 0;

        int ans = INT_MAX;

        if(dp[i][j] != -1)
            return dp[i][j];
 
        for(int k = i+1; k < j; k++)
        {
            ans = min(ans, v[i]*v[j]*v[k] + solveMem(v, i, k, dp) + solveMem(v, k, j, dp));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(vector<int> & v)
    {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i+2; j < n; j++)
            {
                int ans = INT_MAX;
                for(int k = i+1; k < j; k++)
                {
                    ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }

    int minScoreTriangulation(vector<int>& values) {
    
        // int n = values.size();

        // return solve(values, 0, n-1);


        // int n = values.size();
        // vector<vector<int> > dp(n, vector<int>(n, -1));
        // return solveMem(v, 0, n-1, dp);


        return solveTab(values);
    }
};

int main() {
    vector<int> values = {1, 3, 1, 4, 1, 5};

    Solution obj;
    int result = obj.minScoreTriangulation(values);

    cout << "Minimum Score Triangulation: " << result << endl;

    return 0;
}
