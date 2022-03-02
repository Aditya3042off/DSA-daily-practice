// You are given a BST (Binary search tree) with’ N’ number of nodes and a value ‘X’. Your task is to find the greatest value node of the BST which is smaller than or equal to ‘X’.
// Note :‘X’ is not smaller than the smallest node of BST .

// https://www.youtube.com/watch?v=xm_W1ub-K-w&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=43

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> *root, int x)
{
    // Write your code here.
    int ans = -1;
    while (root != NULL)
    {
        if (root->val == x)
            return x;

        if (x > root->val)
        {
            ans = root->val;
            root = root->right;
        }
        else
            root = root->left;
    }
    return ans;
}