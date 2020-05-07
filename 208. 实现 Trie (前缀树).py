# 208. 实现 Trie (前缀树)

# 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

# 示例:

# Trie trie = new Trie();

# trie.insert("apple");
# trie.search("apple");   // 返回 true
# trie.search("app");     // 返回 false
# trie.startsWith("app"); // 返回 true
# trie.insert("app");   
# trie.search("app");     // 返回 true
# 说明:

# 你可以假设所有的输入都是由小写字母 a-z 构成的。
# 保证所有输入均为非空字符串。


class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tree = {}


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        temp = self.tree
        for s in word:
            if s not in temp:
                temp[s] = {}
            temp = temp[s]
        temp['end'] = 0


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        temp = self.tree
        for s in word:
            if s not in temp:
                return False
            temp = temp[s]
        return 'end' in temp


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        temp = self.tree
        for s in prefix:
            if s not in temp:
                return False
            temp = temp[s]
        return True



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)