#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator function for sorting edges by weight
bool cmp(vector<int> &a, vector<int> &b)
{
  return a[2] < b[2];
}

// Initialize the disjoint set
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
  for(int i = 0; i < n; i++)
  {
    parent[i] = i;
    rank[i] = 0;
  }
}

// Find the parent of a node with path compression
int findParent(vector<int> &parent, int node)
{
  if(parent[node] == node)
  {
    return node;
  }

  return parent[node] = findParent(parent, parent[node]);
}

// Union two sets using union by rank
void unionSet(int u, int v, vector<int> &parent, vector<int> & rank)
{
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u] < rank[v])
  {
    parent[u] = v;
  }
  else if(rank[v] < rank[u])
  {
    parent[v] = u;
  }
  else
  {
    parent[v] = u;
    rank[u]++;
  }
}

// Kruskal's algorithm for Minimum Spanning Tree
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);

  int minWeight = 0;

  for(int i = 0; i < edges.size(); i++)
  {
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int wt = edges[i][2];

    if(u != v)
    {
      minWeight += wt;
      unionSet(u, v, parent, rank);
    }
  }

  return minWeight;
}

int main()
{
  // Example 1: Simple graph with 4 nodes
  int n1 = 4;
  vector<vector<int>> edges1 = {
    {0, 1, 10},  // node1, node2, weight
    {0, 2, 6},
    {0, 3, 5},
    {1, 3, 15},
    {2, 3, 4}
  };
  
  int mstWeight1 = minimumSpanningTree(edges1, n1);
  cout << "Minimum Spanning Tree Weight for Graph 1: " << mstWeight1 << endl;
  
  // Example 2: Graph with 5 nodes
  int n2 = 5;
  vector<vector<int>> edges2 = {
    {0, 1, 2},
    {0, 3, 6},
    {1, 2, 3},
    {1, 3, 8},
    {1, 4, 5},
    {2, 4, 7},
    {3, 4, 9}
  };
  
  int mstWeight2 = minimumSpanningTree(edges2, n2);
  cout << "Minimum Spanning Tree Weight for Graph 2: " << mstWeight2 << endl;
  
  // Example 3: User input
  cout << "\nWould you like to enter your own graph? (y/n): ";
  char choice;
  cin >> choice;
  
  if(choice == 'y' || choice == 'Y') {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    
    vector<vector<int>> edges(e, vector<int>(3));
    cout << "Enter edges (format: node1 node2 weight):" << endl;
    for(int i = 0; i < e; i++) {
      cout << "Edge " << i+1 << ": ";
      cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    
    int mstWeight = minimumSpanningTree(edges, n);
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;
  }
  
  return 0;
}