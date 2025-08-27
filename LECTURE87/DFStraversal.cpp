#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i: adj[node])
    {
        if(!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() 
{
    // Test Case 1: Simple connected graph
    cout << "Test Case 1: Simple connected graph" << endl;
    int V1 = 4, E1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}};
    
    vector<vector<int>> result1 = depthFirstSearch(V1, E1, edges1);
    for(int i = 0; i < result1.size(); i++) {
        cout << "Component " << i+1 << ": ";
        for(int node : result1[i]) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}