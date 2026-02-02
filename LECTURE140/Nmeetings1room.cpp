#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int, int> a, pair<int, int>b)
    {
        return a.second < b.second;
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int, int>> v;
        
        for(int i = 0; i <n; i++)
        {
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int count = 1;
        int ansEnd = v[0].second;
        
        for(int i = 1; i < n; i++)
        {
            if(v[i].first > ansEnd)
            {
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> start(n), end(n);

    for(int i = 0; i < n; i++) {
        cin >> start[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> end[i];
    }

    Solution obj;
    cout << obj.maxMeetings(start, end);

    return 0;
}