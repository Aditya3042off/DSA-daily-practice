// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1},
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at
// (3, 3) from (0, 0) by two paths - DRDDRR
// and DDRDRR, when printed in sorted order
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is
// blocked.

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void solve(vector<vector<int>> &m, vector<string> &ans, string path, int x, int y)
    {
        int n = m.size();
        if (x < 0 or x >= n or y < 0 or y >= n)
            return;
        if (x == n - 1 and y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // m[x][y] = -1 means that cell is already visited;
        if (m[x][y] == 0 or m[x][y] == -1)
            return;

        m[x][y] = -1;

        solve(m, ans, path + 'D', x + 1, y);
        solve(m, ans, path + 'L', x, y - 1);
        solve(m, ans, path + 'R', x, y + 1);
        solve(m, ans, path + 'U', x - 1, y);

        m[x][y] = 1;
        return;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        if (m[0][0] == 0 or m[n - 1][n - 1] == 0)
            return {"-1"};
        vector<string> ans;
        solve(m, ans, "", 0, 0);
        if (!ans.size())
            return {"-1"};
        return ans;
    }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends