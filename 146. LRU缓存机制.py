# 146. LRU缓存机制

# 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

# 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
# 写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

# 进阶:

# 你是否可以在 O(1) 时间复杂度内完成这两种操作？

# 示例:

# LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

# cache.put(1, 1);
# cache.put(2, 2);
# cache.get(1);       // 返回  1
# cache.put(3, 3);    // 该操作会使得密钥 2 作废
# cache.get(2);       // 返回 -1 (未找到)
# cache.put(4, 4);    // 该操作会使得密钥 1 作废
# cache.get(1);       // 返回 -1 (未找到)
# cache.get(3);       // 返回  3
# cache.get(4);       // 返回  4


class ListNode:
    def __init__(self, x, key):
        self.val = x
        self.key = key
        self.next = None
        self.pre = None

class LRUCache:

    def __init__(self, capacity: int):
        self.head = ListNode(0, 'head')
        self.tail = ListNode(0, 'tail')
        self.head.next = self.tail
        self.head.pre = None
        self.tail.next = None
        self.tail.pre = self.head
        self.hash_map = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.hash_map:
            return -1
        self.move_to_head(self.hash_map[key])
        return self.hash_map[key].val

    def put(self, key: int, value: int) -> None:
        if self.get(key) != -1:
            self.hash_map[key].val = value
        else:
            if len(self.hash_map) >= self.capacity:
                delete_node = self.tail.pre
                delete_node.pre.next = self.tail
                self.tail.pre = delete_node.pre
                self.hash_map.pop(delete_node.key)
                delete_node = None
            node = ListNode(value, key)
            self.head.next.pre = node
            node.next = self.head.next
            self.head.next = node
            node.pre = self.head
            self.hash_map[key] = node
                
    def move_to_head(self, node):
        pre = node.pre
        next = node.next
        pre.next = next
        next.pre = pre
        # move to head
        self.head.next.pre = node
        node.next = self.head.next
        self.head.next = node
        node.pre = self.head




# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)