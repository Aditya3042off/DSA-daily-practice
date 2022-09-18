// You are given an array words of size n consisting of non-empty strings.

// We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].

// For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
// Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

// Note that a string is considered as a prefix of itself.

// Example 1:

// Input: words = ["abc","ab","bc","b"]
// Output: [5,4,3,2]
// Explanation: The answer for each string is the following:
// - "abc" has 3 prefixes: "a", "ab", and "abc".
// - There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
// The total is answer[0] = 2 + 2 + 1 = 5.
// - "ab" has 2 prefixes: "a" and "ab".
// - There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
// The total is answer[1] = 2 + 2 = 4.
// - "bc" has 2 prefixes: "b" and "bc".
// - There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
// The total is answer[2] = 2 + 1 = 3.
// - "b" has 1 prefix: "b".
// - There are 2 strings with the prefix "b".
// The total is answer[3] = 2.
// Example 2:

// Input: words = ["abcd"]
// Output: [4]
// Explanation:
// "abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
// Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.

struct Node
{
    Node *links[26];
    int countstart;

    Node()
    {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
        countstart = 0;
    }

    bool containsKey(int key)
    {
        return links[key] != NULL;
    }

    Node *getNext(int key)
    {
        return links[key];
    }

    void put(int key, Node *node)
    {
        links[key] = node;
    }

    void incCountStart()
    {
        countstart++;
    }

    int getCountStart()
    {
        return countstart;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string s)
    {
        Node *node = root;

        for (char c : s)
        {
            if (node->containsKey(c - 'a') == false)
                node->put(c - 'a', new Node());
            node = node->getNext(c - 'a');
            node->incCountStart();
        }
    }

    int countStartPrefixes(string s)
    {
        Node *node = root;
        int count = 0;
        for (char c : s)
        {
            node = node->getNext(c - 'a');
            count += node->getCountStart();
        }
        return count;
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        int n = words.size();

        Trie trie = Trie();

        vector<int> ans;

        for (auto word : words)
            trie.insert(word);

        for (auto word : words)
            ans.push_back(trie.countStartPrefixes(word));

        return ans;
    }
};