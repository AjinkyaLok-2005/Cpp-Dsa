#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int solve(int n, vector<int>& a, int curr, int prev)
    {
        //base case
        if(curr == n)
            return 0;
            
        //include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev])
            take = 1 + solve(n, a, curr + 1, curr);
            
        //exclude
        int notTake = 0 + solve(n, a, curr + 1, prev);
        
        return max(take, notTake);
    }
    
    int solveMem(int n, vector<int>& a, int curr, int prev, vector<vector<int>>& dp)
    {
        //base case
        if(curr == n)
            return 0;
            
        if(dp[curr][prev] != -1)
            return dp[curr][prev];
            
        //include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev])
            take = 1 + solveMem(n, a, curr + 1, curr, dp);
            
        //exclude
        int notTake = 0 + solveMem(n, a, curr + 1, prev, dp);
        
        return dp[curr][prev+1] = max(take, notTake);
    }
    
    int solveTab(int n, vector<int>& a)
    {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int curr = n-1; curr >= 0; curr--)
        {
            for(int prev = curr-1; prev >= -1; prev--)
            {
                //include
                int take = 0;
                if(prev == -1 || a[curr] > a[prev])
                    take = 1 + dp[curr + 1][curr+1];
                    
                //exclude
                int notTake = 0 + dp[curr + 1][prev+1];
                
                dp[curr][prev+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
    
    int solveTabSO(int n, vector<int>& a)
    {
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--)
        {
            for(int prev = curr-1; prev >= -1; prev--)
            {
                //include
                int take = 0;
                if(prev == -1 || a[curr] > a[prev])
                    take = 1 + nextRow[curr+1];
                    
                //exclude
                int notTake = 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(take, notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    
    int solveOptimal(int n, vector<int> & a)
    {
        if(n == 0)
            return 0;
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i = 1; i < n; i++)
        {
            if(a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                //find the index of the just bigger element in ans
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                if (index == ans.size())
                {
                    ans.push_back(a[i]);
                }
                else
                {
                    ans[index] = a[i];
                }
            }
        }
        
        return ans.size();
    }
  
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        // return solve(n, arr, 0, -1);
        
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solveMem(n, arr, 0, -1, dp);
        
        // return solveTabSO(n, arr);
        
        return solveOptimal(n, arr);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.lis(arr) << endl;

    return 0;
}
