// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]

// https://www.youtube.com/watch?v=FXWRE67PLL0&list=PLot-Xpze53ldBT_7QA8NVot219jFNr_GI&index=12

class DSU
{
private:
    vector<int> size, parent;

public:
    DSU(int n)
    {
        for (int i = 0; i < n; i++)
        {
            size.push_back(1);
            parent.push_back(i);
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionSize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        DSU dsu = DSU(1001);
        vector<int> ans;

        for (auto edge : edges)
        {
            if (dsu.findParent(edge[0]) == dsu.findParent(edge[1]))
                ans = edge;
            else
            {
                dsu.unionSize(edge[0], edge[1]);
            }
        }
        return ans;
    }
};