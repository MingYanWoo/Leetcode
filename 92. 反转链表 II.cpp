92. 反转链表 II

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *suss = NULL;
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == 1) {
            return reverse(head, n);
        }
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }

    ListNode* reverse(ListNode* head, int n) {
        if(n == 1) {
            suss = head->next;
            return head;
        }
        ListNode *last = reverse(head->next, n - 1);
        head->next->next = head;
        head->next = suss;
        return last;
    }
};