// Given a Binary Tree A containing N nodes.

// You need to find the path from Root to a given node B.

// NOTE:

// No two nodes in the tree have same data values.
// You can assume that B is present in the tree A and a path always exists.

// https://www.youtube.com/watch?v=fmflMqVOC7k&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=27
// https://www.interviewbit.com/problems/path-to-given-node/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findPath(TreeNode *node, int b, vector<int> &ans, bool &flag)
{
    ans.push_back(node->val);
    if (node->val == b)
    {
        flag = true;
        return;
    }

    if (node->left != NULL)
        findPath(node->left, b, ans, flag);
    if (flag)
        return;
    if (node->right != NULL)
        findPath(node->right, b, ans, flag);
    if (flag)
        return;
    ans.pop_back();
    return;
}

vector<int> solve(TreeNode *A, int B)
{
    bool flag = false;
    vector<int> ans;
    if (A == NULL)
        return ans;
    findPath(A, B, ans, flag);
    return ans;
}