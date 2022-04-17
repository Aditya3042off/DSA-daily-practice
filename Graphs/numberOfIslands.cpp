// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        int count = 0, x, y;
        queue<pair<int, int>> q;
        int row[4] = {0, 0, 1, -1};
        int col[4] = {1, -1, 0, 0};

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (visited[i][j] || grid[i][j] == '0')
                    continue;
                visited[i][j] = 1;
                count++;
                q.push({i, j});

                while (!q.empty())
                {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        if (x + row[k] < rows and x + row[k] >= 0 and y + col[k] < cols and y + col[k] >= 0)
                        {
                            if (!visited[x + row[k]][y + col[k]] and grid[x + row[k]][y + col[k]] == '1')
                            {
                                visited[x + row[k]][y + col[k]] = 1;
                                q.push({x + row[k], y + col[k]});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};