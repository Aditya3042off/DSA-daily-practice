// You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
// connected 4-directionally (horizontal or vertical.) You may assume all four edges of the
// grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0

class Solution
{
public:
    void solve(vector<vector<int>> &visited, vector<vector<int>> &grid, int x, int y, int &ans, int &curr)
    {
        if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0)
        {
            return;
        }
        if (visited[x][y] || !grid[x][y])
            return;

        visited[x][y] = 1;
        curr++;
        ans = max(ans, curr);

        solve(visited, grid, x + 1, y, ans, curr);
        solve(visited, grid, x - 1, y, ans, curr);
        solve(visited, grid, x, y + 1, ans, curr);
        solve(visited, grid, x, y - 1, ans, curr);

        return;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (visited[i][j])
                    continue;
                curr = 0;
                solve(visited, grid, i, j, ans, curr);
            }
        }
        return ans;
    }
};
