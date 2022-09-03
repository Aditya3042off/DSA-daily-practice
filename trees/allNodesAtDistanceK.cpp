// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// https://www.youtube.com/watch?v=i9ORlEy6EsI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=31

// Given the root of a binary tree, the value of a target node target, and an integer k,
// return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
// Example 2:

// Input: root = [1], target = 1, k = 3
// Output: []

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void assignParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentMap)
    {
        TreeNode *node = root;
        parentMap[root] = NULL;

        queue<TreeNode *> q;
        q.push(node);

        while (!q.empty())
        {
            node = q.front();
            q.pop();

            if (node->left != NULL)
            {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
        return;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        TreeNode *node;
        unordered_map<TreeNode *, TreeNode *> parentMap;
        queue<TreeNode *> q;
        unordered_set<TreeNode *> visited;

        assignParent(root, parentMap);

        int currdist = 0;

        q.push(target);
        visited.insert(target);

        while (!q.empty() and currdist < k)
        {
            int size = q.size();

            for (int i = 1; i <= size; i++)
            {
                node = q.front();
                q.pop();

                if (node->left != NULL and visited.find(node->left) == visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right != NULL and visited.find(node->right) == visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parentMap[node] != NULL and visited.find(parentMap[node]) == visited.end())
                {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }

            currdist++;
        }
        if (currdist < k)
            return {};

        vector<int> ans;

        while (!q.empty())
        {
            ans.push_back((q.front())->val);
            q.pop();
        }
        return ans;
    }
};