// https://leetcode.com/problems/maximum-width-of-binary-tree/
// https://www.youtube.com/watch?v=ZbybYvcVLks&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=29

// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes
// (the leftmost and rightmost non-null nodes), where the null nodes between the
// end-nodes that would be present in a complete binary tree extending down to that
// level are also counted into the length calculation.

// It is guaranteed that the answer will in the range of a 32-bit signed integer.

// Example 1:

// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
// Example 2:

// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
// Example 3:

// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2 (3,2)

#include <bits/stdc++.h>
typedef long long int llt;
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
struct util
{
    TreeNode *node;
    llt idx;

    util(TreeNode *_node, llt _idx)
    {
        node = _node;
        idx = _idx;
    }
};

class Solution
{
public:
    long widthOfBinaryTree(TreeNode *root)
    {
        deque<util> dq;
        dq.push_back(util(root, 0));

        llt ans = 1;
        llt temp = 0;
        TreeNode *node;
        llt idx;

        while (!dq.empty())
        {
            llt size = dq.size();

            llt minIdx = dq.front().idx;

            for (llt i = 0; i < size; i++)
            {
                node = dq.front().node;
                idx = dq.front().idx;
                dq.pop_front();

                if (node->left != NULL)
                    dq.push_back(util(node->left, 2 * (idx - minIdx)));
                if (node->right != NULL)
                    dq.push_back(util(node->right, 2 * (idx - minIdx) + 1));
            }
            if (!dq.empty())
                ans = max(ans, dq.back().idx - dq.front().idx + 1);
        }
        return ans;
    }
};