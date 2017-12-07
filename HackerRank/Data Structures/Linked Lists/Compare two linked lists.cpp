//https://www.hackerrank.com/challenges/compare-two-linked-lists/problem

/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if (headA== NULL && headB == NULL)
  {  return 1;  }
  if (headA == NULL && headB != NULL)
  {  return 0;  }
  if (headA != NULL && headB == NULL)
  {  return 0;  }
  if (headA->data != headB->data)
  {  return 0;  }

  /* If we reach here, then a and b are not NULL and their
       data is same, so move to next nodes in both lists */
  return CompareLists(headA->next, headB->next);
}

