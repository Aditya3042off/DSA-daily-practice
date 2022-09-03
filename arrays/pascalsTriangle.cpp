// // Given an integer numRows, return the first numRows of Pascal's triangle.

// // In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// // Example 1:

// // Input: numRows = 5
// // Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// // Example 2:

// // Input: numRows = 1
// // Output: [[1]]

// https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=12
// https://leetcode.com/problems/pascals-triangle/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        int idx;

        if (numRows == 1)
            return ans;

        for (int rowNum = 2; rowNum <= numRows; rowNum++)
        {
            vector<int> temp(rowNum, 0);
            temp[0] = temp[rowNum - 1] = 1;

            for (int col = 1; col < rowNum - 1; col++)
            {
                idx = ans.size() - 1;
                temp[col] = ans[idx][col] + ans[idx][col - 1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};