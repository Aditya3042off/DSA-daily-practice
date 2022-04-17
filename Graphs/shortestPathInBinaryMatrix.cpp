// You have been given a binary matrix of size 'N' * 'M' where each element is either 0 or 1. You are also given a source and a destination cell, both of them lie within the matrix.
// Your task is to find the length of the shortest path from the source cell to the destination cell only consisting of 1s. If there is no path from source to destination cell, return -1.
// Note:
// 1. Coordinates of the cells are given in 0-based indexing.
// 2. You can move in 4 directions (Up, Down, Left, Right) from a cell.
// 3. The length of the path is the number of 1s lying in the path.
// 4. The source cell is always filled with 1.
// For Example -
// 1 0 1
// 1 1 1
// 1 1 1
// For the given binary matrix and source cell(0,0) and destination cell(0,2). Few valid paths consisting of only 1s are

// X 0 X     X 0 X
// X X X     X 1 X
// 1 1 1     X X X
// The length of the shortest path is 5.
// Input Format:
// The first line of input contains two integers 'N' and 'M' separated by a single space representing the number of rows and columns in the binary matrix respectively.

// The next 'N' lines of the input contain 'M' single space-separated integers each representing the 'i'-th row of the Binary Matrix.

// The next line of input contains two single space-separated integers 'SOURCEX' and 'SOURCEY' representing the coordinates of the source cell.

// The next line of input contains two single space-separated integers 'DESTX' and 'DESTY' representing the coordinates of the destination cell.
// Constraints :
// 1 <= N <= 500
// 1 <= M <= 500
// MAT[i] = {0, 1}

// 0 <= SOURCEX <= N - 1
// 0 <= SOURCEY <= M - 1
// 0 <= DESTX <= N - 1
// 0 <= DESTY <= M - 1
// MAT[SOURCEX][SOURCEY] = 1

// Time Limit: 1 sec
// Output Format :
// For each test case, print a single line that contains a single integer i.e. length of the shortest path from the source cell to the destination cell.
// Note:
// You do not need to print anything; it has already been taken care of. Just implement the given function.
// Sample Input 1:
// 3 3
// 0 1 0
// 0 0 1
// 1 1 1
// 2 0
// 1 2
// Sample Output 1:
// 4
// Explanation Of Sample Input 1:
// The shortest path is composed of the cells (2,0) -> (2,1) -> (2,2) -> (1,2). Length of this path is 4.
// Sample Input 2:
// 4 4
// 1 0 1 0
// 0 1 0 1
// 1 0 1 0
// 0 0 1 0
// 0 0
// 3 2
// Sample Output 2:
// -1

// https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118511/offering/1381547?leftPanelTab=0

#include <bits/stdc++.h>
int findShortestPath(vector<vector<bool>> &mat,
                     int sourceX, int sourceY,
                     int destX, int destY,
                     int n, int m)
{
    // Write your code here.
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[sourceX][sourceY] = 1;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({1, {sourceX, sourceY}});

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int d = pq.top().first;
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx >= 0 and newx < n and newy >= 0 and newy < m and mat[newx][newy] == 1)
            {
                if (d + 1 < dist[newx][newy])
                {
                    pq.push({d + 1, {newx, newy}});
                    dist[newx][newy] = d + 1;
                }
            }
        }
    }
    if (dist[destX][destY] == 1e9)
        return -1;
    return dist[destX][destY];
}