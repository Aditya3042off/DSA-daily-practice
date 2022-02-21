// Given the root of a binary tree,
// return the zigzag level order traversal of its nodes' values.
// (i.e., from left to right, then right to left for the next level and alternate between).

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

// https://www.youtube.com/watch?v=3OXWEdlIGl4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=20

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        vector<int> temp;
        int count = 0;

        // count-> even  left to right
        // count-> odd right to left

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                root = q.front();
                temp.push_back(root->val);
                if (root->left != NULL)
                    q.push(root->left);
                if (root->right != NULL)
                    q.push(root->right);
                q.pop();
            }
            if (count & 1)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            temp.clear();
            count++;
        }
        return ans;
    }
};