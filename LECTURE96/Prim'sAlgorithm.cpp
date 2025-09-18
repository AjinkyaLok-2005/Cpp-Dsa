#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Step 1: Build adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto &edge : g)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Step 2: Find min and max node (to handle any indexing)
    int start = INT_MAX, endNode = INT_MIN;
    for (auto &edge : g)
    {
        start = min(start, min(edge.first.first, edge.first.second));
        endNode = max(endNode, max(edge.first.first, edge.first.second));
    }

    // Step 3: Create helper arrays sized by endNode+1
    vector<int> key(endNode + 1, INT_MAX);
    vector<int> parent(endNode + 1, -1);
    vector<bool> mst(endNode + 1, false);

    // Step 4: Start Prim’s from `start` node
    key[start] = 0;

    // Step 5: Repeat (n-1) times
    for (int count = 0; count < (endNode - start + 1); count++)
    {
        // Pick min key node not yet in MST
        int mini = INT_MAX, u = -1;
        for (int v = start; v <= endNode; v++)
        {
            if (!mst[v] && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        if (u == -1) break; // no valid node left

        // Mark selected node as part of MST
        mst[u] = true;

        // Update adjacent vertices
        for (auto [v, w] : adj[u])
        {
            if (!mst[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    // Step 6: Build MST result
    vector<pair<pair<int, int>, int>> result;
    for (int v = start; v <= endNode; v++)
    {
        if (parent[v] != -1)
        {
            result.push_back({{parent[v], v}, key[v]});
        }
    }

    return result;
}

int main()
{
    // Example input: 4 nodes, 5 edges
    vector<pair<pair<int, int>, int>> g = {
        {{1, 0}, 5},
        {{0, 2}, 8},
        {{1, 2}, 10},
        {{1, 3}, 15},
        {{2, 3}, 20}};

    int n = 4; // number of vertices
    int m = g.size(); // number of edges

    auto mst = calculatePrimsMST(n, m, g);

    cout << "Edges in MST:\n";
    for (auto &edge : mst)
    {
        cout << edge.first.first << " - " << edge.first.second << "  weight: " << edge.second << "\n";
    }

    return 0;
}
