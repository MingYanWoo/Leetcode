// 23. 合并K个排序链表
// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

// 示例:

// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return merge(lists, 0, lists.size()-1);
    }

    ListNode* merge(vector<ListNode*>& lists, int low, int high) {
        if(low == high) 
            return lists[low];

        int mid = low + (high - low) / 2;
        ListNode *l1 = merge(lists, low, mid);
        ListNode *l2 = merge(lists, mid+1, high);
        return merge2Lists(l1, l2);
    }

    ListNode* merge2Lists(ListNode* p1, ListNode* p2) {
        ListNode *head = new ListNode(0);
        ListNode *hair = head;
        while(p1 && p2) {
            if(p1->val < p2->val) {
                hair->next = p1;
                p1 = p1->next;
            }else {
                hair->next = p2;
                p2 = p2->next;
            }
            hair = hair->next;
        }
        if(p1) hair->next = p1;
        if(p2) hair->next = p2;
        return head->next;
    }
};