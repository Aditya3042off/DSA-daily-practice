// Given the root of a binary tree, return the postorder traversal of its nodes' values.
// Input: root = [1,null,2,3]
// Output: [3,2,1]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]

// https://www.youtube.com/watch?v=2YBhNLodD8Q&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=12

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
    vector<int> postorderTraversal(TreeNode *root)
    {

        // unlike recursive in iterative we cannot tell if a node's left and right subtree
        //  has been traversed or not
        //  to mimic the behaviour of recursion we cutoff the link btw
        //  a node and it's left or right subtree when ever we add the left or right
        //  subtree in stack
        //  so ever time when we check a node in stack we can easily tell if it's left
        //  and right traversal has been done or not by checking it's left and right
        //  pointer.

        // left recursive || right recursive call in recursion approach in recursion
        // is similar to adding left || right child pointer of a node to stack and then
        // cutting the link btw node and added left || right child

        // so whenever we revisit a node in stack we can say if it's left or right recursion is
        //  completed or not
        //  when we first visit node if it has left child we add it to stack
        //  and cutoff link btw them
        //  if left pointer is null that means left traversal done
        //  so now we add right child to stack and cutoff link btw them
        //  if both left and right pointers are null that means both left and right
        //  traversals are done so now we just print the val and pop the node from stack

        // iterative
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode *> st;
        st.push(root);
        TreeNode *temp;

        while (!st.empty())
        {
            temp = st.top();

            if (temp->left != NULL)
            {
                st.push(temp->left);
                temp->left = NULL;
            }
            else if (temp->right != NULL)
            {
                st.push(temp->right);
                temp->right = NULL;
            }
            else
            {
                ans.push_back(temp->val);
                st.pop();
            }
        }
        return ans;
    }
};