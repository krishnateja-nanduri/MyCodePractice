//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem

/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    if(head == NULL) return;
    struct Node * temp = head, * curr = head;
    if(temp!=NULL) head = temp->next;
    else return ;
    ReversePrint(head);
    cout<<curr->data<<endl;
}

