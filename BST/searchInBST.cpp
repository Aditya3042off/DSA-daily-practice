// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]

// Input: root = [4,2,7,1,3], val = 5
// Output: []

// https://www.youtube.com/watch?v=KcNt6v_56cc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=41

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
    // recursive
    //     TreeNode* searchBST(TreeNode* root, int val) {
    //         if(root == NULL) return NULL;
    //         if(val == root->val) return root;

    //         if(val < root->val) return searchBST(root->left,val);
    //         else return searchBST(root->right,val);
    //     }

    // iterative
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != NULL)
        {
            if (root->val == val)
                break;

            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};