// Given the root of a binary tree, return the inorder traversal of its nodes' values

// Input: root = [1,null,2,3]
// Output: [1,3,2]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]

// https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=11

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // iterative inorder traversal

        // generally what happens in recursive solution is we traverse the left subtree
        // then we print the element and then traverse its right subtree

        // but here in iterative we cannot tell if we have traversed the left subtree or not
        //  in order to mimic the recursive behaviour every time when we push a node's left
        //  child in stack we cut it's bond and point the node's left to null
        //  this signifies that we have traversed left tree
        //  so every time when we find a node in stack with left pointing to null
        //  it means that either it doesn't have
        //  left tree or it's left tree has already been traversed
        //  so without any doubt we can print it and go to it's right subtree

        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *temp;
            temp = st.top();

            if (temp->left != NULL)
            {
                st.push(temp->left);
                temp->left = NULL;
            }
            else
            {
                ans.push_back(temp->val);
                st.pop();
                if (temp->right != NULL)
                    st.push(temp->right);
            }
        }
        return ans;
    }
};