/* Given a binary tree, print nodes of extreme corners of each level but in alternate order.

Example:

For the above tree, the output is

1 2 7 8 31
– print rightmost node of 1st level
– print leftmost node of 2nd level
– print rightmost node of 3rd level
– print leftmost node of 4th level
– print rightmost node of 5th level

Example 1:

Input:
       1
     /  \
    2    3
Output: 1 2
Explanation: This represents a tree
with 3 nodes and 2 edges where root
is 1, left child of 1 is 3 and
right child of 1 is 2.

https://practice.geeksforgeeks.org/problems/extreme-nodes-in-alternate-order/1?page=2&difficulty[]=1&difficulty[]=2&curated[]=6&sortBy=submissions */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*
 A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
    /* Function to print nodes of extreme corners
    of each level in alternate order */
    vector<int> ExtremeNodes(Node *root)
    {
        // Your code here
        vector<int> ans;

        deque<Node *> dq;
        dq.push_back(root);
        int level = 1;
        while (!dq.empty())
        {
            if (level % 2 != 0)
                ans.push_back((dq.back())->data);
            else
                ans.push_back((dq.front())->data);

            int size = dq.size();
            for (int i = 0; i < size; i++)
            {
                Node *node = dq.front();
                dq.pop_front();

                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }

            level++;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution obj;
        vector<int> nodes = obj.ExtremeNodes(root);
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends