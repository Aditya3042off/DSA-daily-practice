// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom

// https://www.youtube.com/watch?v=0FtVY6I4pB8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=24
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        map<int, int> mp;
        queue<pair<int, Node *>> q;
        q.push({0, root});

        while (!q.empty())
        {
            int col = q.front().first;
            root = q.front().second;
            q.pop();
            mp[col] = root->data;

            if (root->left != NULL)
                q.push({col - 1, root->left});
            if (root->right != NULL)
                q.push({col + 1, root->right});
        }
        vector<int> ans;
        for (auto itr : mp)
            ans.push_back(itr.second);
        return ans;
    }
};