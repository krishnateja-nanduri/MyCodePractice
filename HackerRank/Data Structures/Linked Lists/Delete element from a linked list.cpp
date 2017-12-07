//https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem

/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    Node *prev = NULL;
    Node *ptr = head;
    
    int pos = 0;
    
    if(position==0)
    {
        head=head->next;
        delete (ptr);
    }
    else
    {
        while(position!=pos)
        {
            ++pos;
            prev=ptr;
            ptr=ptr->next;
        }
        
        if(ptr!=NULL)
        {
            prev->next=ptr->next;
            delete (ptr);
        }
    }
    return head;
}

