// Given below is a binary tree. The task is to print the top view of binary tree.
// Top view of a binary tree is the set of nodes visible when the tree is viewed from the top

// https://www.youtube.com/watch?v=Et9OCDNvJ78&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=23
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
// https://leetcode.com/discuss/general-discussion/1094690/views-and-traversal-of-binary-tree-important-topics-must-read

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here
        map<int, int> mp;
        queue<pair<int, Node *>> q;

        q.push({0, root});

        while (!q.empty())
        {
            int col = q.front().first;
            root = q.front().second;
            q.pop();

            if (mp.find(col) == mp.end())
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