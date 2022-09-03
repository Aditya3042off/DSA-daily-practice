// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=11&t=637s

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = 1, col = 1;
        int rows = matrix.size(), cols = matrix[0].size();

        for (int i : matrix[0])
        {
            if (i == 0)
                row = 0;
        }
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col = 0;
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] != 0)
                    continue;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (row == 0)
        {
            for (int i = 0; i < cols; i++)
                matrix[0][i] = 0;
        }
        if (col == 0)
        {
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
    }
};