#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto i : adj[front]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s) {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Test case 1
    vector<pair<int, int>> edges1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}, {1, 4}};
    int n1 = 4, m1 = 5, s1 = 1, t1 = 4;
    
    vector<int> path1 = shortestPath(edges1, n1, m1, s1, t1);
    
    cout << "Shortest path from " << s1 << " to " << t1 << ": ";
    for (int node : path1) {
        cout << node << " ";
    }
    cout << endl;

    // Test case 2
    vector<pair<int, int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {2, 5}, {5, 6}, {6, 4}};
    int n2 = 6, m2 = 6, s2 = 1, t2 = 4;
    
    vector<int> path2 = shortestPath(edges2, n2, m2, s2, t2);
    
    cout << "Shortest path from " << s2 << " to " << t2 << ": ";
    for (int node : path2) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}