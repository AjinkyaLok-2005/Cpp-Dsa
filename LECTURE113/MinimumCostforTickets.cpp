#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& days, vector<int>& cost, int index)
    {
        if(index >= n)
            return 0;

        //1 day pass
        int option1 = cost[0] + solve(n, days, cost, index+1);

        //7 day pass
        int i;

        for(i = index; i < n && days[i] < days[index] + 7; i++);

        int option2 = cost[1] + solve(n, days, cost, i); 

        //30 day pass
        for(i = index; i < n && days[i] < days[index] + 30; i++);

        int option3 = cost[2] + solve(n, days, cost, i);

        return min(option1, min(option2, option3));
    }

    int solveMem(int n, vector<int>& days, vector<int>& cost, int index, vector<int>& dp)
    {
        if(index >= n)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        //1 day pass
        int option1 = cost[0] + solveMem(n, days, cost, index+1, dp);

        //7 day pass
        int i;

        for(i = index; i < n && days[i] < days[index] + 7; i++);

        int option2 = cost[1] + solveMem(n, days, cost, i, dp); 

        //30 day pass
        for(i = index; i < n && days[i] < days[index] + 30; i++);

        int option3 = cost[2] + solveMem(n, days, cost, i, dp);

        dp[index] = min(option1, min(option2, option3));

        return dp[index];
    }

    int solveTab(int n, vector<int>& days, vector<int>& cost)
    {
        vector<int> dp(n+1, INT_MAX);

        dp[n] = 0;

        for(int k = n-1; k >= 0; k--)
        {
            //1 day pass
            int option1 = cost[0] + dp[k+1];

            //7 day pass
            int i;

            for(i = k; i < n && days[i] < days[k] + 7; i++);

            int option2 = cost[1] + dp[i]; 

            //30 day pass
            for(i = k; i < n && days[i] < days[k] + 30; i++);

            int option3 = cost[2] + dp[i];

            dp[k] = min(option1, min(option2, option3));
        }

        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // return solve(n, days, cost, 0);

        // vector<int> dp(n+1, -1);
        // return solveMem(n, days, cost, 0, dp);

        return solveTab(n, days, costs);
    }
};

int main()
{
    Solution obj;

    // Example input
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    cout << obj.mincostTickets(days, costs) << endl;

    return 0;
}
