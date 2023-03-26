// https://practice.geeksforgeeks.org/problems/lru-cache/1
// https://www.youtube.com/watch?v=xDEuM5qa0zg
// Approach: store node as {key, val, prev, next} DLL and also in map
// DLL head and tail is initialised
// add node to head->next, remove node from tail->prev (update map)

class LRUCache
{
private:
    struct Node
    {
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    Node *head = new Node(0, 0);
    Node *tail = new Node(0, 0);

    unordered_map<int, Node *> mp;
    int capacity;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *existingNode = mp[key];
            int value = existingNode->value;
            deleteNode(existingNode);
            insertAtFront(key, value);
            mp.erase(key);
            mp[key] = head->next;
            return value;
        }
        else
        {
            return -1;
        }
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }

        if (mp.size() == capacity)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        insertAtFront(key, value);
        mp[key] = head->next;
    }

    void insertAtFront(int key, int value)
    {
        Node *newNode = new Node(key, value);
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }

    void deleteNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
};