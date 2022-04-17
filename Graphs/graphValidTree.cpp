// Description
// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// Example
// Example 1:

// Input: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
// Output: true.
// Example 2:

// Input: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
// Output: false.

// https://www.lintcode.com/problem/178/
// https://www.youtube.com/watch?v=bXsUuownnoQ

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

        if (size[pv] > size[pu])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution
{
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges)
    {
        // write your code here
        DSU dsu = DSU(n);
        unordered_set<int> st;
        for (auto edge : edges)
        {
            st.insert(edge[0]);
            st.insert(edge[1]);
            if (dsu.findParent(edge[0]) == dsu.findParent(edge[1]))
                return false;
            dsu.unionSize(edge[0], edge[1]);
        }
        // this set is track how many nodes have atleast 1 edge to/from them
        // if atleast one node doesn't have an edge to/from it then given graph cannot be tree
        if (st.size() != n and n != 1)
            return false;
        return true;
    }
};