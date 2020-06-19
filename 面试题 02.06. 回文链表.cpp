// 面试题 02.06. 回文链表
// 编写一个函数，检查输入的链表是否是回文的。

 

// 示例 1：

// 输入： 1->2
// 输出： false 
// 示例 2：

// 输入： 1->2->2->1
// 输出： true 
 

// 进阶：
// 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        int count = 0;
        ListNode *p = head;
        while(p) {
            p = p->next;
            count++;
        }

        int n = count / 2;
        for(int i = 1; i <= n; i++) {
                s.push(head->val);
                head = head->next;
        }
        if((count % 2) != 0) {
            head = head->next;
        }
        for(int i = 1; i <= n; i++) {
            if(head->val != s.top()) return false;
            s.pop();
            head = head->next;
        }
        return true;
    }
};