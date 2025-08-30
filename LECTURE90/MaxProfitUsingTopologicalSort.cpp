#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void topoSort(int node, unordered_map<int, bool>& visited, stack<int>& s, unordered_map<int, list<int>>& adj) {
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                topoSort(neighbour, visited, s, adj);
            }
        }

        s.push(node);
    }

    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {

        unordered_map<int, list<int>> adj;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        unordered_map<int, bool> visited;
        stack<int> s;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                topoSort(i, visited, s, adj);
            }
        }

        vector<int> sortedScores = score;
        sort(sortedScores.begin(), sortedScores.end());

        long long finalMaxP = 0;
        for (int i = 0; i < sortedScores.size(); i++) {
            finalMaxP += (long long)(i + 1) * sortedScores[i];
        }

        return finalMaxP;
    }
};

int main() {
    // Test case 1 from the original prompt
    int n1 = 2;
    vector<vector<int>> edges1 = {};
    vector<int> score1 = {40622, 61576};
    Solution sol1;
    cout << "Test Case 1:" << endl;
    cout << "Input: n = 2, edges = {}, score = {40622, 61576}" << endl;
    cout << "Max Profit: " << sol1.maxProfit(n1, edges1, score1) << endl;
    cout << "------------------------" << endl;

    // Test case 2: a simple directed graph
    int n2 = 4;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}};
    vector<int> score2 = {10, 20, 30, 40};
    Solution sol2;
    cout << "Test Case 2:" << endl;
    cout << "Input: n = 4, edges = {{0, 1}, {1, 2}, {2, 3}}, score = {10, 20, 30, 40}" << endl;
    cout << "Max Profit: " << sol2.maxProfit(n2, edges2, score2) << endl;
    cout << "------------------------" << endl;

    // Test case 3: a graph with multiple components
    int n3 = 5;
    vector<vector<int>> edges3 = {{0, 1}, {2, 3}};
    vector<int> score3 = {5, 8, 3, 10, 2};
    Solution sol3;
    cout << "Test Case 3:" << endl;
    cout << "Input: n = 5, edges = {{0, 1}, {2, 3}}, score = {5, 8, 3, 10, 2}" << endl;
    cout << "Max Profit: " << sol3.maxProfit(n3, edges3, score3) << endl;
    cout << "------------------------" << endl;

    return 0;
}