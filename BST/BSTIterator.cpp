// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

// Input
// ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
// [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
// Output
// [null, 3, 7, true, 9, true, 15, true, 20, false]

// Explanation
// BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
// bSTIterator.next();    // return 3
// bSTIterator.next();    // return 7
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 9
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 15
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 20
// bSTIterator.hasNext(); // return False

// https://www.youtube.com/watch?v=D2jMcmxU4bs&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=51

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
class BSTIterator
{
public:
    stack<TreeNode *> st;
    TreeNode *temp;

    BSTIterator(TreeNode *root)
    {
        while (root->left)
        {
            st.push(root);
            root = root->left;
        }
        st.push(root);
    }

    int next()
    {
        temp = st.top();
        int ans = temp->val;
        st.pop();
        if (!temp->right)
            return ans;

        temp = temp->right;
        while (temp->left)
        {
            st.push(temp);
            temp = temp->left;
        }
        st.push(temp);

        return ans;
    }

    bool hasNext()
    {
        return st.size();
    }

    //     vector<TreeNode*> inorder;
    //     int temp;

    //     BSTIterator(TreeNode* root) {
    //         temp = 0;
    //         stack<TreeNode*> st;
    //         st.push(root);

    //         while(!st.empty()) {
    //             root = st.top();

    //             if(root->left) {
    //                 st.push(root->left);
    //                 root->left = NULL;
    //                 continue;
    //             }
    //             else {
    //                 st.pop();
    //                 inorder.push_back(root);
    //                 if(!root->right) continue;
    //                 st.push(root->right);
    //             }
    //         }
    //     }

    //     int next() {
    //         temp++;
    //         return inorder[temp-1]->val;
    //     }

    //     bool hasNext() {
    //          return temp < inorder.size();
    //     }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */