// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Input: p = [1,2,3], q = [1,2,3]
// Output: true

// Input: p = [1,2], q = [1,null,2]
// Output: false

// Input: p = [1,2,1], q = [1,1,2]
// Output: false

// https://www.youtube.com/watch?v=BhuvF_-PWS0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=19

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL || q == NULL)
        {
            if (p == NULL and q == NULL)
                return true;
            return false;
        }
        bool ans = true;
        queue<TreeNode *> tree1;
        tree1.push(p);
        queue<TreeNode *> tree2;
        tree2.push(q);
        int size1;
        int size2;
        TreeNode *node1;
        TreeNode *node2;
        while (!tree1.empty() || !tree2.empty())
        {

            size1 = tree1.size();
            size2 = tree2.size();
            if (size1 != size2)
            {
                ans = false;
                break;
            }

            for (int i = 0; i < size1; i++)
            {
                node1 = tree1.front();
                node2 = tree2.front();
                tree1.pop();
                tree2.pop();

                if (node1 == NULL and node2 != NULL || node2 == NULL and node1 != NULL)
                {
                    ans = false;
                    break;
                }

                if (node1 == NULL and node2 == NULL)
                    continue;

                if (node1->val != node2->val)
                {
                    ans = false;
                    break;
                }
                tree1.push(node1->left);
                tree1.push(node1->right);

                tree2.push(node2->left);
                tree2.push(node2->right);
            }
        }
        return ans;
    }
};