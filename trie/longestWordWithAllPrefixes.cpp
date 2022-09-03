// https://www.youtube.com/watch?v=thsleiL6zxg

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *getNode(char ch)
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
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    bool insertWord(string word)
    {
        Node *temp = root;
        bool containsAllPrefixes = true; // this tells us if all prefixes of current word are present in trie or not
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->containsKey(word[i]))
            {
                if (i != word.size() - 1)
                    containsAllPrefixes = false;
                temp->put(word[i], new Node());
            }
            temp = temp->getNode(word[i]);
            if (temp->isEnd() == false and i != word.size() - 1)
                containsAllPrefixes = false;
        }
        temp->setEnd();
        return containsAllPrefixes;
    }
};

int main()
{
    int n = 7;
    string wordsList[n] = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    Trie trie = Trie();

    sort(wordsList, wordsList + n);
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (!trie.insertWord(wordsList[i]))
            continue;
        if (ans.size() < wordsList[i].size())
            ans = wordsList[i];
    }

    cout << "ANSWER: " << ans;
}