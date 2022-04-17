// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

// Example 1:
// Input: grid = [[0,1],[1,0]]
// Output: 2

// Example 2:
// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1)
            return -1;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

        while (!q.empty())
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int d = q.front().first;
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (newx >= 0 and newx < n and newy >= 0 and newy < n and grid[newx][newy] == 0)
                {

                    if (d + 1 < dist[newx][newy])
                    {
                        q.push({d + 1, {newx, newy}});
                        dist[newx][newy] = d + 1;
                    }
                }
            }
        }

        if (dist[n - 1][n - 1] == 1e9)
            return -1;
        return dist[n - 1][n - 1];
    }
};