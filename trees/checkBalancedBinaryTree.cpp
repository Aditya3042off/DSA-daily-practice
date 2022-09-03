// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// Input: root = []
// Output: true

// https://www.youtube.com/watch?v=Yt50Jfbd8Po&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=16

#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
    //     bool flag = true;

    //     void checkBalanced(TreeNode* node,int& height) {
    //         if(node == NULL) return;

    //         height++;
    //         int temp = height;

    //         // finding left height
    //         checkBalanced(node->left,height);
    //         int leftHeight = height;
    //         if(!flag) return;
    //         height = temp;

    //         // finding right height
    //         checkBalanced(node->right,height);
    //         int rightHeight = height;
    //         if(!flag) return;

    //         if(abs(leftHeight-rightHeight) > 1) flag = false;

    //         height = max(leftHeight,rightHeight);
    //         return;
    //     }

    int checkBalanced(TreeNode *node, bool &flag)
    {
        if (node == NULL)
            return 0;

        int leftHeight = checkBalanced(node->left, flag);
        if (!flag)
            return -1;

        int rightHeight = checkBalanced(node->right, flag);
        if (!flag)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            flag = false;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode *root)
    {
        // if(root == NULL) return flag;
        // int height = 0;
        // checkBalanced(root,height);
        if (root == NULL)
            return true;
        bool flag = true;
        checkBalanced(root, flag);
        return flag;
    }
};