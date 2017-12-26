//https://www.interviewbit.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* curr = A;
    ListNode* head = A;
    ListNode* last;
    
    int sizeOv = 0;
    
    if(B == 0 || A == NULL){
        return A;
    }
    
    while(curr != NULL){
        last = curr;
        curr = curr->next;
        sizeOv++;
    }
    
    while(B >= sizeOv){
        B = B - sizeOv;
    }
    
    B = sizeOv - B;
    
    last->next = head;
    // now, its a circular list
    
    curr = A;
    
    while(B != 0){
        last = curr;
        curr = curr->next;
        B--;
    }
    
    head = curr;
    last->next = NULL;
    
    return head;
}

