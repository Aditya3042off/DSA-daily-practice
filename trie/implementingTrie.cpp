// Implement Trie Data Structure to support these operations:
// insert(word) - To insert a string "word" in Trie
// search(word) - To check if string "word" is present in Trie or not.
// startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".

// Three type of queries denote these operations:
// Type 1: To insert a string "word" in Trie.
// 1 word

// Type 2: To check if the string "word" is present in Trie or not.
// 2 word

// Type 3: To check if there is any string in the Trie that starts with the given prefix string "word".
// 3 word

// Input Format :
// The first line contains an Integer 'Q' which denotes the number of queries to be run. Then next 'Q' lines denote each query:

// The first and only line of each query contains the type of query and a string "word" separated by a single space.
// Output Format :
// For each query of Type 2 print the string "true" if string "word" is present in Trie or "false" otherwise.
// For each query of Type 3 print the string "true" if there is any string in the Trie that starts with the given prefix string "word" or "false" otherwise.

// Output for every query will be printed in a separate line.
// Note:
// You are not required to print the output explicitly, it has already been taken care of. Just implement the function.
// Constraints :
// 1 <= Q <= 5*10^4
// 1 <= W <= 10

// Where 'Q' is the number of queries, and 'W' is the length of the "word".
// All input of "word" will consist of only lowercase letters a-z.
// Sample Input 1 :
// 5
// 1 hello
// 1 help
// 2 help
// 3 hel
// 2 hel
// Sample Output 1 :
// true
// true
// false
//  Explanation To Sample Input 1 :
// Query 1: "hello" is inserted
// Query 2: "help" is inserted
// Query 3: "true" is printed as "help" is present
// Query 4: "true" is printed as "hello" and "help" is present having the prefix "hel"
// Query 5: "false" is printed as "hel" is not present
// Sample Input 2 :
// 10
// 1 aaaa
// 1 aaaaaa
// 1 bcd
// 2 aaaaa
// 3 aaaaa
// 3 bc
// 2 bc
// 1 bc
// 3 bcda
// 2 bc
// Sample Output 2 :
// false
// true
// true
// false
// false
// true
//  Explanation To Sample Input 2 :
// Query 1: "aaaa" is inserted
// Query 2: "aaaaaa" is inserted
// Query 3: "bcd" is inserted
// Query 4: "false" is printed as "aaaaa" is not present
// Query 5: "true" is printed as "aaaaaa" is present having the prefix "aaaaa"
// Query 6: "true" is printed as "bcd" is present having the prefix "bc"
// Query 7: "false" is printed as "bc" is not present
// Query 8: "bc" is inserted
// Query 9: "false" is printed as no word is present having the prefix "bcda"
// Query 10: "true" is printed as "bc" is present

// https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=1&ab_channel=takeUforward
// https://www.codingninjas.com/codestudio/problems/implement-trie_631356?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        if (node->isEnd())
        {
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};