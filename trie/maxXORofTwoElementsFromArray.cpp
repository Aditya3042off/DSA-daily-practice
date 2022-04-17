// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

// Example 1:

// Input: nums = [3,10,5,25,2,8]
// Output: 28
// Explanation: The maximum result is 5 XOR 25 = 28.
// Example 2:

// Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// Output: 127

// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

struct Node
{
    Node *links[2];

    bool containsKey(int ind)
    {
        return (links[ind] != NULL);
    }
    Node *get(int ind)
    {
        return links[ind];
    }
    void put(int ind, Node *node)
    {
        links[ind] = node;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

public:
    void insert(int num)
    {
        Node *node = root;
        // cout << num << endl;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

public:
    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &arr1)
    {
        Trie trie;
        int n = arr1.size();
        for (int i = 0; i < n; i++)
        {
            trie.insert(arr1[i]);
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, trie.findMax(arr1[i]));
        }
        return maxi;
    }
};