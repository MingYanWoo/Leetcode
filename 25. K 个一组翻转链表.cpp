// 25. K 个一组翻转链表
// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。

// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

// 示例：

// 给你这个链表：1->2->3->4->5

// 当 k = 2 时，应当返回: 2->1->4->3->5

// 当 k = 3 时，应当返回: 3->2->1->4->5

 

// 说明：

// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int counter = 0;
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *pre = hair;

        ListNode *start = head;
        ListNode *end = head;
        while(end->next) {
            while(end->next && counter++<k-1) end = end->next;
            if(counter < k-1) break;
            ListNode *next_start = end->next;
            ListNode *next_end = end->next;
            vector<ListNode*> res = reverse(start, end);
            pre->next = res[0];
            res[1]->next = next_start;
            pre = res[1];
            start = next_start;
            end = next_end;
            if(!end) break;
            counter = 0;
        }
        return hair->next;
    }

    vector<ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode *tmp = NULL;
        ListNode *p = head;
        while(p != tail) {
            ListNode *nextNode = p->next;
            p->next = tmp;
            tmp = p;
            p = nextNode;
        }
        p->next = tmp;
        vector<ListNode*> res{p, head};
        return res;
    } 
};