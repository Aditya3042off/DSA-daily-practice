// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Input: root = [1,2,2,3,4,4,3]
// Output: true

// Input: root = [1,2,2,null,3,null,3]
// Output: false

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
    bool solve(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == NULL and node2 == NULL)
            return true;
        if (node1 == NULL || node2 == NULL)
            return false;

        return (node1->val == node2->val) and solve(node1->left, node2->right) and solve(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return solve(root->left, root->right);
    }
};