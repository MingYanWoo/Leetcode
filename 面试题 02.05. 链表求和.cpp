// 面试题 02.05. 链表求和

// 给定两个用链表表示的整数，每个节点包含一个数位。

// 这些数位是反向存放的，也就是个位排在链表首部。

// 编写函数对这两个整数求和，并用链表形式返回结果。

 

// 示例：

// 输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
// 输出：2 -> 1 -> 9，即912
// 进阶：假设这些数位是正向存放的，请再做一遍。

// 示例：

// 输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
// 输出：9 -> 1 -> 2，即912




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
        bool flag = false;
        while(l1 && l2) {
            int sum = l1->val + l2->val;
            if(flag) sum++;
            if(sum > 9) {
                sum %= 10;
                flag = true;
            }else {
                flag = false;
            }
            ListNode *newNode = new ListNode(sum);
            p->next = newNode;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1 = l1 ? l1 : l2;
        while(l1 && flag) {
            int sum = l1->val + 1;
            if(sum > 9) {
                sum %= 10;
                flag = true;
            }else {
                flag = false;
            }
            ListNode *newNode = new ListNode(sum);
            p->next = newNode;
            p = p->next;
            l1 = l1->next;
        }
        if(l1) p->next = l1;
        if(flag) p->next = new ListNode(1);
        return hair->next;
    }
};