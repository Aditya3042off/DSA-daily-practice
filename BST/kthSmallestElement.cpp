// Given the root of a binary search tree, and an integer k,
// return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Input: root = [3,1,4,null,2], k = 1
// Output: 1

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

// https://www.youtube.com/watch?v=9TJYWh0adfk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=46

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
    TreeNode *ans = NULL;
    void solve(TreeNode *root, int k, int &count)
    {
        if (root == NULL || ans)
            return;

        solve(root->left, k, count);
        count++;
        if (k == count)
            ans = root;
        else
            solve(root->right, k, count);
        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        solve(root, k, count);
        return ans->val;
    }
};