// You have been given a Binary Tree of 'N' nodes, where the nodes have integer values.
// Your task is to find the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.

// https://www.youtube.com/watch?v=ySp2epYvgTE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=14&t=540s

#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

#include <bits/stdc++.h>

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    if (root == NULL)
        return {inorder, preorder, postorder};
    stack<pair<BinaryTreeNode<int> *, int>> st;
    pair<BinaryTreeNode<int> *, int> temp(root, 0);
    st.push(temp);

    while (!st.empty())
    {
        pair<BinaryTreeNode<int> *, int> temp2;
        temp = st.top();
        if (temp.first == NULL)
        {
            st.pop();
            continue;
        }

        if (temp.second == 0)
        {
            preorder.push_back((temp.first)->data);
            temp.second++;
            temp2.first = (temp.first)->left;
            temp2.second = 0;
            st.push(temp2);
        }
        else if (temp.second == 1)
        {
            inorder.push_back((temp.first)->data);
            temp.second++;
            temp2.first = (temp.first)->right;
            temp2.second = 0;
            st.push(temp2);
        }
        else
        {
            postorder.push_back((temp.first)->data);
            st.pop();
        }
    }
    return {inorder, preorder, postorder};
}