// 面试题 02.04. 分割链表

// 编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

// 示例:

// 输入: head = 3->5->8->5->10->2->1, x = 5
// 输出: 3->1->2->10->5->5->8



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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *p = head->next;
        ListNode *last = head;
        while(p) {
            if(p->val < x) {
                ListNode *tmp = p->next;
                last->next = tmp;
                p->next = head;
                head = p;
                p = tmp;
            }else {
                p = p->next;
                last = last->next;
            }
        }
        return head;
    }
};