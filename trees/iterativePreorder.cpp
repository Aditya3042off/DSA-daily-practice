// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Input: root = [1,null,2,3]
// Output: [1,2,3]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]

// https://www.youtube.com/watch?v=Bfqd8BsPVuw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=10

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *temp = st.top();
            ans.push_back(temp->val);
            st.pop();
            if (temp->right != NULL)
                st.push(temp->right);
            if (temp->left != NULL)
                st.push(temp->left);
        }

        return ans;
    }
};