#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            bool cycleDetected = checkCycleDFS(i, visited, dfsVisited, adj);
            if(cycleDetected)
            {
                return true;
            }
        }
        else if(dfsVisited[i])
        {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if(cycleFound)
            {
                return true;
            }
        }
    }

    return false;
}

int main() 
{
    // Test case 1: Graph with cycle
    int n1 = 4;
    vector<pair<int, int>> edges1 = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2}  // This creates a cycle: 2->3->4->2
    };
    
    cout << "Graph with cycle: ";
    if(detectCycleInDirectedGraph(n1, edges1)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle found." << endl;
    }
}