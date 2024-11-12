class LRUCache
{
private:
    struct Node
    {
        int key, value;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;

    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(Node *node)
    {
        removeNode(node);
        addNodeToHead(node);
    }

    void removeTail()
    {
        Node *node = tail->prev;
        removeNode(node);
        cache.erase(node->key);
        delete node;
    }

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        Node *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        else
        {
            Node *newNode = new Node(key, value);
            cache[key] = newNode;
            addNodeToHead(newNode);
            if (cache.size() > capacity)
            {
                removeTail();
            }
        }
    }

    ~LRUCache()
    {
        delete head;
        delete tail;
    }
};