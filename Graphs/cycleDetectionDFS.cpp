// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
// https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=8

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(vector<int> &visited, vector<int> adj[], int k, int parent)
    {
        visited[k] = 1;

        for (auto i : adj[k])
        {
            if (visited[i] and i != parent)
                return true;
            if (visited[i])
                continue;
            if (dfs(visited, adj, i, k))
                return true;
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (visited[i])
                continue;
            if (dfs(visited, adj, i, -1))
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends