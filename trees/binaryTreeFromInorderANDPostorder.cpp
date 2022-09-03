// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// https://www.youtube.com/watch?v=LgLRTaEMRVc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=36

// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Example 1:

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
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
    TreeNode *solve(vector<int> &postorder, vector<int> &inorder, unordered_map<int, int> &indexes, int left, int right)
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

        for (int i = postorder.size() - 1; i >= 0; i--)
        {
            if (indexes[postorder[i]] < left or indexes[postorder[i]] > right)
                continue;

            node->val = postorder[i];
            inorderIndex = indexes[postorder[i]];
            break;
        }

        node->left = solve(postorder, inorder, indexes, left, inorderIndex - 1);
        node->right = solve(postorder, inorder, indexes, inorderIndex + 1, right);

        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> indexes;

        for (int i = 0; i < inorder.size(); i++)
            indexes[inorder[i]] = i;

        return solve(postorder, inorder, indexes, 0, inorder.size() - 1);
    }
};