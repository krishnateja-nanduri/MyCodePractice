//https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *l1, Node* l2)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->data < l2->data) {
            l1->next = MergeLists(l1->next, l2);
            return l1;
        } else {
            l2->next = MergeLists(l2->next, l1);
            return l2;
        }
}

