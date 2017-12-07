//https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem

/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
     Node * temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            Node * t=temp->next;
            temp->next=t->next;
            delete(t);
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
}

