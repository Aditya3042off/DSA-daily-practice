// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false

// https://www.youtube.com/watch?v=ssL3sHwPeb4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=52

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
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         if(root == NULL) return false;
//         bool flag = false;
//         unordered_map<int,int> mp;
//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty()) {
//             root = q.front();
//             q.pop();

//             if(mp.find(root->val) != mp.end()) {
//                 flag = true;
//                 break;
//             }
//             mp[k-root->val] = 1;
//             if(root->left) q.push(root->left);
//             if(root->right) q.push(root->right);
//         }
//         return flag;
//     }
// };

class BSTIterator
{
    stack<TreeNode *> myStack;
    bool reverse = true;

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if (!reverse)
            pushAll(tmpNode->right);
        else
            pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        for (; node != NULL;)
        {
            myStack.push(node);
            if (reverse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};