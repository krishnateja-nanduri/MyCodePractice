//https://www.hackerrank.com/challenges/reverse-a-linked-list/problem

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
if(head==NULL)
        return head;
    if(head->next==NULL)
    {
        return head;
    }

    struct Node* tmp= (Reverse(head->next));
    struct Node* headtmp=tmp;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=head;
    head->next=NULL;
    return headtmp;
}

