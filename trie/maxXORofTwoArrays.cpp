// Problem Statement
// You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’. Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation.
// Input Format:
// The first line of the input contains an integer, 'T,’ denoting the number of test cases.

// The first line of each test case contains two space-separated integers, 'N' and ‘M’ denoting the number of elements in the first and second array.

// The second line of each test case contains 'N' space-separated integers denoting the elements of the array first array.

// The last line of each test case contains 'M' space-separated integers denoting the elements of the array second array.
// Output Format:
// For each test case, print a single integer - the maximum possible xor among all possible pairs.

// Print the output of each test case in a separate line.
// Note :
// You do not need to input or print anything, and it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <=  T  <= 5
// 1 <=  N, M <= 1000
// 0 <=  arr1[i], arr2[i]  <= 10 ^ 9

// Where 'T' denotes the number of test cases, 'N', ‘M’ denotes the number of elements in the first array and second array, ‘arr1[i]', and ‘arr2[i]’ denotes the 'i-th' element of the first array and second array.

// Time limit: 1 sec
// Sample Input 1:
// 1
// 7 7
// 6 6 0 6 8 5 6
// 1 7 1 7 8 0 2
// Sample Output 1:
// 15
// Explanation of sample input 1:
// First testcase:
// Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15
// Sample Input 2:
// 1
// 3 3
// 25 10 2
// 8 5 3
// Sample Output 2:
// 28
// Explanation of sample input 2:
// First test case:
// 28 is the maximum possible xor given by pair = (25, 5). It is the maximum possible xor among all possible pairs.

// https://www.codingninjas.com/codestudio/problems/maximum-xor_973113?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
// https://www.youtube.com/watch?v=EIhAwfHubE8&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=6&ab_channel=takeUforward

#include <bits/stdc++.h>

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
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        trie.insert(arr1[i]);
    }
    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, trie.findMax(arr2[i]));
    }
    return maxi;
}