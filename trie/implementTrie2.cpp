#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int prefixes;
    int completeStrings;

    Node()
    {
        prefixes = 0;
        completeStrings = 0;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *getNode(char ch)
    {
        return links[ch - 'a'];
    }

    void putNode(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void incPrefix()
    {
        prefixes++;
    }

    void decPrefix()
    {
        prefixes--;
    }

    void removeCompleteString()
    {
        completeStrings--;
    }

    void setCompleteString()
    {
        completeStrings++;
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

    void insertString(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (!temp->containsKey(ch))
            {
                temp->putNode(ch, new Node());
            }
            temp = temp->getNode(ch);
            temp->incPrefix();
        }
        temp->setCompleteString();
    }

    bool searchWord(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (!temp->containsKey(ch))
                return false;
            temp = temp->getNode(ch);
        }
        return temp->completeStrings != 0;
    }

    int countWordsEqualTo(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (!temp->containsKey(ch))
                return 0;
            temp = temp->getNode(ch);
        }
        return temp->completeStrings;
    }

    int countWordsStartingWith(string prefix)
    {
        Node *temp = root;
        for (char ch : prefix)
        {
            if (!temp->containsKey(ch))
                return 0;
            temp = temp->getNode(ch);
        }
        return temp->prefixes;
    }

    void erase(string word)
    {

        // first we check if the word exist in trie or not
        if (searchWord(word) == false)
            return;

        Node *temp = root;
        for (char ch : word)
        {
            temp = temp->getNode(ch);
            temp->decPrefix();
        }
        temp->removeCompleteString();
    }
};

int main()
{
    Trie trie = Trie();
    trie.insertString("walle");
    trie.insertString("wallet");
    trie.insertString("warren");
    trie.insertString("warrant");
    trie.insertString("warranty");
    trie.insertString("waxing");
    trie.insertString("wool");
    trie.insertString("wade");
    trie.insertString("wain");
    trie.insertString("warren");
    trie.insertString("warren");
    trie.insertString("wool");
    trie.insertString("wool");
    trie.insertString("wool");

    cout << trie.countWordsEqualTo("wool") << endl;
    cout << trie.countWordsEqualTo("wain") << endl;
    cout << trie.countWordsEqualTo("warren") << endl;

    cout << trie.countWordsStartingWith("w") << endl;
    cout << trie.countWordsStartingWith("warr") << endl;
    cout << trie.countWordsStartingWith("wal") << endl;

    trie.erase("walle");
    trie.erase("wallet");
    trie.erase("warren");
    trie.erase("warren");

    cout << trie.countWordsEqualTo("warren") << endl;
    cout << trie.countWordsEqualTo("wallet") << endl;
}