// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example 1:
// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
// Example 2:

// Input: board = [["X"]]
// Output: [["X"]]

// https://www.youtube.com/watch?v=9z2BunfoZ5Y&t=183s

class Solution
{
public:
    void dfs(vector<vector<char>> &board, int x, int y)
    {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return;
        if (board[x][y] == 'X' || board[x][y] == 'T')
            return;
        board[x][y] = 'T';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O')
                dfs(board, 0, i);
            if (board[n - 1][i] == 'O')
                dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};