// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.
// Example 2:

// Input: grid = [[1]]
// Output: 4
// Example 3:

// Input: grid = [[1,0]]
// Output: 4

// https://www.youtube.com/watch?v=fISIuAFRM2s&list=PLot-Xpze53ldBT_7QA8NVot219jFNr_GI&index=10

struct node
{
    int x;
    int y;
    node(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

class Solution
{
public:
    int findPer(vector<vector<int>> &grid, int rows, int cols, queue<node> &q)
    {
        int p = 0; // stores the perimeter of the island
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            cout << x << " " << y << " " << p << endl;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (newx < 0 || newy < 0 || newx >= rows || newy >= cols || grid[newx][newy] == 0)
                    p++;
                else if (grid[newx][newy] == 1)
                {
                    grid[newx][newy] = -1;
                    q.push(node(newx, newy));
                }
            }
        }
        return p;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<node> q;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push(node(i, j));
                    grid[i][j] = -1; // represents that land is visited
                    break;
                }
            }
            if (!q.empty())
                break;
        }
        return findPer(grid, rows, cols, q);
    }
};