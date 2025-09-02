#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> & edges)
{
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++)
    {
        for(auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int cnt = 0;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        cnt++;
        for(auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    if(cnt == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    cout << "=== Directed Graph Cycle Detection ===\n" << endl;

    // Test Case 1: No cycle (DAG)
    cout << "Test Case 1: No cycle (0->1->2)" << endl;
    int n1 = 3;
    vector<pair<int, int>> edges1 = {{1, 2}, {2, 3}}; // 0->1, 1->2
    bool result1 = detectCycleInDirectedGraph(n1, edges1);
    cout << "Cycle detected: " << (result1 ? "Yes" : "No") << endl;
    cout << "Expected: No" << endl << endl;

    // Test Case 2: Contains cycle
    cout << "Test Case 2: Contains cycle (0->1->2->0)" << endl;
    int n2 = 3;
    vector<pair<int, int>> edges2 = {{1, 2}, {2, 3}, {3, 1}}; // 0->1, 1->2, 2->0
    bool result2 = detectCycleInDirectedGraph(n2, edges2);
    cout << "Cycle detected: " << (result2 ? "Yes" : "No") << endl;
    cout << "Expected: Yes" << endl << endl;

    return 0;
}