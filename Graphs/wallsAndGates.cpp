// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF

// Example
// Example1

// Input:
// [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
// Output:
// [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

// Explanation:
// the 2D grid is:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// the answer is:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4
// Example2

// Input:
// [[0,-1],[2147483647,2147483647]]
// Output:
// [[0,-1],[1,2]]

// https://www.youtube.com/watch?v=e69C6xhiSQE
// https://www.lintcode.com/problem/663/

struct node
{
    int x, y, dist;
    node(int _x, int _y, int _d)
    {
        x = _x;
        y = _y;
        dist = _d;
    }
};

class Solution
{
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        // write your code here
        int rows = rooms.size(), cols = rooms[0].size();
        queue<node> q;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (rooms[i][j] != 0)
                    continue;

                q.push(node(i, j, 0));

                while (!q.empty())
                {
                    int x = q.front().x, y = q.front().y, d = q.front().dist;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int newx = x + dx[k];
                        int newy = y + dy[k];

                        if (newx >= 0 and newy >= 0 and newx < rows and newy < cols and rooms[newx][newy] != 0 and rooms[newx][newy] != -1)
                        {
                            if (rooms[newx][newy] > d + 1)
                            {
                                rooms[newx][newy] = d + 1;
                                q.push(node(newx, newy, d + 1));
                            }
                        }
                    }
                }
            }
        }
        return;
    }
};