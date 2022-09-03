// https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=30

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }
};

void solve(Node *node)
{
    if (node == NULL)
        return;

    int childSum = 0;
    if (node->left)
        childSum += node->left->val;
    if (node->right)
        childSum += node->right->val;

    if (childSum <= node->val)
    {
        if (node->left)
            node->left->val = childSum;
        if (node->right)
            node->right->val = childSum;
    }

    solve(node->left);
    solve(node->right);

    int newVal = 0;

    if (node->left)
        newVal += node->left->val;
    if (node->right)
        newVal += node->right->val;

    if (node->left or node->right)
        node->val = newVal;
}

int main()
{
}