/* The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.



Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem */

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
struct DP
{
    int robbing;
    int notrobbing;
    DP(int _rob, int _notrob)
    {
        robbing = _rob;
        notrobbing = _notrob;
    }
};

class Solution
{
public:
    DP solve(TreeNode *node)
    {
        if (node == NULL)
            return DP(0, 0);

        DP left = solve(node->left);
        DP right = solve(node->right);

        return DP(
            node->val + left.notrobbing + right.notrobbing,                           // robbing current house
            max(left.robbing, left.notrobbing) + max(right.robbing, right.notrobbing) // notrobbing current house
        );
    }

    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        DP ans = solve(root);

        return max(ans.robbing, ans.notrobbing);

        //         unordered_map<TreeNode*,int> dp;

        //         return f(root,dp);
    }

    // method -1
    //     int f(TreeNode* root,unordered_map<TreeNode*,int>& dp) {
    //         if(root == NULL) return 0;
    //         if(dp[root] != 0) return dp[root];

    //         //rob
    //         int robbing = root->val;
    //         if(root->left) robbing += f(root->left->left,dp) + f(root->left->right,dp);
    //         if(root->right) robbing += f(root->right->left,dp) + f(root->right->right,dp);

    //         //notrob
    //         int notrobbing = f(root->left,dp) + f(root->right,dp);

    //         return dp[root] = max(robbing,notrobbing);
    //     }
};