// https://www.lintcode.com/problem/787/
// https://www.youtube.com/watch?v=pBU2Lh7gspQ&list=PLN4aKSfpk8TQwHTE3ZAz6felbFY2UcLYR&index=2&t=2133s

// Description
// There is a ball in a maze with empty spaces and walls.
// The ball can go through empty spaces by rolling up, down, left or right,
// but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

// Given the ball's start position, the destination and the maze,
// determine whether the ball could stop at the destination.

// The maze is represented by a binary 2D array.
// 1 means the wall and 0 means the empty space. Y
// ou may assume that the borders of the maze are all walls.
// The start and destination coordinates are represented by row and column indexes.

// Example
// Example 1:

// Input:
// map =
// [
//  [0,0,1,0,0],
//  [0,0,0,0,0],
//  [0,0,0,1,0],
//  [1,1,0,1,1],
//  [0,0,0,0,0]
// ]
// start = [0,4]
// end = [3,2]
// Output:
// false
// Example 2:

// Input:
// map =
// [[0,0,1,0,0],
//  [0,0,0,0,0],
//  [0,0,0,1,0],
//  [1,1,0,1,1],
//  [0,0,0,0,0]
// ]
// start = [0,4]
// end = [4,4]
// Output:
// true

#include <bits/stdc++.h>
using namespace std;

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
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */

    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &end)
    {
        // write your code here
        int rows = maze.size();
        int cols = maze[0].size();

        int startx = start[0], starty = start[1];
        int endx = end[0], endy = end[1];

        if (maze[endx][endy] == 1)
            return false;

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        queue<node> q;
        q.push(node(startx, starty));
        visited[startx][starty] == 1;

        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            for (int idx = 0; idx < 4; idx++)
            {
                int newx = x;
                int newy = y;
                while (newx + dx[idx] >= 0 and newx + dx[idx] < rows and newy + dy[idx] >= 0 and newy + dy[idx] < cols and maze[newx + dx[idx]][newy + dy[idx]] == 0)
                {
                    newx += dx[idx];
                    newy += dy[idx];
                }
                if (newx == endx and newy == endy)
                    return true;
                if (visited[newx][newy] == 0)
                {
                    q.push(node(newx, newy));
                    visited[newx][newy] = 1;
                }
            }
        }
        return false;
    }
};

int main()
{
}