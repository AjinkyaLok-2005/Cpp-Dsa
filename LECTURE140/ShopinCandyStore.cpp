#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        
        sort(prices.begin(), prices.end());
        
        int mini = 0;
        int buy = 0;
        int Free = n-1;
        
        while(buy <= Free)
        {
            mini = mini + prices[buy];
            buy++;
            Free = Free - k;
        }
        
        int maxi = 0;
        buy = n-1;
        Free = 0;
        
        while(Free <= buy)
        {
            maxi = maxi + prices[buy];
            buy--;
            Free = Free + k;
        }
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution obj;
    vector<int> result = obj.minMaxCandy(prices, k);

    cout << result[0] << " " << result[1];

    return 0;
}