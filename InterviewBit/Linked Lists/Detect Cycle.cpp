// https://www.interviewbit.com/problems/list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    
    if(A==NULL || A->next==NULL ){
        return A;
    }
    
    ListNode *sl =A, *fst=A, *tmp=A;

    while(sl && fst){
        sl=sl->next;
        
        if(fst && fst->next){
            fst = fst->next->next;
        }
        
        else
            return NULL;
        
        if(sl==fst){
            break;
        }
    }
    
    while(sl && tmp!=sl){
        tmp=tmp->next;
        sl=sl->next;
    }
        
    return sl;
}
