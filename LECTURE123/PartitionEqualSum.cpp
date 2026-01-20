#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool solve(int index, vector<int>& arr, int target)
    {
        if(index >= arr.size())
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
            
        bool incl = solve(index+1, arr, target - arr[index]);
        bool excl = solve(index+1, arr, target - 0);
        
        return incl or excl;
    }
    
    bool solveMem(int index, vector<int>& arr, int target, vector<vector<int>>& dp)
    {
        if(index >= arr.size())
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
            
        if(dp[index][target] != -1)
                return dp[index][target];
            
        bool incl = solveMem(index+1, arr, target - arr[index], dp);
        bool excl = solveMem(index+1, arr, target - 0, dp);
        
        return dp[index][target] = incl or excl;
    }
    
    bool solveTab(int N, vector<int>& arr, int total)
    {
        vector<vector<int>> dp(N+1, vector<int>(total+1, 0));
        
        for(int i = 0; i <= N; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int index = N-1; index >= 0; index--)
        {
            for(int target = 0; target <= total/2; target++)
            {
                bool incl = 0;
                if(target - arr[index] >= 0)
                    incl = dp[index+1][target - arr[index]];
                bool excl = dp[index+1][target - 0];
                
                dp[index][target] = incl or excl;
            }
        }
        
        return dp[0][total/2];
    }
    
    bool solveTabSO(int N, vector<int>& arr, int total)
    {
        vector<vector<int>> dp(N+1, vector<int>(total+1, 0));
        
        vector<int> curr(total+1, 0);
        vector<int> next(total+1, 0);
        
        curr[0] = 1;
        next[0] =1;
        
        for(int index = N-1; index >= 0; index--)
        {
            for(int target = 0; target <= total/2; target++)
            {
                bool incl = 0;
                if(target - arr[index] >= 0)
                    incl = next[target - arr[index]];
                    
                bool excl = next[target - 0];
                
                curr[target] = incl or excl;
            }
            next = curr;
        }
        
        return next[total/2];
    }
    
    bool equalPartition(vector<int>& arr) {
        int total = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            total += arr[i];    
        }
        
        if(total & 1)
            return 0;
            
        int target = total/2;
        
        int N = arr.size();
        
        // return solve(0, arr, target);
        
        // vector<vector<int>> dp(N, vector<int>(target+1, -1));
        // return solveMem(0, arr, target, dp);
        
        return solveTabSO(N, arr, total);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    bool ans = obj.equalPartition(arr);

    if(ans)
        cout << "True";
    else
        cout << "False";

    return 0;
}
