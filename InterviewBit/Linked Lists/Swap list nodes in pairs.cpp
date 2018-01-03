//https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* head) {

        ListNode *dummy = new ListNode(-1), *pre = dummy;
         dummy->next = head;
         while (pre->next && pre->next->next)
         {
             ListNode *t = pre->next->next;
             pre->next->next = t->next;
             t->next = pre->next;
             pre->next = t;
             pre = t->next;
         }
         return dummy->next;
 }
