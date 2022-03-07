// You are given two binary trees root1 and root2.

// Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

// Return the merged tree.

// Note: The merging process must start from the root nodes of both trees.

// Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
// Output: [3,4,5,5,4,null,7]
// Example 2:

// Input: root1 = [1], root2 = [1,2]
// Output: [2,2]

// https://www.youtube.com/watch?v=QHH6rIK3dDQ&list=PLot-Xpze53ldg4pN6PfzoJY7KsKcxF1jg&index=4

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

// we can also use iterative approach

// recursive
class Solution
{
public:
    TreeNode *solve(TreeNode *tree1, TreeNode *tree2)
    {
        if (!tree2)
            return tree1;

        if (!tree1)
        {
            TreeNode *newNode = new TreeNode(tree2->val);
            newNode->left = solve(NULL, tree2->left);
            newNode->right = solve(NULL, tree2->right);
            return newNode;
        }

        tree1->val += tree2->val;
        tree1->left = solve(tree1->left, tree2->left);
        tree1->right = solve(tree1->right, tree2->right);

        return tree1;
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1)
            return root2;
        if (!root2)
            return root1;
        return solve(root1, root2);
    }
};