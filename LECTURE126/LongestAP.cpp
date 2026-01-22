#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            int temp = arr[i] - difference;
            int tempAns = 0;

            //check answer exists for temp already or not
            if(dp.count(temp))
                tempAns = dp[temp];

            //current answer update
            dp[arr[i]] = 1 + tempAns;

            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int difference = -2;

    int result = obj.longestSubsequence(arr, difference);
    cout << "Longest subsequence length: " << result << endl;

    return 0;
}