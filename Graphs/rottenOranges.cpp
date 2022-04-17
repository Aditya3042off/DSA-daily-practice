// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

// https://www.youtube.com/watch?v=pBU2Lh7gspQ&list=PLN4aKSfpk8TQwHTE3ZAz6felbFY2UcLYR&index=2

class Solution
{
public:
    bool isValid(int x, int y, vector<vector<int>> &grid)
    {
        return (x < grid.size() and x >= 0 and y < grid[0].size() and y >= 0);
    }

    int solve(vector<vector<int>> &grid, int x, int y)
    {
        int count = 0, time = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    count++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        pair<int, int> curr;

        while (count > 0 and !q.empty())
        {
            time++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                curr = q.front();
                cout << curr.first << "-" << curr.second << " ";
                q.pop();

                if (isValid(curr.first + 1, curr.second, grid) and grid[curr.first + 1][curr.second] == 1)
                {
                    grid[curr.first + 1][curr.second] = 2;
                    q.push({curr.first + 1, curr.second});
                    count--;
                }
                if (isValid(curr.first - 1, curr.second, grid) and grid[curr.first - 1][curr.second] == 1)
                {
                    grid[curr.first - 1][curr.second] = 2;
                    q.push({curr.first - 1, curr.second});
                    count--;
                }
                if (isValid(curr.first, curr.second + 1, grid) and grid[curr.first][curr.second + 1] == 1)
                {
                    grid[curr.first][curr.second + 1] = 2;
                    q.push({curr.first, curr.second + 1});
                    count--;
                }
                if (isValid(curr.first, curr.second - 1, grid) and grid[curr.first][curr.second - 1] == 1)
                {
                    grid[curr.first][curr.second - 1] = 2;
                    q.push({curr.first, curr.second - 1});
                    count--;
                }
            }
        }
        if (count == 0)
            return time;
        return -1;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        return solve(grid, 0, 0);
    }
};