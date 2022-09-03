// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// https://www.youtube.com/watch?v=aZNaLrVebKQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=35

// Given two integer arrays preorder and inorder where preorder is the
// preorder traversal of a binary tree and inorder is the inorder traversal of the same tree,
// construct and return the binary tree.

// Example 1:

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

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
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &indexes, int left, int right)
    {
        TreeNode *node = new TreeNode;
        node->left = NULL;
        node->right = NULL;

        if (left > right)
            return NULL;

        if (left == right)
        {
            node->val = inorder[left];
            return node;
        }

        int inorderIndex;

        for (int i = 0; i < preorder.size(); i++)
        {
            if (indexes[preorder[i]] < left or indexes[preorder[i]] > right)
                continue;

            node->val = preorder[i];
            inorderIndex = indexes[preorder[i]];
            break;
        }

        node->left = solve(preorder, inorder, indexes, left, inorderIndex - 1);
        node->right = solve(preorder, inorder, indexes, inorderIndex + 1, right);

        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> indexes;

        for (int i = 0; i < inorder.size(); i++)
            indexes[inorder[i]] = i;

        return solve(preorder, inorder, indexes, 0, inorder.size() - 1);
    }
};