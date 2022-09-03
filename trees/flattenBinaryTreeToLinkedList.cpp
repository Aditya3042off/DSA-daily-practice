// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// https://www.youtube.com/watch?v=sWf7k1x9XR4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=39
// https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list/
// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class
// where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// Example 1:

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [0]
// Output: [0]

// Another three approaches available in top mentioned youtube vide

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
    TreeNode *solve(TreeNode *node)
    {
        if (!node)
            return NULL;
        if (!node->left and !node->right)
            return node;

        TreeNode *left = solve(node->left);
        TreeNode *right = solve(node->right);
        TreeNode *temp;

        if (left != NULL)
        {
            temp = node->right;
            node->right = node->left;
            node->left = NULL;

            if (right != NULL)
            {
                left->right = temp;
                return right;
            }
            return left;
        }
        return right;
    }

    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        solve(root);
    }
};