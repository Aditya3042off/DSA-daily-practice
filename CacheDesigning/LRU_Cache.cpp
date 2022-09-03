// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// https://www.youtube.com/watch?v=xDEuM5qa0zg
// https://leetcode.com/problems/lru-cache/

struct Node
{
    int key, value;
    Node *prev, *next;

    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
public:
    int maxCapacity, currCapacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> hashMap;

    LRUCache(int _capacity)
    {
        maxCapacity = _capacity;
        currCapacity = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = head->prev = tail;
        tail->prev = tail->next = head;
    }

    Node *addNode(int key, int value)
    {

        Node *node = new Node(key, value);

        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;

        return node;
    }

    void deleteNode(Node *node)
    {
        Node *temp = node->next;
        node->prev->next = temp;
        temp->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        delete node;
    }

    int get(int key)
    {
        if (hashMap[key] == NULL)
            return -1;

        int val = hashMap[key]->value;

        deleteNode(hashMap[key]);
        hashMap[key] = addNode(key, val);

        return val;
    }

    void put(int key, int value)
    {
        if (hashMap[key] != NULL)
        {
            deleteNode(hashMap[key]);
            hashMap[key] = NULL;
        }
        else if (currCapacity == maxCapacity)
        {
            int keyToRemove = tail->prev->key;
            deleteNode(tail->prev);
            hashMap[keyToRemove] = NULL;
        }
        else
            currCapacity++;

        hashMap[key] = addNode(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */