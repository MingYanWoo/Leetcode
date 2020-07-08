# OR157.LRU Cache

# 题目描述

# 	设计一个数据结构，实现LRU Cache的功能(Least Recently Used – 最近最少使用缓存)。它支持如下2个操作： get 和 put。

# int get(int key) – 如果key已存在，则返回key对应的值value（始终大于0）；如果key不存在，则返回-1。
# void put(int key, int value) – 如果key不存在，将value插入；如果key已存在，则使用value替换原先已经存在的值。如果容量达到了限制，LRU Cache需要在插入新元素之前，将最近最少使用的元素删除。

# 请特别注意“使用”的定义：新插入或获取key视为被使用一次；而将已经存在的值替换更新，不算被使用。

# 限制：请在O(1)的时间复杂度内完成上述2个操作。

# 输入描述:
# 第一行读入一个整数n，表示LRU Cache的容量限制。 从第二行开始一直到文件末尾，每1行代表1个操作。

# 如果每行的第1个字符是p，则该字符后面会跟随2个整数，表示put操作的key和value。

# 如果每行的第1个字符是g，则该字符后面会跟随1个整数，表示get操作的key。
# 输出描述:
# 按照输入中get操作出现的顺序，按行输出get操作的返回结果。
# 示例1
# 输入

# 复制
# 2
# p 1 1
# p 2 2
# g 1
# p 2 102
# p 3 3
# g 1
# g 2
# g 3
# 输出

# 复制
# 1
# 1
# -1
# 3
# 说明

# 2        //Cache容量为2
# p 1 1    //put(1, 1)
# p 2 2    //put(2, 2)
# g 1      //get(1), 返回1
# p 2 102  //put(2, 102)，更新已存在的key，不算被使用
# p 3 3    //put(3, 3)，容量超过限制，将最近最少使用的key=2清除
# g 1      //get(1), 返回1
# g 2      //get(2), 返回-1
# g 3      //get(3), 返回3



class ListNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        self.pre = None

class LRU_Cache:
    def __init__(self, cap):
        self.cap = cap
        self.head = ListNode(None, None)
        self.tail = ListNode(None, None)
        self.head.next = self.tail
        self.tail.pre = self.head
        self.hashMap = {}
        
    def put(self, key, value):
        if key in self.hashMap:
            self.hashMap[key].value = value
            # self.move_to_head(key)
        else:
            if self.cap == 0:
                return
            if len(self.hashMap) >= self.cap:
                # delete last
                tailPre = self.tail.pre
                tailPrePre = tailPre.pre
                tailPrePre.next = self.tail
                self.tail.pre = tailPrePre
                self.hashMap.pop(tailPre.key)
                
            newNode = ListNode(key, value)
            self.hashMap[key] = newNode
            self.insert_to_head(key)
            

    def get(self, key):
        if key in self.hashMap:
            self.move_to_head(key)
            return self.hashMap[key].value
        else:
            return -1
    
    def move_to_head(self, key):
        node = self.hashMap[key]
        preNode = node.pre
        nextNode = node.next
        preNode.next = nextNode
        nextNode.pre = preNode
        self.insert_to_head(key)
        
    def insert_to_head(self, key):
        node = self.hashMap[key]
        headNext = self.head.next
        self.head.next = node
        node.pre = self.head
        node.next = headNext
        headNext.pre = node

if __name__ == '__main__':
    n = int(input())
    lru = LRU_Cache(n)
    while True:
        try:
            row = input().split(' ')
            op = row[0]
            #print(lru.hashMap)
            if op == 'p':
                lru.put(int(row[1]), int(row[2]))
            else:
                print(lru.get(int(row[1])))
        except:
            break