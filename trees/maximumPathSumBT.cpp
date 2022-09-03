// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

// https://www.youtube.com/watch?v=WszrfSwMz58&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=18&t=933s

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
    int findMaxPathSum(TreeNode *node, int &maxi)
    {
        if (node == NULL)
            return 0;

        int left = max(0, findMaxPathSum(node->left, maxi));
        int right = max(0, findMaxPathSum(node->right, maxi));

        maxi = max(maxi, left + right + node->val);

        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxi = INT_MIN;
    }

    // maxSum is for storing the max path sum at every node
    //  at every node we calculate nodeSum with is the max of
    //  the currNode value plus maximum path sum in leftSubtree,
    //  the currNode value plus maximum path sum in rightSubtree,
    //  the currNode value
    //  and we compare nodeSum and maxSum
    //  if nodeSum is -ve when returning to top tree we pass 0 because
    //  instead of taking a -ve value 0 is better

    // and also at every node we are calculating the total subtree sum
    // which is sum of nodeVal, maxPath sum in leftTree,maxPath sum in rightTree
    // we are storing it in maxTreeSum

    // after the complete traversal
    // maxSum - stores the maximumPath sum of all the paths in the tree
    // maxTreeSum - stores the maximum SubTree sum of all the subtrees in the tree

    // final answer is the maximum in these two

    //     int maxSum = INT_MIN;
    //     int maxTreeSum = INT_MIN;

    //     int findSum(TreeNode *node, bool isRoot)
    //     {
    //         if (node == NULL)
    //             return 0;

    //         int leftSum = node->val + findSum(node->left, false);
    //         int rightSum = node->val + findSum(node->right, false);

    //         int nodeSum = max({leftSum, rightSum, node->val});
    //         maxSum = max(maxSum, nodeSum);
    //         maxTreeSum = max(maxTreeSum, leftSum + rightSum - node->val);

    //         if (nodeSum < 0)
    //             return 0;
    //         return nodeSum;
    //     }

    //     int maxPathSum(TreeNode *root)
    //     {
    //         if (root == NULL)
    //             return 0;
    //         bool isRoot = true;
    //         findSum(root, isRoot);

    //         return max(maxSum, maxTreeSum);
    //     }
    // };