// https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {

    ListNode *prevHead=A, *prevHead2=A, *head = A, *pre=NULL, *curr =A, *after;
    int m_init = m;
    n = n-m +1;
    m = m-1;
    
    while(m--){
        prevHead2 = prevHead;
        prevHead= prevHead->next;
        curr= curr->next;
    }
    
    while(curr && n--){
        after = curr ->next;
        curr->next = pre;
        head = curr;
        pre = curr;
        curr = after;
    }

    if(m_init!=1)
        prevHead2->next = pre;

    prevHead->next = after;
    
    if(m_init!=1)
        return A;
    
    return head;
    
}
