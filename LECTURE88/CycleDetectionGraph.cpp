#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour: adj[front])
        {
            if(visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;

    for(int i = 0; i< m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans == 1)
            {
                return "Yes";
            }
        }
    }

    return "No";
}

int main() 
{
    // Test case 1: Graph with cycle
    vector<vector<int>> edges1 = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0}  // This creates a cycle
    };
    int n1 = 4, m1 = 4;
    
    string result1 = cycleDetection(edges1, n1, m1);
    cout << "Test Case 1 - Graph with cycle: " << result1 << endl;
}