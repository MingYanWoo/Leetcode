// 面试题 16.25. LRU缓存

// 设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指定最大容量。当缓存被填满时，它应该删除最近最少使用的项目。

// 它应该支持以下操作： 获取数据 get 和 写入数据 put 。

// 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
// 写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

// 示例:

// LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // 返回  1
// cache.put(3, 3);    // 该操作会使得密钥 2 作废
// cache.get(2);       // 返回 -1 (未找到)
// cache.put(4, 4);    // 该操作会使得密钥 1 作废
// cache.get(1);       // 返回 -1 (未找到)
// cache.get(3);       // 返回  3
// cache.get(4);       // 返回  4



struct DListNode {
    DListNode *next;
    DListNode *pre;
    int key, val;
    DListNode(int key, int val, DListNode* next, DListNode* pre): key(key), val(val), next(next), pre(pre) {}
};

class LRUCache {
    DListNode *head = new DListNode(-1, -1, nullptr, nullptr);
    DListNode *tail = new DListNode(-1, -1, nullptr, nullptr);
    int cap, size;
    unordered_map<int, DListNode*> mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        DListNode *node = mp[key];
        addToHead(node, false);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()) {
            if(size >= cap) deleteLast();
            DListNode *node = new DListNode(key, value, nullptr, nullptr);
            mp[key] = node;
            addToHead(node, true);
            size++;
            return;
        }
        DListNode *node = mp[key];
        node->val = value;
        addToHead(node, false);
    }

    void addToHead(DListNode* node, bool isNew) {
        // 断开
        if(!isNew) {
            DListNode *preNode = node->pre;
            DListNode *nextNode = node->next;
            preNode->next = nextNode;
            nextNode->pre = preNode;
        }
        // 插入head处
        node->next = head->next;
        node->next->pre = node;
        head->next = node;
        node->pre = head;
    }

    void deleteLast() {
        int key = tail->pre->key;
        DListNode *last = mp[key];
        last->pre->next = tail;
        tail->pre = last->pre;
        mp.erase(key);
        delete last;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */