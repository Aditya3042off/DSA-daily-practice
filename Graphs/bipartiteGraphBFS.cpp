// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

// Return true if and only if it is bipartite.

// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Output: false
// Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

// Input: graph = [[1,3],[0,2],[1,3],[0,2]]
// Output: true
// Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

// https://www.youtube.com/watch?v=nbgaEu-pvkU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=10

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // using BFS
    bool checkBipartite(vector<vector<int>> &graph, vector<int> &visited, int k)
    {
        queue<int> q;
        visited[k] = 0;
        q.push(k);

        while (!q.empty())
        {
            k = q.front();
            q.pop();

            for (int i : graph[k])
            {
                if (visited[k] == visited[i])
                    return false;
                if (visited[i] != -1)
                    continue;

                visited[i] = visited[k] ^ 1;
                q.push(i);
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<int> visited(v, -1);

        for (int i = 0; i < v; i++)
        {
            if (visited[i] != -1)
                continue;

            if (!checkBipartite(graph, visited, i))
                return false;
        }
        return true;
    }
};