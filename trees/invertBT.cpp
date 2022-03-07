// Given the root of a binary tree, invert the tree, and return its root.

// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

// Input: root = [2,1,3]
// Output: [2,3,1]
// Example 3:

// Input: root = []
// Output: []

// https://www.youtube.com/watch?v=OnSn2XEQ4MY&list=PLot-Xpze53ldg4pN6PfzoJY7KsKcxF1jg&index=3

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void invert(TreeNode *node)
    {
        if (!node)
            return;
        TreeNode *temp;

        invert(node->left);
        invert(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
        return;
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return NULL;
        invert(root);
        return root;
    }
};