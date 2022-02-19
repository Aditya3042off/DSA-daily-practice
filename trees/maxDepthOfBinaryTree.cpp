// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2

// // https://www.youtube.com/watch?v=eD3tmO66aBA&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=15

#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
    int maxDepth(TreeNode *root)
    {
        queue<TreeNode *> q;

        if (root == NULL)
            return 0;
        int temp;
        int length = 1;
        q.push(root);

        while (!q.empty())
        {
            temp = q.size();

            while (temp--)
            {
                root = q.front();
                if (root->left != NULL)
                    q.push(root->left);
                if (root->right != NULL)
                    q.push(root->right);
                q.pop();
            }
            if (!q.empty())
                length++;
        }
        return length;
    }
};