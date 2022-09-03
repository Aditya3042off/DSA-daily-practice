// https://www.youtube.com/watch?v=flDtskodcKI&t=3716s
// https://www.lintcode.com/problem/434/

// Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k).
// Originally, the 2D matrix is all 0 which means there is only sea in the matrix.
// The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can
// change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the
// matrix after each operator.You need to return an array of size K.

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
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

void changeLandsNum(vector<vector<int>> &grid, int &numIslands, int x, int y, DSU &dsu)
{
    int n = grid.size();
    int m = grid[0].size();

    set<int> st;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];

        if (newx < n and newx >= 0 and newy < m and newy >= 0 and grid[newx][newy] != 0)
        {
            st.insert(dsu.findParent(newx * m + newy));
            dsu.unionSize(x * m + y, newx * m + newy);
        }
    }

    int size = st.size();

    if (size == 0)
    {
        // there are no adjacent islands. so this cell will be a new island.
        //  so islands count will increase by 1;
        numIslands++;
    }
    else if (size == 1)
    {
        // there are some lands adjacent to this new cell
        // but all those lands belong to same main island
        // so adding this new cell wont change islands count
    }
    else
    {
        // there are some adj lands to this new cell and they dont belong to new island
        // so by adding this cell all the adjacent isalnd groups will be one whole big isalnd
        // so island count decreases
        numIslands -= (size - 1);
    }

    return;
}

class Solution
{
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators)
    {
        // write your code here
        // here i am representing 2d grid as 1d array
        vector<int> ans;
        vector<vector<int>> grid(n, vector<int>(m, 0));

        int numIslands = 0;

        DSU dsu = DSU(n * m + 1);

        for (int i = 0; i < operators.size(); i++)
        {
            int x = operators[i].x;
            int y = operators[i].y;
            // sometimes there are giving same x,y values more than once. no need to calculate for those
            if (grid[x][y] != 1)
            {
                grid[x][y] = 1;
                changeLandsNum(grid, numIslands, x, y, dsu);
            }

            ans.push_back(numIslands);
        }
        return ans;
    }
};