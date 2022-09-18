// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

// Example 1:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22
// Example 2:

// Input: root = [1,2,3], targetSum = 5
// Output: []
// Example 3:

// Input: root = [1,2], targetSum = 0
// Output: []

// https://www.youtube.com/watch?v=QG0hE0R_ng4&list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner&index=4&t=1333s

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
    void f(TreeNode *node, long long sum, long long &ans, unordered_map<long long, int> &prefix, int target)
    {
        if (node == NULL)
            return;

        long long currsum = sum + node->val;
        if (currsum == target)
            ans++;

        ans += prefix[currsum - target];

        prefix[currsum]++;

        f(node->left, currsum, ans, prefix, target);
        f(node->right, currsum, ans, prefix, target);

        prefix[currsum]--;
        return;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        long long ans = 0;
        unordered_map<long long, int> prefix;

        f(root, 0, ans, prefix, targetSum);

        return ans;
    }
};