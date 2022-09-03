// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia:
// “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as
// descendants (where we allow a node to be a descendant of itself).”

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

// https://www.youtube.com/watch?v=_-QHfMDde90&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=28&t=180s
// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    //     void solve(TreeNode* root,vector<TreeNode*>& path,int k,bool& flag) {
    //         path.push_back(root);
    //         if(root->val == k) {
    //             flag=true;
    //             return;
    //         }

    //         if(root->left != NULL) solve(root->left,path,k,flag);
    //         if(flag) return;

    //         if(root->right != NULL) solve(root->right,path,k,flag);
    //         if(flag) return;

    //         path.pop_back();
    //     }

    //     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //         vector<TreeNode*> p1,p2;
    //         bool flag = false;
    //         solve(root,p1,p->val,flag);
    //         flag = false;
    //         solve(root,p2,q->val,flag);

    //         int i=0;

    //         while(true) {
    //             if(i<p1.size() and i< p2.size() and p1[i]->val == p2[i]->val) i++;
    //             else break;
    //         }

    //         return p1[i-1];
    //     }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // base case
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // result
        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        { // both left and right are not null, we found our result
            return root;
        }
    }
};