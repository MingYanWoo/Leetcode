// 143. 重排链表

// 反馈
// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 示例 1:

// 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
// 示例 2:

// 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *quick = hair;
        ListNode *slow = hair;

        while(quick && quick->next) {
            quick = quick->next->next;
            slow = slow->next;
        }

        ListNode *l1 = head;
        ListNode *l2 = slow->next;
        slow->next = NULL;

        //reverse
        ListNode *pre = NULL;
        while(l2) {
            ListNode *nextNode = l2->next;
            l2->next = pre;
            pre = l2;
            l2 = nextNode;
        }
        l2 = pre;

        ListNode *p = hair;
        while(l1 && l2) {
            ListNode *l1n = l1;
            ListNode *l2n = l2;
            l1 = l1->next;
            l2 = l2->next;
            p->next = l1n;
            p->next->next = l2n;
            p = p->next->next;
        }
        if(l1) p->next = l1;
        if(l2) p->next = l2;
        
        head = hair->next;
        return;
    }
};