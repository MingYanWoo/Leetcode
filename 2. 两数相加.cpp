// 2. 两数相加
// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 示例：

// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *hair = new ListNode(0);
        ListNode *p = hair;
        bool carry = false;
        while(l1 || l2) {
            int carryNum = carry ? 1 : 0;
            int l1v = 0, l2v = 0;
            if(l1) {
                l1v = l1->val;
                l1 = l1->next;
            }
            if(l2) {
                l2v = l2->val;
                l2 = l2->next;
            }
            int num = l1v + l2v + carryNum;
            carry = num >= 10 ? true : false;
            num = num % 10;
            ListNode *node = new ListNode(num);
            p->next = node;
            p = p->next;
        }
        if(carry) {
            ListNode *node = new ListNode(1);
            p->next = node;
        }
        return hair->next;
    }
};