// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Input: root = [2,1,3]
// Output: true

// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

// https://www.youtube.com/watch?v=f-sj7I5oXEI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=47&t=122s

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
    //     bool solve(TreeNode* root,multiset<int>& less,multiset<int>& greater) {
    //         if(root == NULL) return true;

    //         if( less.begin() != less.end() and root->val >= *(less.begin())) return false;
    //         if( greater.rbegin() != greater.rend() and root->val <= *(greater.rbegin())) return false;

    //         less.insert(root->val);
    //         bool isLeftValid = solve(root->left,less,greater);
    //         less.erase(root->val);

    //         if(!isLeftValid) return false;

    //         greater.insert(root->val);
    //         bool isRightValid = solve(root->right,less,greater);
    //         greater.erase(root->val);

    //         return isLeftValid and isRightValid;
    //     }

    //     bool isValidBST(TreeNode* root) {
    //         multiset<int> less,greater;
    //         return solve(root,less,greater);

    //     }

    bool solve(TreeNode *node, long long int less, long long int greater)
    {
        if (node == NULL)
            return true;

        if (node->val >= less || node->val <= greater)
            return false;

        if (!solve(node->left, node->val, greater))
            return false;
        return solve(node->right, less, node->val);
    }

    bool isValidBST(TreeNode *root)
    {
        // if(!root->left and !root->right) return true;
        long long int less = LLONG_MAX;
        long long int greater = LLONG_MIN;
        return solve(root, less, greater);
    }
};