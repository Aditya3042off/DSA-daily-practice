// https://practice.geeksforgeeks.org/problems/burning-tree/1
// https://www.youtube.com/watch?v=2r5wLmQfD6g&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=32

// Given a binary tree and a node called target. Find the minimum time required
// to burn the complete binary tree if the target is set on fire. It is known that in
// 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

// Example 1:

// Input:
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10
// Target Node = 8
// Output: 7
// Explanation: If leaf with the value
// 8 is set on fire.
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree.
// Example 2:

// Input:
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      7
//   /    /
//  8    10
// Target Node = 10
// Output: 5

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));

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

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    Node *findTarget(Node *node, int target)
    {
        if (node == NULL)
            return NULL;

        if (node->data == target)
            return node;

        Node *left = findTarget(node->left, target);
        if (left != NULL)
            return left;
        Node *right = findTarget(node->right, target);
        if (right != NULL)
            return right;

        return NULL;
    }

    void assignParent(Node *root, unordered_map<Node *, Node *> &parentMap)
    {
        Node *node = root;
        parentMap[root] = NULL;

        queue<Node *> q;
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

    int minTime(Node *root, int target)
    {
        // Your code goes here
        Node *start = findTarget(root, target);

        unordered_map<Node *, Node *> parentMap;
        assignParent(root, parentMap);

        // in the queue the nodes newely burned at every time index are stored
        // eg: newely burned node at time 0 is our stating node
        queue<Node *> q;
        unordered_set<Node *> visited;

        q.push(start);
        visited.insert(start);

        int currTime = 0;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Node *node = q.front();
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
            currTime++;
        }
        return --currTime;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}

// } Driver Code Ends