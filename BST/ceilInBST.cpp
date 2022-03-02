// Ninja is given a binary search tree and an integer. Now he is given a particular key in the tree and returns its ceil value. Can you help Ninja solve the problem?
// Note:
// Ceil of an integer is the closest integer greater than or equal to a given number.
// For example:
// arr[] = {1, 2, 5, 7, 8, 9}, key = 3.
// The closest integer greater than 3 in the given array is 5. So, its ceil value in the given array is 5.

// https://www.youtube.com/watch?v=KSsk8AhdOZA&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=42

/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ans = -1;
    while (node != NULL)
    {
        if (x < node->data)
        {
            ans = node->data;
            node = node->left;
        }
        else if (x == node->data)
        {
            ans = x;
            break;
        }
        else
            node = node->right;
    }
    return ans;
}