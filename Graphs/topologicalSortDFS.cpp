// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

// https://www.youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13
// https://practice.geeksforgeeks.org/problems/topological-sort/1#
// https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/tutorial/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // using DFS
    // stack holds the topological sort of the given DAG
    void findSort(vector<int> adj[], vector<int> &visited, stack<int> &st, int k)
    {
        visited[k] = 1;

        for (int i : adj[k])
        {
            if (visited[i])
                continue;

            findSort(adj, visited, st, i);
        }
        st.push(k);
        return;
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int v, vector<int> adj[])
    {
        // code here
        vector<int> visited(v, 0);
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < v; i++)
        {
            if (visited[i])
                continue;
            findSort(adj, visited, st, i);
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
} // } Driver Code Ends