#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int i = 0;
        int j = m-1;
        
        int mini = INT_MAX;
        
        while(j < a.size())
        {
            int diff = a[j] - a[i];
            mini = min(mini, diff);
            i++;
            j++;
        }
        return mini;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Solution obj;
    cout << obj.findMinDiff(a, m);

    return 0;
}